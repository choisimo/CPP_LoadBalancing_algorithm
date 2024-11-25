#include "quickSort.h"
#include <algorithm>
#include <chrono>
#include <iostream>

void QuickSort::sort(std::vector<TrafficFlow>& flows) {
    auto start_time = std::chrono::high_resolution_clock::now();
    quickSort(flows, 0, flows.size() - 1);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    std::cout << "QuickSort Duration: " << duration << " ms" << std::endl;
}

void QuickSort::quickSort(std::vector<TrafficFlow>& flows, int low, int high) {
    if (low < high) {
        int pi = partition(flows, low, high);
        quickSort(flows, low, pi - 1);
        quickSort(flows, pi + 1, high);
    }
}

int QuickSort::partition(std::vector<TrafficFlow>& flows, int low, int high) {
    double pivot = flows[high].flowBytesPerSec;
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (flows[j].flowBytesPerSec < pivot) {
            ++i;
            std::swap(flows[i], flows[j]);
        }
    }
    std::swap(flows[i + 1], flows[high]);
    return i + 1;
}
