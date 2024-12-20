//
// Created by nodove on 24. 11. 25.
//

#ifndef CPP_LOADBALANCING_ALGORITHM_MERGESORT_H
#define CPP_LOADBALANCING_ALGORITHM_MERGESORT_H
#include <vector>
#include "../trafficFlow.h"

class MergeSort {
public:
    void sort(std::vector<TrafficFlow>& flows, bool showProcess);
private:
    void mergeSort(std::vector<TrafficFlow>& flows, int left, int right, bool showProcess);
    void merge(std::vector<TrafficFlow>& flows, int left, int mid, int right, bool showProcess);
};

#endif //CPP_LOADBALANCING_ALGORITHM_MERGESORT_H
