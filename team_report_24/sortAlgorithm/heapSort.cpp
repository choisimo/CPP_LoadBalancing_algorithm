//
// Created by nodove on 24. 11. 23.
//
#include "heapSort.h"
#include <chrono>
#include <iostream>
#include <algorithm>

void HeapSort::sort(std::vector<TrafficFlow>& flows) {
    std::cout << "[HeapSort] Starting sort...\n";
    auto start_time = std::chrono::high_resolution_clock::now();
    int n = flows.size();

    for (int i = n / 2 - 1; i >= 0; --i) {
        std::cout << "[HeapSort] Heapifying at index " << i << " during heap construction\n";
        heapify(flows, n, i);
    }

    for (int i = n - 1; i > 0; --i) {
        std::cout << "[HeapSort] Swapping root (" << flows[0].flowBytesPerSec
                  << ") with element at index " << i << " (" << flows[i].flowBytesPerSec << ")\n";
        std::swap(flows[0], flows[i]);
        std::cout << "[HeapSort] Heapifying root after swap, size reduced to " << i << "\n";
        heapify(flows, i, 0);
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    std::cout << "[HeapSort] Sort completed. Duration: " << duration << " ms\n";
}

void HeapSort::heapify(std::vector<TrafficFlow>& flows, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;


    std::cout << "[HeapSort] Heapifying at index " << i << " with size " << n << "\n";
    std::cout << "[HeapSort] Current largest: index " << largest
              << " (" << flows[largest].flowBytesPerSec << ")\n";


    if (left < n && flows[left].flowBytesPerSec > flows[largest].flowBytesPerSec) {
        std::cout << "[HeapSort] Left child " << flows[left].flowBytesPerSec
                  << " is larger than current largest " << flows[largest].flowBytesPerSec << "\n";

        largest = left;
    }

    if (right < n && flows[right].flowBytesPerSec > flows[largest].flowBytesPerSec) {
        std::cout << "[HeapSort] Right child " << flows[right].flowBytesPerSec
                  << " is larger than current largest " << flows[largest].flowBytesPerSec << "\n";

        largest = right;
    }
    if (largest != i) {
        std::cout << "[HeapSort] Swapping " << flows[i].flowBytesPerSec
                  << " with largest child " << flows[largest].flowBytesPerSec << "\n";

        std::swap(flows[i], flows[largest]);

        heapify(flows, n, largest);
    } else {
        std::cout << "[HeapSort] No swap needed\n";
    }
}
