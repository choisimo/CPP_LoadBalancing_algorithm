//
// Created by csimo on 24. 10. 21.
//

#ifndef TRAFFICFLOW_H
#define TRAFFICFLOW_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

struct TrafficFlow {
    std::string flowID;            // ????? ?? ID
    std::string sourceIP;          // ??? IP
    int sourcePort;                // ??? ??? ???
    std::string destinationIP;     // ???? IP
    int destinationPort;           // ???? ??? ???
    int protocol;                  // ???????? (??: TCP = 6, UDP = 17)
    std::string timestamp;         // ????????
    double flowDuration;           // ????? ???? ???? ?ð?
    int totalFwdPackets;           // ?? ???? ??? ??
    int totalBackwardPackets;      // ?? ????? ??? ??
    double flowBytesPerSec;        // ??? ????? ?????
    double flowPacketsPerSec;      // ??? ??? ?????
    double flowIATMean;            // ??? ?? ??? ????
    std::string label;             // ????? ?? (????, ??????)
    int totalPackets;              // ?? ??? ??
    std::string protocolName;      // ???????? ???
};

#endif //TRAFFICFLOW_H
