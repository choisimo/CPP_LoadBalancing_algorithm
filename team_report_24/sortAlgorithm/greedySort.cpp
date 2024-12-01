//
// Created by nodove on 24. 11. 25.
//
#include "greedySort.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <limits>

#include <queue>

#include <queue>
#include <vector>

struct CompareTrafficFlow {
    bool operator()(const TrafficFlow& a, const TrafficFlow& b) const {
        return a.flowBytesPerSec > b.flowBytesPerSec;  // 오름차순 정렬
    }
};

void GreedySort::sort(std::vector<TrafficFlow>& flows) {
    std::cout << "[GreedySort] Starting sort using Min-Heap...\n";

    if (flows.empty()) {
        std::cout << "[GreedySort] No data to sort.\n";
        return;
    }

    auto start_time = std::chrono::high_resolution_clock::now();

    // Min-Heap 생성
    std::priority_queue<TrafficFlow, std::vector<TrafficFlow>, CompareTrafficFlow> minHeap(flows.begin(), flows.end());

    // Min-Heap에서 하나씩 꺼내며 정렬
    for (int i = 0; i < flows.size(); ++i) {
        flows[i] = minHeap.top();
        minHeap.pop();

        // 진행률 출력 (10% 단위)
        if (flows.size() >= 10 && i % (flows.size() / 10) == 0) {
            std::cout << "[GreedySort] Progress: " << (i * 100 / flows.size()) << "%\n";
        }
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

    std::cout << "[GreedySort] Sort completed in " << duration << " ms\n";
}
