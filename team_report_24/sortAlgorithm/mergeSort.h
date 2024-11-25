//
// Created by nodove on 24. 11. 25.
//

#ifndef CPP_LOADBALANCING_ALGORITHM_MERGESORT_H
#define CPP_LOADBALANCING_ALGORITHM_MERGESORT_H
#include <vector>
#include "../trafficFlow.h"

class MergeSort {
public:
    void sort(std::vector<TrafficFlow>& flows);
private:
    void mergeSort(std::vector<TrafficFlow>& flows, int left, int right);
    void merge(std::vector<TrafficFlow>& flows, int left, int mid, int right);
};

#endif //CPP_LOADBALANCING_ALGORITHM_MERGESORT_H
