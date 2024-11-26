#include "JsonSaver.h"

void JsonSaver::saveResults(const std::string& filename,
                            const std::vector<TrafficFlow>& quickSortFlows,
                            const std::vector<TrafficFlow>& mergeSortFlows,
                            const std::vector<TrafficFlow>& heapSortFlows,
                            const std::vector<TrafficFlow>& greedySortFlows) const {
    nlohmann::json jsonData;

    jsonData["QuickSort"] = convertToJson(quickSortFlows);
    jsonData["MergeSort"] = convertToJson(mergeSortFlows);
    jsonData["HeapSort"] = convertToJson(heapSortFlows);
    jsonData["GreedySort"] = convertToJson(greedySortFlows);

    // JSON 파일 저장
    std::ofstream file(filename);
    if (file.is_open()) {
        file << jsonData.dump(4); // JSON 형식으로 들여쓰기 저장
        file.close();
        std::cout << "JSON 파일 저장 완료: " << filename << std::endl;
    } else {
        std::cerr << "JSON 파일 저장 실패: " << filename << std::endl;
    }
}

nlohmann::json JsonSaver::convertToJson(const std::vector<TrafficFlow>& flows) const {
    nlohmann::json jsonFlows = nlohmann::json::array();

    for (const auto& flow : flows) {
        jsonFlows.push_back({
                                    {"FlowID", flow.flowID},
                                    {"FlowBytesPerSec", flow.flowBytesPerSec},
                                    {"SourceIP", flow.sourceIP},
                                    {"DestinationIP", flow.destinationIP}
                            });
    }

    return jsonFlows;
}
