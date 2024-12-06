//
// Created by csimo on 24. 10. 21.
//
#include "JsonSaver.h"
#include "trafficFlow.h"
#include "csvLoader.h"
#include "sortAlgorithm/quickSort.h"
#include "sortAlgorithm/mergeSort.h"
#include "sortAlgorithm/heapSort.h"
#include "sortAlgorithm/greedySort.h"
#include <iomanip>
#include <sys/resource.h>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <new>

size_t totalAllocatedMemory = 0; // 전체 메모리 할당량 추적

void* operator new(size_t size) {
    totalAllocatedMemory += size;
    return malloc(size);
}

void operator delete(void* ptr) noexcept {
    free(ptr);
}

void operator delete(void* ptr, size_t size) noexcept {
    totalAllocatedMemory -= size;
    free(ptr);
}

// 시간 및 메모리 사용량 저장용
struct AlgorithmStats {
    double timeInSeconds;    // 실행 시간 (초)
    long memoryUsageInKB;    // 메모리 사용량 (KB)
};


std::map<std::string, AlgorithmStats> statsMap;

long getMemoryUsageFromProc() {
    std::ifstream statusFile("/proc/self/status");
    if (!statusFile.is_open()) {
        std::cerr << "[Error] Failed to open /proc/self/status\n";
        return -1;
    }

    std::string line;
    while (std::getline(statusFile, line)) {
        if (line.find("VmRSS:") != std::string::npos) {
            std::istringstream iss(line);
            std::string key;
            long value;
            std::string unit;
            iss >> key >> value >> unit;
            return value; // KB 단위
        }
    }
    return -1; // 메모리 사용량을 찾지 못한 경우
}


void measureMemoryDuringSort(const std::string& algorithmName, std::function<void()> sortFunction, bool useProcessMemory) {
    long memoryBefore = (useProcessMemory) ? getMemoryUsageFromProc() : totalAllocatedMemory;

    auto start = std::chrono::high_resolution_clock::now();
    sortFunction();
    auto end = std::chrono::high_resolution_clock::now();

    long memoryAfter = (useProcessMemory) ? getMemoryUsageFromProc() : totalAllocatedMemory;

    if (memoryAfter < memoryBefore) {
        std::cerr << "[Error] Memory usage decreased unexpectedly in " << algorithmName << ".\n";
        memoryAfter = memoryBefore;  // 음수를 방지하기 위해 값을 수정
    }

    double duration = std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();
    statsMap[algorithmName] = {duration, memoryAfter - memoryBefore};

    std::cout << "[" << algorithmName << "] Execution Time: " << duration << " s\n";
    std::cout << "[" << algorithmName << "] Memory Usage Change: " << (memoryAfter - memoryBefore)
              << (useProcessMemory ? " KB (Process)" : " bytes (Allocator)") << "\n";
}




void recordStats(const std::string& algorithmName, const std::chrono::high_resolution_clock::time_point& start, const std::chrono::high_resolution_clock::time_point& end) {
    // 실행 시간 계산
    double durationInSeconds = std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();

    // 메모리 사용량 측정
    long memoryUsage = 0;
#ifdef _WIN32
    PROCESS_MEMORY_COUNTERS memInfo;
    if (GetProcessMemoryInfo(GetCurrentProcess(), &memInfo, sizeof(memInfo))) {
        memoryUsage = memInfo.WorkingSetSize / 1024; // KB 단위
    }
#else
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    memoryUsage = usage.ru_maxrss; // KB 단위
#endif

    // 결과 저장
    statsMap[algorithmName] = {durationInSeconds, memoryUsage};
}

void printStatsSummary() {
    std::cout << "========================================\n";
    std::cout << "Summary of Algorithm Performance\n";
    std::cout << std::setw(15) << "Algorithm" << std::setw(20) << "Execution Time (s)" << std::setw(20) << "Additional Memory Usage (KB)\n";
    std::cout << "----------------------------------------\n";
    for (const auto& [algorithmName, stats] : statsMap) {
        std::cout << std::setw(15) << algorithmName
                  << std::setw(20) << std::fixed << std::setprecision(3) << stats.timeInSeconds
                  << std::setw(20) << stats.memoryUsageInKB << "\n";
    }
    std::cout << "========================================\n";
}




vector <TrafficFlow> loadCsvData(const string& filename)
{
    auto load_start_time = chrono::high_resolution_clock::now();
    csvLoader loader(filename);
    vector<TrafficFlow> flows = loader.load();
    cout << "total flows : " << flows.size() << endl;
    auto load_end_time = chrono::high_resolution_clock::now();

    cout << "CSV 파일 로드 시간: "
         << chrono::duration_cast<chrono::milliseconds>(load_end_time - load_start_time).count()
         << "ms\n";

    return flows;
}

void printFlowDataByChunks(const vector<TrafficFlow>& flows, int chunkSize, int topN) {
    int totalChunks = (flows.size() + chunkSize - 1) / chunkSize; // 전체 청크 개수 계산
    for (int i = 0; i < totalChunks; i++) {
        cout << "Chunk " << i + 1 << ":\n";
        int start = i * chunkSize;
        int end = min(start + chunkSize, (int)flows.size());

        cout << "Displaying top " << topN << " flows in this chunk:\n";
        for (int j = start; j < end && j < start + topN; j++) {
            const auto& flow = flows[j];
            cout << "Flow ID: " << flow.flowID
                 << ", Flow Bytes per Second: " << flow.flowBytesPerSec
                 << ", Source IP: " << flow.sourceIP
                 << ", Destination IP: " << flow.destinationIP
                 << "\n";
        }
        cout << "----------------------------------------\n";
    }
}


