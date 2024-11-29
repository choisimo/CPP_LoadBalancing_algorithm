//
// Created by nodove on 24. 11. 25.
//
#include "greedySort.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <limits>

void GreedySort::sort(std::vector<TrafficFlow>& flows) {
    std::cout << "[GreedySort] Starting sort...\n";

    auto start_time = std::chrono::high_resolution_clock::now();

    std::vector<TrafficFlow> sortedFlows; // 정렬된 결과를 저장할 배열
    std::vector<bool> visited(flows.size(), false); // 방문 여부 추적
    int n = flows.size();

    for (int i = 0; i < n; ++i) {
        double minValue = std::numeric_limits<double>::max();
        int minIndex = -1;

        // 현재 배열에서 최소 값을 찾음
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && flows[j].flowBytesPerSec < minValue) {
                minValue = flows[j].flowBytesPerSec;
                minIndex = j;
            }
        }

        // 최소 값을 정렬된 배열에 추가하고 방문으로 표시
        if (minIndex != -1) {
            sortedFlows.push_back(flows[minIndex]);
            visited[minIndex] = true;
        }

        // 진행 상태 출력
        if (i % (n / 1) == 0) { // 10% 간격으로 진행률 출력
            std::cout << "[GreedySort] Progress: " << (i * 100 / n) << "%\n";
        }
    }

    // 정렬된 결과를 원본 배열에 복사
    flows = sortedFlows;

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

    std::cout << "[GreedySort] Sort completed in " << duration << " ms\n";
}


/*
void GreedySort::sort(std::vector<TrafficFlow>& flows) {
    auto start_time = std::chrono::high_resolution_clock::now();
    std::stable_sort(flows.begin(), flows.end(), [](const TrafficFlow& a, const TrafficFlow& b) {
        return a.flowBytesPerSec < b.flowBytesPerSec;
    });
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    std::cout << "GreedySort (Stable Sort) Duration: " << duration << " ms" << std::endl;
}
*/
