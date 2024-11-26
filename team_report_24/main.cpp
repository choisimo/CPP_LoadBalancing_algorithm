//
// Created by csimo on 24. 10. 21.
//
#include "trafficFlow.h"
#include "csvLoader.h"
#include "sortAlgorithm/quickSort.h"
#include "sortAlgorithm/mergeSort.h"
#include "sortAlgorithm/heapSort.h"
#include "sortAlgorithm/greedySort.h"
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

void printFlowData(const vector<TrafficFlow>& flows, int limit = 5) {
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


int main() {
    string filename = "/workspace/CPP_LoadBalancing_algorithm/team_report_24/traffic_data_set.csv"; // CSV ???? ??? ????

    // CSV 데이터 로드
    vector<TrafficFlow> flows = loadCsvData(filename);

    // QuickSort
    vector<TrafficFlow> quickSortFlows = flows;
    QuickSort quickSort;
    auto quick_start = chrono::high_resolution_clock::now();
    quickSort.sort(quickSortFlows);
    auto quick_end = chrono::high_resolution_clock::now();
    cout << "QuickSort 시간: "
         << chrono::duration_cast<chrono::milliseconds>(quick_end - quick_start).count()
         << "ms\n";
    cout << "QuickSort 결과 (상위 5개):\n";
    printFlowData(quickSortFlows);

    // MergeSort
    vector<TrafficFlow> mergeSortFlows = flows;
    MergeSort mergeSort;
    auto merge_start = chrono::high_resolution_clock::now();
    mergeSort.sort(mergeSortFlows);
    auto merge_end = chrono::high_resolution_clock::now();
    cout << "MergeSort 시간: "
         << chrono::duration_cast<chrono::milliseconds>(merge_end - merge_start).count()
         << "ms\n";
    cout << "MergeSort 결과 (상위 5개):\n";
    printFlowData(mergeSortFlows);

    // HeapSort
    vector<TrafficFlow> heapSortFlows = flows;
    HeapSort heapSort;
    auto heap_start = chrono::high_resolution_clock::now();
    heapSort.sort(heapSortFlows);
    auto heap_end = chrono::high_resolution_clock::now();
    cout << "HeapSort 시간: "
         << chrono::duration_cast<chrono::milliseconds>(heap_end - heap_start).count()
         << "ms\n";
    cout << "HeapSort 결과 (상위 5개):\n";
    printFlowData(heapSortFlows);

    // GreedySort (Stable Sort)
    vector<TrafficFlow> greedySortFlows = flows;
    GreedySort greedySort;
    auto greedy_start = chrono::high_resolution_clock::now();
    greedySort.sort(greedySortFlows);
    auto greedy_end = chrono::high_resolution_clock::now();
    cout << "GreedySort 시간: "
         << chrono::duration_cast<chrono::milliseconds>(greedy_end - greedy_start).count()
         << "ms\n";
    cout << "GreedySort 결과 (상위 5개):\n";
    printFlowData(greedySortFlows);


    cout << "========================================\n";
    // 최종 결과 확인
    cout << "QuickSort 결과 (상위 5개):\n";
    printFlowData(quickSortFlows);
    cout << "MergeSort 결과 (상위 5개):\n";
    printFlowData(mergeSortFlows);
    cout << "HeapSort 결과 (상위 5개):\n";
    printFlowData(heapSortFlows);
    cout << "GreedySort 결과 (상위 5개):\n";
    printFlowData(greedySortFlows);

    cout << "========================================\n";
    
    return 0;
}