int main() {
    std::string filename = "/workspace/CPP_LoadBalancing_algorithm/team_report_24/traffic_data_set.csv"; // CSV 파일 경로


    int limit = 5;       // 기본값
    int chunkSize = 100000; // 기본값
    char isShow = 'N';   // 기본값

    std::string input;   // 입력 받는 용 임시 문자열

    std::cout << "Enter the number of data to print (default: 5): ";
    std::getline(std::cin, input);
    if (!input.empty()) {
        try {
            limit = std::stoi(input);
        } catch (...) {
            limit = 5; // 변환 실패 시 기본값
        }
    }

    std::cout << "Enter the chunk size (default: 100000): ";
    std::getline(std::cin, input);
    if (!input.empty()) {
        try {
            chunkSize = std::stoi(input);
        } catch (...) {
            chunkSize = 100000; // 변환 실패 시 기본값
        }
    }

    std::cout << "Enter Y to show sorting process, N to hide (default: N): ";
    std::getline(std::cin, input);
    if (!input.empty()) {
        // 문자열의 첫 글자 검사
        char c = input[0];
        if (c == 'Y' || c == 'y') {
            isShow = 'Y';
        } else {
            isShow = 'N';
        }
    }

    bool showProcess = (isShow == 'Y' || isShow == 'y');


    // CSV 데이터 로드
    std::cout << "Loading CSV data...\n";
    vector<TrafficFlow> flows = loadCsvData(filename);
    std::cout << "Data loaded successfully.\n";

    // QuickSort
    std::cout << "Starting QuickSort...\n";
    vector<TrafficFlow> quickSortFlows = flows;
    auto quick_start = std::chrono::high_resolution_clock::now();
    QuickSort quickSort;
    quickSort.sort(quickSortFlows, showProcess);
    auto quick_end = std::chrono::high_resolution_clock::now();
    recordStats("QuickSort", quick_start, quick_end);
    std::cout << "QuickSort finished.\n";
    printFlowDataByChunks(quickSortFlows, chunkSize, limit);

    // MergeSort
    std::cout << "Starting MergeSort...\n";
    vector<TrafficFlow> mergeSortFlows = flows;
    auto merge_start = std::chrono::high_resolution_clock::now();
    MergeSort mergeSort;
    mergeSort.sort(mergeSortFlows, showProcess);
    auto merge_end = std::chrono::high_resolution_clock::now();
    recordStats("MergeSort", merge_start, merge_end);
    std::cout << "MergeSort finished.\n";
    printFlowDataByChunks(mergeSortFlows, chunkSize, limit);

    // HeapSort
    std::cout << "Starting HeapSort...\n";
    vector<TrafficFlow> heapSortFlows = flows;
    auto heap_start = std::chrono::high_resolution_clock::now();
    HeapSort heapSort;
    heapSort.sort(heapSortFlows, showProcess);
    auto heap_end = std::chrono::high_resolution_clock::now();
    recordStats("HeapSort", heap_start, heap_end);
    std::cout << "HeapSort finished.\n";
    printFlowDataByChunks(heapSortFlows, chunkSize, limit);

    // GreedySort
    std::cout << "Starting GreedySort...\n";
    vector<TrafficFlow> greedySortFlows = flows;
    auto greedy_start = std::chrono::high_resolution_clock::now();
    GreedySort greedySort;
    greedySort.sort(greedySortFlows, showProcess);
    auto greedy_end = std::chrono::high_resolution_clock::now();
    recordStats("GreedySort", greedy_start, greedy_end);
    std::cout << "GreedySort finished.\n";
    printFlowDataByChunks(greedySortFlows, chunkSize, limit);


    cout << "========================================\n";
    cout << "memory usage calculate..\n";
    cout << "========================================\n";

    // 정렬 알고리즘별 메모리 사용량 측정
    measureMemoryDuringSort("HeapSort", [&]() {
        HeapSort heapSort;
        heapSort.sort(flows, false);
    }, true);

    measureMemoryDuringSort("MergeSort", [&]() {
        MergeSort mergeSort;
        mergeSort.sort(flows, false);
    }, false);

    measureMemoryDuringSort("QuickSort", [&]() {
        QuickSort quickSort;
        quickSort.sort(flows, false);
    }, true);

    measureMemoryDuringSort("GreedySort", [&]() {
        GreedySort greedySort;
        greedySort.sort(flows, false);
    }, false);

    // 요약 출력
    std::cout << "\n========================================\n";
    printStatsSummary();
    std::cout << "========================================\n";

    // 결과 JSON 파일 저장
    JsonSaver jsonSaver;
    jsonSaver.saveResults(
            "/workspace/CPP_LoadBalancing_algorithm/team_report_24/jsonFile/results.json",
            quickSortFlows, mergeSortFlows, heapSortFlows, greedySortFlows);

    std::cout << "Results saved to JSON file.\n";

    return 0;
}
