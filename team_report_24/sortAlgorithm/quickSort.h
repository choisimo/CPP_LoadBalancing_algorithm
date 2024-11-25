#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
#include "../trafficFlow.h"

class QuickSort {
public:
    void sort(std::vector<TrafficFlow>& flows);
private:
    void quickSort(std::vector<TrafficFlow>& flows, int low, int high);
    int partition(std::vector<TrafficFlow>& flows, int low, int high);
};

#endif // QUICKSORT_H
