//
// Created by nodove on 24. 11. 25.
//

#ifndef CPP_LOADBALANCING_ALGORITHM_GREEDYSORT_H
#define CPP_LOADBALANCING_ALGORITHM_GREEDYSORT_H

#include <vector>
#include <algorithm>
#include "../trafficFlow.h"

class GreedySort {
public:
    void sort(std::vector<TrafficFlow> &flows);
};

#endif //CPP_LOADBALANCING_ALGORITHM_GREEDYSORT_H
