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
    std::string flowID;            // 트래픽 플로우를 구분하는 고유 ID
    std::string sourceIP;          // 송신 IP 주소
    int sourcePort;                // 송신 포트 번호
    std::string destinationIP;     // 수신 IP 주소
    int destinationPort;           // 수신 포트 번호
    int protocol;                  // 사용 프로토콜 (예: TCP = 6, UDP = 17)
    std::string timestamp;         // 트래픽 발생 시간
    double flowDuration;           // 플로우 지속 시간 (초 단위)
    int totalFwdPackets;           // 송신된 총 패킷 수
    int totalBackwardPackets;      // 수신된 총 패킷 수
    double flowBytesPerSec;        // 초당 전송된 바이트 수
    double flowPacketsPerSec;      // 초당 전송된 패킷 수
    double flowIATMean;            // 패킷 간 평균 간격
    std::string label;             // 트래픽 플로우의 분류 (예: 정상, 비정상)
    int totalPackets;              // 총 패킷 수 (송신 + 수신)
    std::string protocolName;      // 프로토콜 이름 (예: TCP, UDP)
};


#endif //TRAFFICFLOW_H
