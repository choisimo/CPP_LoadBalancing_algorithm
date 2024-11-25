//
// Created by nodove on 24. 11. 25.
//
#include "greedySort.h"
#include <iostream>
#include <chrono>

void GreedySort::sort(std::vector<TrafficFlow>& flows) {
    auto start_time = std::chrono::high_resolution_clock::now();
    std::stable_sort(flows.begin(), flows.end(), [](const TrafficFlow& a, const TrafficFlow& b) {
        return a.flowBytesPerSec < b.flowBytesPerSec;
    });
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    std::cout << "GreedySort (Stable Sort) Duration: " << duration << " ms" << std::endl;
}
