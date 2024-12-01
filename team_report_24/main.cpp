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

void printFlowData(const vector<TrafficFlow>& flows, int limit) {
    int count = 0;
    for (const auto& flow : flows) {
        if (count++ >= limit) break;
        cout << "Flow ID: " << flow.flowID
             << ", Flow Bytes per Second: " << flow.flowBytesPerSec
             << ", Source IP: " << flow.sourceIP
             << ", Destination IP: " << flow.destinationIP
             << "\n";
    }
    cout << "...\n\n";
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



void printMemoryUsage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    cout << "Memory Usage: " << usage.ru_maxrss << "KB (" << usage.ru_maxrss / 1024 << "MB)\n";
}

int main() {
    string filename = "/workspace/CPP_LoadBalancing_algorithm/team_report_24/traffic_data_set.csv"; // CSV ???? ??? ????

    int limit = 5, chunkSize = 100000;
    char isShow = 'N';
    cout << "enter the number of data to print: ";
    cin >> limit;
    cout << "enter the chunk size:";
    cin >> chunkSize;
    cout << endl;
    cout << "enter Y to show sorting process, N to hide: ";
    cin >> isShow;


    bool showProcess = (isShow == 'Y' || isShow == 'y');
    // CSV 데이터 로드
    vector<TrafficFlow> flows = loadCsvData(filename);

    // QuickSort
    vector<TrafficFlow> quickSortFlows = flows;
    QuickSort quickSort;
    auto quick_start = chrono::high_resolution_clock::now();
    quickSort.sort(quickSortFlows, showProcess);
    auto quick_end = chrono::high_resolution_clock::now();
    cout << "QuickSort 시간: "
         << chrono::duration_cast<chrono::milliseconds>(quick_end - quick_start).count()
         << "ms\n";
    cout << "QuickSort 결과 (상위 " << limit << " 개):\n";
    printFlowDataByChunks(quickSortFlows, chunkSize, limit);

    // MergeSort
    vector<TrafficFlow> mergeSortFlows = flows;
    MergeSort mergeSort;
    auto merge_start = chrono::high_resolution_clock::now();
    mergeSort.sort(mergeSortFlows, showProcess);
    auto merge_end = chrono::high_resolution_clock::now();
    cout << "MergeSort 시간: "
         << chrono::duration_cast<chrono::milliseconds>(merge_end - merge_start).count()
         << "ms\n";
    cout << "MergeSort 결과 (상위 " << limit << " 개):\n";
    printFlowDataByChunks(mergeSortFlows,chunkSize, limit);

    // HeapSort
    vector<TrafficFlow> heapSortFlows = flows;
    HeapSort heapSort;
    auto heap_start = chrono::high_resolution_clock::now();
    heapSort.sort(heapSortFlows, showProcess);
    auto heap_end = chrono::high_resolution_clock::now();
    cout << "HeapSort 시간: "
         << chrono::duration_cast<chrono::milliseconds>(heap_end - heap_start).count()
         << "ms\n";
    cout << "HeapSort 결과 (상위 " << limit << " 개):\n";
    printFlowDataByChunks(heapSortFlows, chunkSize, limit);

    // GreedySort (Stable Sort)
    vector<TrafficFlow> greedySortFlows = flows;
    GreedySort greedySort;
    auto greedy_start = chrono::high_resolution_clock::now();
    greedySort.sort(greedySortFlows, showProcess);
    auto greedy_end = chrono::high_resolution_clock::now();
    cout << "GreedySort 시간: "
         << chrono::duration_cast<chrono::milliseconds>(greedy_end - greedy_start).count()
         << "ms\n";
    cout << "GreedySort 결과 (상위 " << limit << " 개):\n";
    printFlowDataByChunks(greedySortFlows, chunkSize, limit);


    cout << "========================================\n";
// 최종 결과 확인 - 청크 단위로 출력
    cout << "QuickSort 결과 (" << chunkSize << ") 개씩 나누어 상위 10개 출력):\n";
    printFlowDataByChunks(quickSortFlows, 50000, 10);
    cout << "========================================\n";

    cout << "MergeSort 결과 (" << chunkSize << ") 개씩 나누어 상위 10개 출력):\n";
    printFlowDataByChunks(mergeSortFlows, 50000, 10);
    cout << "========================================\n";

    cout << "HeapSort 결과 (" << chunkSize << ") 개씩 나누어 상위 10개 출력):\n";
    printFlowDataByChunks(heapSortFlows, 50000, 10);
    cout << "========================================\n";

    cout << "GreedySort 결과 (" << chunkSize << ") 개씩 나누어 상위 10개 출력):\n";
    printFlowDataByChunks(greedySortFlows, 50000, 10);
    cout << "========================================\n";



    cout << "========================================\n";
    cout << "시간 비교\n";
    cout << "QuickSort 시간: "
         << chrono::duration_cast<chrono::milliseconds>(quick_end - quick_start).count()
         << "ms ("
         << fixed << setprecision(3)
         << chrono::duration_cast<chrono::duration<double>>(quick_end - quick_start).count()
         << "s)\n";

    cout << "MergeSort 시간: "
         << chrono::duration_cast<chrono::milliseconds>(merge_end - merge_start).count()
         << "ms ("
         << fixed << setprecision(3)
         << chrono::duration_cast<chrono::duration<double>>(merge_end - merge_start).count()
         << "s)\n";

    cout << "HeapSort 시간: "
         << chrono::duration_cast<chrono::milliseconds>(heap_end - heap_start).count()
         << "ms ("
         << fixed << setprecision(3)
         << chrono::duration_cast<chrono::duration<double>>(heap_end - heap_start).count()
         << "s)\n";

    cout << "GreedySort 시간: "
         << chrono::duration_cast<chrono::milliseconds>(greedy_end - greedy_start).count()
         << "ms ("
         << fixed << setprecision(3)
         << chrono::duration_cast<chrono::duration<double>>(greedy_end - greedy_start).count()
         << "s)\n";
    cout << "========================================\n";

    // save sorted data to json file
    JsonSaver jsonSaver;
    jsonSaver.saveResults("/workspace/CPP_LoadBalancing_algorithm/team_report_24/jsonFile/results.json", quickSortFlows, mergeSortFlows, heapSortFlows, greedySortFlows);

    return 0;
}