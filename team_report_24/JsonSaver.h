#ifndef JSONSAVER_H
#define JSONSAVER_H

#include <vector>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp> // JSON 라이브러리
#include "trafficFlow.h"

class JsonSaver {
public:
    // JSON 파일 저장
    void saveResults(const std::string& filename,
                     const std::vector<TrafficFlow>& quickSortFlows,
                     const std::vector<TrafficFlow>& mergeSortFlows,
                     const std::vector<TrafficFlow>& heapSortFlows,
                     const std::vector<TrafficFlow>& greedySortFlows) const;

private:
    // TrafficFlow 데이터를 JSON으로 변환
    nlohmann::json convertToJson(const std::vector<TrafficFlow>& flows) const;
};

#endif // JSONSAVER_H
