//
// Created by nodove on 24. 11. 22.
//
#include "mergeSort.h"
#include <chrono>
#include <iostream>

void MergeSort::sort(std::vector<TrafficFlow>& flows) {
    std::cout << "[MergeSort] Starting sort...\n";
    auto start_time = std::chrono::high_resolution_clock::now();
    mergeSort(flows, 0, flows.size() - 1);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    std::cout << "[MergeSort] Sort completed. Duration: " << duration << " ms\n";
}

void MergeSort::mergeSort(std::vector<TrafficFlow>& flows, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        std::cout << "[MergeSort] Splitting range: [" << left << ", " << mid << "] and [" << mid + 1 << ", " << right << "]\n";


        mergeSort(flows, left, mid);
        mergeSort(flows, mid + 1, right);

        std::cout << "[MergeSort] Merging range: [" << left << ", " << mid << "] and [" << mid + 1 << ", " << right << "]\n";

        merge(flows, left, mid, right);
    }
}

void MergeSort::merge(std::vector<TrafficFlow>& flows, int left, int mid, int right) {
    std::cout << "[MergeSort] Merging subarrays...\n";


    std::vector<TrafficFlow> leftArr(flows.begin() + left, flows.begin() + mid + 1);
    std::vector<TrafficFlow> rightArr(flows.begin() + mid + 1, flows.begin() + right + 1);

    std::cout << "[MergeSort] Left array size: " << leftArr.size()
              << ", Right array size: " << rightArr.size() << "\n";


    int i = 0, j = 0, k = left;
    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i].flowBytesPerSec < rightArr[j].flowBytesPerSec) {
            std::cout << "[MergeSort] Selecting left[" << i << "] = " << leftArr[i].flowBytesPerSec << "\n";
            flows[k++] = leftArr[i++];
        } else {
            std::cout << "[MergeSort] Selecting right[" << j << "] = " << rightArr[j].flowBytesPerSec << "\n";
            flows[k++] = rightArr[j++];
        }
    }
    while (i < leftArr.size()) {
        std::cout << "[MergeSort] Adding remaining left[" << i << "] = " << leftArr[i].flowBytesPerSec << "\n";
        flows[k++] = leftArr[i++]; }
    while (j < rightArr.size()) {
        std::cout << "[MergeSort] Adding remaining right[" << j << "] = " << rightArr[j].flowBytesPerSec << "\n";
        flows[k++] = rightArr[j++]; }


    std::cout << "[MergeSort] Merging completed.\n";
}

