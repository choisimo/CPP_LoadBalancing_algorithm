//
// Created by nodove on 24. 11. 25.
//

#ifndef CPP_LOADBALANCING_ALGORITHM_HEAPSORT_H
#define CPP_LOADBALANCING_ALGORITHM_HEAPSORT_H

#include <vector>
#include "../trafficFlow.h"

class HeapSort {
public:
    void sort(std::vector<TrafficFlow>& flows, bool showProcess);
private:
    void heapify(std::vector<TrafficFlow>& flows, int n, int i, bool showProcess);
};

#endif //CPP_LOADBALANCING_ALGORITHM_HEAPSORT_H
