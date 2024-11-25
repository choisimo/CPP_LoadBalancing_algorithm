//
// Created by nodove on 24. 11. 23.
//
#include "heapSort.h"
#include <chrono>
#include <iostream>
#include <algorithm>

void HeapSort::sort(std::vector<TrafficFlow>& flows) {
    auto start_time = std::chrono::high_resolution_clock::now();
    int n = flows.size();

    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(flows, n, i);

    for (int i = n - 1; i > 0; --i) {
        std::swap(flows[0], flows[i]);
        heapify(flows, i, 0);
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    std::cout << "HeapSort Duration: " << duration << " ms" << std::endl;
}

void HeapSort::heapify(std::vector<TrafficFlow>& flows, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && flows[left].flowBytesPerSec > flows[largest].flowBytesPerSec)
        largest = left;

    if (right < n && flows[right].flowBytesPerSec > flows[largest].flowBytesPerSec)
        largest = right;

    if (largest != i) {
        std::swap(flows[i], flows[largest]);
        heapify(flows, n, largest);
    }
}
