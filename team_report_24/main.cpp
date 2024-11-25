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

int main() {
    string filename = "/workspace/CPP_LoadBalancing_algorithm/team_report_24/traffic_data_set.csv"; // CSV ???? ??? ????

    // CSV 데이터 로드
    vector<TrafficFlow> flows = loadCsvData(filename);

    return 0;
}
