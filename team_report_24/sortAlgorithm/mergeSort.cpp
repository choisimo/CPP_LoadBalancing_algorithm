//
// Created by nodove on 24. 11. 22.
//
#include "mergeSort.h"
#include <chrono>
#include <iostream>

void MergeSort::sort(std::vector<TrafficFlow>& flows, bool showProcess) {
    std::cout << "[MergeSort] Starting sort...\n";
    auto start_time = std::chrono::high_resolution_clock::now();
    mergeSort(flows, 0, flows.size() - 1, showProcess);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    std::cout << "[MergeSort] Sort completed. Duration: " << duration << " ms\n";
}

void MergeSort::mergeSort(std::vector<TrafficFlow>& flows, int left, int right, bool showProcess) {
    if (left < right) {

        int mid = left + (right - left) / 2;


        // 로그 출력은 주요 이벤트에서만 실행
        if (showProcess && (right - left > 10000)) { // 데이터 범위가 큰 경우에만 출력
            std::cout << "[MergeSort] Splitting range: [" << left << ", " << mid << "] and [" << mid + 1 << ", " << right << "]\n";
        }


        mergeSort(flows, left, mid, showProcess);
        mergeSort(flows, mid + 1, right, showProcess);

        if (showProcess && (right - left > 10000)) { // 데이터 범위가 큰 경우에만 출력
            std::cout << "[MergeSort] Merging range: [" << left << ", " << mid << "] and [" << mid + 1 << ", " << right << "]\n";
        }

        merge(flows, left, mid, right, showProcess);
    }
}

void MergeSort::merge(std::vector<TrafficFlow>& flows, int left, int mid, int right, bool showProcess) {
    if (showProcess && (right - left > 10000)) { // 범위가 큰 병합 이벤트만 출력
        std::cout << "[MergeSort] Merging: left=" << left << ", mid=" << mid << ", right=" << right << "\n";
    }

    std::vector<TrafficFlow> leftArr(flows.begin() + left, flows.begin() + mid + 1);
    std::vector<TrafficFlow> rightArr(flows.begin() + mid + 1, flows.begin() + right + 1);

    if (leftArr.empty() || rightArr.empty()) {
        std::cerr << "[MergeSort] Error: One of the subarrays is empty. Check bounds!\n";
    }

    // 병합 로직 유지
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

    // 병합 완료 로그
    if (showProcess && (right - left > 10000)) {
        std::cout << "[MergeSort] Merging completed for range: [" << left << ", " << right << "]\n";
    }}

