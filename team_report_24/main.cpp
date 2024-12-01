#include <iostream>
#include <iomanip>
#include <chrono>
#include <vector>
#include <string>

#ifdef _WIN32
#include <windows.h>
#include <psapi.h> // GetProcessMemoryInfo
#else
#include <sys/resource.h> // rusage
#endif

#include "JsonSaver.h"
#include "trafficFlow.h"
#include "csvLoader.h"
#include "sortAlgorithm/quickSort.h"
#include "sortAlgorithm/mergeSort.h"
#include "sortAlgorithm/heapSort.h"
#include "sortAlgorithm/greedySort.h"

// CSV 데이터 로드 함수
vector<TrafficFlow> loadCsvData(const std::string& filename) {
    auto load_start_time = std::chrono::high_resolution_clock::now();
    csvLoader loader(filename);
    vector<TrafficFlow> flows = loader.load();
    std::cout << "Total flows: " << flows.size() << std::endl;
    auto load_end_time = std::chrono::high_resolution_clock::now();

    std::cout << "CSV 파일 로드 시간: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(load_end_time - load_start_time).count()
              << "ms\n";

    return flows;
}

// 플로우 데이터 출력 함수
void printFlowData(const vector<TrafficFlow>& flows, int limit) {
    int count = 0;
    for (const auto& flow : flows) {
        if (count++ >= limit) break;
        std::cout << "Flow ID: " << flow.flowID
                  << ", Flow Bytes per Second: " << flow.flowBytesPerSec
                  << ", Source IP: " << flow.sourceIP
                  << ", Destination IP: " << flow.destinationIP
                  << "\n";
    }
    std::cout << "...\n\n";
}

// 메모리 사용량 출력 함수
void printMemoryUsage() {
#ifdef _WIN32
    // Windows 전용 메모리 사용량 계산
    PROCESS_MEMORY_COUNTERS memInfo;
    if (GetProcessMemoryInfo(GetCurrentProcess(), &memInfo, sizeof(memInfo))) {
        std::cout << "Memory Usage: " << memInfo.WorkingSetSize / 1024 << " KB (" 
                  << memInfo.WorkingSetSize / (1024 * 1024) << " MB)\n";
    } else {
        std::cerr << "Failed to retrieve memory usage.\n";
    }
#else
    // Linux/Unix 전용 메모리 사용량 계산
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    std::cout << "Memory Usage: " << usage.ru_maxrss << " KB ("
              << usage.ru_maxrss / 1024 << " MB)\n";
#endif
}

int main() {
    std::string filename;
    std::cout << "Enter the path to the CSV file: ";
    std::getline(std::cin, filename); // 파일 경로 입력
    std::cout << std::endl;

    int limit = 5;
    std::cout << "Enter the number of data to print: ";
    std::cin >> limit;
    std::cout << std::endl;

    // CSV 데이터 로드
    vector<TrafficFlow> flows = loadCsvData(filename);

    // QuickSort
    vector<TrafficFlow> quickSortFlows = flows;
    QuickSort quickSort;
    auto quick_start = std::chrono::high_resolution_clock::now();
    quickSort.sort(quickSortFlows);
    auto quick_end = std::chrono::high_resolution_clock::now();
    std::cout << "QuickSort 시간: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(quick_end - quick_start).count()
              << "ms\n";
    std::cout << "QuickSort 결과 (상위 " << limit << " 개):\n";
    printFlowData(quickSortFlows, limit);

    // MergeSort
    vector<TrafficFlow> mergeSortFlows = flows;
    MergeSort mergeSort;
    auto merge_start = std::chrono::high_resolution_clock::now();
    mergeSort.sort(mergeSortFlows);
    auto merge_end = std::chrono::high_resolution_clock::now();
    std::cout << "MergeSort 시간: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(merge_end - merge_start).count()
              << "ms\n";
    std::cout << "MergeSort 결과 (상위 " << limit << " 개):\n";
    printFlowData(mergeSortFlows, limit);

    // HeapSort
    vector<TrafficFlow> heapSortFlows = flows;
    HeapSort heapSort;
    auto heap_start = std::chrono::high_resolution_clock::now();
    heapSort.sort(heapSortFlows);
    auto heap_end = std::chrono::high_resolution_clock::now();
    std::cout << "HeapSort 시간: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(heap_end - heap_start).count()
              << "ms\n";
    std::cout << "HeapSort 결과 (상위 " << limit << " 개):\n";
    printFlowData(heapSortFlows, limit);

    // GreedySort
    vector<TrafficFlow> greedySortFlows = flows;
    GreedySort greedySort;
    auto greedy_start = std::chrono::high_resolution_clock::now();
    greedySort.sort(greedySortFlows);
    auto greedy_end = std::chrono::high_resolution_clock::now();
    std::cout << "GreedySort 시간: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(greedy_end - greedy_start).count()
              << "ms\n";
    std::cout << "GreedySort 결과 (상위 " << limit << " 개):\n";
    printFlowData(greedySortFlows, limit);

    // 최종 결과 저장
    JsonSaver jsonSaver;
    jsonSaver.saveResults("jsonFile/results.json", quickSortFlows, mergeSortFlows, heapSortFlows, greedySortFlows);

    return 0;
}
