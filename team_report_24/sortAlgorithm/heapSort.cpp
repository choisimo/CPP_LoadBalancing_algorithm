#include "heapSort.h"
#include <chrono>
#include <iostream>
#include <algorithm>

void HeapSort::sort(std::vector<TrafficFlow>& flows) {
    std::cout << "[HeapSort] Starting sort...\n";
    auto start_time = std::chrono::high_resolution_clock::now();
    int n = flows.size();

    // 힙 구성 단계
    for (int i = n / 2 - 1; i >= 0; --i) {
        if (i % 1000 == 0 || i == 0) { // 큰 단계마다 로그 출력
            std::cout << "[HeapSort] Heapifying at index " << i << " during heap construction\n";
        }
        heapify(flows, n, i);
    }

    // 정렬 단계
    for (int i = n - 1; i > 0; --i) {
        if (i % 1000 == 0 || i == n - 1 || i == 1) { // 크기 변동의 주요 이벤트만 출력
            std::cout << "[HeapSort] Swapping root (" << flows[0].flowBytesPerSec
                      << ") with element at index " << i << " (" << flows[i].flowBytesPerSec << ")\n";
        }
        std::swap(flows[0], flows[i]);

        if (i % 1000 == 0 || i == 1) {
            std::cout << "[HeapSort] Heapifying root after swap, size reduced to " << i << "\n";
        }
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

    // 자주 호출되는 부분에서는 로그를 최소화
    if (n > 1000 && i % 5000 == 0) { // 주기적으로만 출력
        std::cout << "[HeapSort] Heapifying at index " << i << ", size=" << n << "\n";
    }

    if (left < n && flows[left].flowBytesPerSec > flows[largest].flowBytesPerSec) {
        largest = left;
    }

    if (right < n && flows[right].flowBytesPerSec > flows[largest].flowBytesPerSec) {
        largest = right;
    }

    if (largest != i) {
        if (n > 1000 && i % 5000 == 0) { // 대규모 데이터에 대해 간헐적으로 로그 출력
            std::cout << "[HeapSort] Swapping " << flows[i].flowBytesPerSec
                      << " with largest child " << flows[largest].flowBytesPerSec << "\n";
        }
        std::swap(flows[i], flows[largest]);
        heapify(flows, n, largest);
    }
}
