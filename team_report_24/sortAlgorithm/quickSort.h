#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
#include "../trafficFlow.h"

class QuickSort {
public:
    void sort(std::vector<TrafficFlow>& flows, bool Process);
private:
    void quickSort(std::vector<TrafficFlow>& flows, int low, int high, bool showProcess);
    pair<int, int> partition(std::vector<TrafficFlow>& flows, int low, int high, bool showProcess);
};

#endif // QUICKSORT_H
