#include "quickSort.h"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <stack>

// 재귀
/*
void QuickSort::sort(std::vector<TrafficFlow>& flows) {
    std::cout << "[QuickSort] Starting sort...\n";

    auto start_time = std::chrono::high_resolution_clock::now();
    quickSort(flows, 0, flows.size() - 1);
    auto end_time = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    std::cout << "[QuickSort] Sort completed in " << duration << " ms\n";
}
*/

void QuickSort::sort(std::vector<TrafficFlow>& flows) {
    std::stack<std::pair<int, int>> stack;
    stack.push({0, static_cast<int>(flows.size() - 1)});

    while (!stack.empty()) {
        int low = stack.top().first;
        int high = stack.top().second;
        stack.pop();

        std::cout << "[QuickSort] Processing range: low=" << low << ", high=" << high << "\n";

        if (low < high) {
            auto [lt, gt] = partition(flows, low, high);

            // 중요 이벤트만 로그 출력
            if ((high - low) > 10000 || stack.size() % 100 == 0) {
                std::cout << "[QuickSort] Partitioned range: low=" << low
                          << ", high=" << high
                          << ", less-than pivot [" << low << ", " << lt - 1
                          << "], greater-than pivot [" << gt + 1 << ", " << high << "]\n";
            }
            if (low < lt - 1) stack.push({low, lt - 1});
            if (gt + 1 < high) stack.push({gt + 1, high});
        }
    }
}




void QuickSort::quickSort(std::vector<TrafficFlow>& flows, int low, int high) {
    if (low < high) {

        // 3-way partitioning
        auto [lt, gt] = partition(flows, low, high);

        // Recursive sort on left and right subarrays
        quickSort(flows, low, lt - 1); // Sort less-than pivot
        quickSort(flows, gt + 1, high); // Sort greater-than pivot
    }
}



std::pair<int, int> QuickSort::partition(std::vector<TrafficFlow>& flows, int low, int high) {
    int randomPivotIndex = low + rand() % (high - low + 1);
    std::swap(flows[randomPivotIndex], flows[high]);

    double pivot = flows[high].flowBytesPerSec;

    // 피벗 값을 주기적으로만 출력
    if ((high - low) > 10000) {
        std::cout << "[QuickSort] Pivot value for range [" << low << ", " << high << "] = " << pivot << "\n";
    }


    int lt = low;    // Less than pivot
    int gt = high;   // Greater than pivot
    int i = low;

    while (i <= gt) {
        if (flows[i].flowBytesPerSec < pivot) {
            std::swap(flows[lt], flows[i]);
            ++lt;
            ++i;
        } else if (flows[i].flowBytesPerSec > pivot) {
            std::swap(flows[i], flows[gt]);
            --gt;
        } else {
            ++i;
        }
    }

    return {lt, gt}; // Return the range of elements equal to the pivot
}

/*
int QuickSort::partition(std::vector<TrafficFlow>& flows, int low, int high) {
    // 랜덤 피벗 선택
    int randomPivotIndex = low + rand() % (high - low + 1);
    std::swap(flows[randomPivotIndex], flows[high]); // 랜덤 피벗을 끝으로 이동

    double pivot = flows[high].flowBytesPerSec;
    std::cout << "[QuickSort] Pivot value=" << pivot << "\n";

    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (flows[j].flowBytesPerSec <= pivot) {
            ++i;
            std::swap(flows[i], flows[j]);
            std::cout << "[QuickSort] Swapped elements at index " << i << " and " << j << "\n";
        }
    }

    std::swap(flows[i + 1], flows[high]);
    std::cout << "[QuickSort] Final swap with pivot: Swapped index " << (i + 1) << " and " << high << "\n";

    return i + 1;
}
*/

