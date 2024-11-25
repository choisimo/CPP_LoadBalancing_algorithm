//
// Created by nodove on 24. 11. 22.
//
#include "mergeSort.h"
#include <chrono>
#include <iostream>

void MergeSort::sort(std::vector<TrafficFlow>& flows) {
    auto start_time = std::chrono::high_resolution_clock::now();
    mergeSort(flows, 0, flows.size() - 1);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    std::cout << "MergeSort Duration: " << duration << " ms" << std::endl;
}

void MergeSort::mergeSort(std::vector<TrafficFlow>& flows, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(flows, left, mid);
        mergeSort(flows, mid + 1, right);
        merge(flows, left, mid, right);
    }
}

void MergeSort::merge(std::vector<TrafficFlow>& flows, int left, int mid, int right) {
    std::vector<TrafficFlow> leftArr(flows.begin() + left, flows.begin() + mid + 1);
    std::vector<TrafficFlow> rightArr(flows.begin() + mid + 1, flows.begin() + right + 1);

    int i = 0, j = 0, k = left;
    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i].flowBytesPerSec < rightArr[j].flowBytesPerSec) {
            flows[k++] = leftArr[i++];
        } else {
            flows[k++] = rightArr[j++];
        }
    }
    while (i < leftArr.size()) flows[k++] = leftArr[i++];
    while (j < rightArr.size()) flows[k++] = rightArr[j++];
}
