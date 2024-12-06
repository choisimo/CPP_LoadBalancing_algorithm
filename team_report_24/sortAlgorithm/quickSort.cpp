#include "quickSort.h"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <stack>

// 재귀


void QuickSort::sort(std::vector<TrafficFlow>& flows, bool showProcess) {
    std::stack<std::pair<int, int>> stack;
    stack.push({0, static_cast<int>(flows.size() - 1)});

    while (!stack.empty()) {
        int low = stack.top().first;
        int high = stack.top().second;
        stack.pop();

        if (showProcess)
        std::cout << "[QuickSort] Processing range: low=" << low << ", high=" << high << "\n";

        if (low < high) {
            auto [lt, gt] = partition(flows, low, high, showProcess);

            // 중요 이벤트만 로그 출력
            if (showProcess && ((high - low) > 10000 || stack.size() % 100 == 0)) {
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




void QuickSort::quickSort(std::vector<TrafficFlow>& flows, int low, int high, bool showProcess) {
    if (low < high) {

        // 3-way partitioning
        auto [lt, gt] = partition(flows, low, high, showProcess);

        // Recursive sort on left and right subarrays
        quickSort(flows, low, lt - 1, showProcess); // Sort less-than pivot
        quickSort(flows, gt + 1, high, showProcess); // Sort greater-than pivot
    }
}



std::pair<int, int> QuickSort::partition(std::vector<TrafficFlow>& flows, int low, int high, bool showProcess) {
    int randomPivotIndex = low + rand() % (high - low + 1);
    std::swap(flows[randomPivotIndex], flows[high]);

    double pivot = flows[high].flowBytesPerSec;

    // 피벗 값을 주기적으로만 출력
    if (showProcess && ((high - low) > 10000)) {
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
