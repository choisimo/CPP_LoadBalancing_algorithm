//
// Created by csimo on 24. 10. 21.
//

class csvLoader {
private:
    string filename;
public:
    csvLoader(const string& f) : filename(f) {
        std::cout << "loading file: " << this->filename << "..." <<  std::endl;
    }

    vector<TrafficFlow> load();
    /* {
        ifstream file(filename);
        string line, cell;
        vector<TrafficFlow> flows;

        // header???? column ????
        getline(file, line);
        stringstream headerStream(line);
        vector<string> headers;

        while (getline(headerStream, cell, ',')) {
            headers.push_back(cell);
        }

        unordered_map<string, int> header_map;
        for (int i = 0; i < headers.size(); i++) {
            header_map[headers[i]] = i;
        }

        while (getline(file, line)) {
            stringstream lineStream(line);
            vector<string> row;

            while (getline(lineStream, cell, ',')) {
                row.push_back(cell);
            }

            // TrafficFlow ????ü ????
            TrafficFlow flow;

            flow.flowID = row[header_map["Flow.ID"]];
            flow.sourceIP = row[header_map["Source.IP"]];
            flow.sourcePort = stoi(row[header_map["Source.Port"]]);
            flow.destinationIP = row[header_map["Destination.IP"]];
            flow.destinationPort = stoi(row[header_map["Destination.Port"]]);
            flow.protocol = stoi(row[header_map["Protocol"]]);
            flow.timestamp = row[header_map["Timestamp"]];

            //
            try {
                flow.flowDuration = stod(row[header_map["Flow.Duration"]]);
            } catch (const std::invalid_argument& e) {
                flow.flowDuration = 0.0;
            }

            flow.totalFwdPackets = stoi(row[header_map["Total.Fwd.Packets"]]);
            flow.totalBackwardPackets = stoi(row[header_map["Total.Backward.Packets"]]);

            // ??? ??????? ??? ?????
            try {
                flow.flowBytesPerSec = stod(row[header_map["Flow.Bytes.s"]]);
            } catch (const std::invalid_argument& e) {
                flow.flowBytesPerSec = 0.0;
            }

            try {
                flow.flowPacketsPerSec = stod(row[header_map["Flow.Packets.s"]]);
            } catch (const std::invalid_argument& e) {
                flow.flowPacketsPerSec = 0.0;
            }

            // ??? ?? ??? ???? ???? ó??
            try {
                flow.flowIATMean = stod(row[header_map["Flow.IAT.Mean"]]);
            } catch (const std::invalid_argument& e) {
                flow.flowIATMean = 0.0;
            }

            flow.label = row[header_map["Label"]];
            flow.totalPackets = stoi(row[header_map["Total.Fwd.Packets"]]) + stoi(row[header_map["Total.Backward.Packets"]]);
            flow.protocolName = row[header_map["ProtocolName"]];

            flows.push_back(flow);
        }

        return flows;
    }*/
};

vector<TrafficFlow> csvLoader::load() {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return {};
    }

    string line;
    vector<string> lines;

    // 파일의 모든 줄을 메모리에 로드
    while (getline(file, line)) {
        lines.push_back(line);
    }
    file.close();

    if (lines.empty()) return {};

    // 헤더 처리
    stringstream headerStream(lines[0]);
    vector<string> headers;
    string cell;

    while (getline(headerStream, cell, ',')) {
        headers.push_back(cell);
    }

    unordered_map<string, int> header_map;
    for (int i = 0; i < headers.size(); i++) {
        header_map[headers[i]] = i;
    }

    vector<TrafficFlow> flows(lines.size() - 1);

    // OpenMP를 사용한 병렬 파싱
#pragma omp parallel for
    for (int i = 1; i < lines.size(); i++) {
        stringstream lineStream(lines[i]);
        vector<string> row;

        while (getline(lineStream, cell, ',')) {
            row.push_back(cell);
        }

        TrafficFlow flow;

        flow.flowID = row[header_map["Flow.ID"]];
        flow.sourceIP = row[header_map["Source.IP"]];
        flow.sourcePort = stoi(row[header_map["Source.Port"]]);
        flow.destinationIP = row[header_map["Destination.IP"]];
        flow.destinationPort = stoi(row[header_map["Destination.Port"]]);
        flow.protocol = stoi(row[header_map["Protocol"]]);
        flow.timestamp = row[header_map["Timestamp"]];

        try {
            flow.flowDuration = stod(row[header_map["Flow.Duration"]]);
        } catch (...) {
            flow.flowDuration = 0.0;
        }

        flow.totalFwdPackets = stoi(row[header_map["Total.Fwd.Packets"]]);
        flow.totalBackwardPackets = stoi(row[header_map["Total.Backward.Packets"]]);

        try {
            flow.flowBytesPerSec = stod(row[header_map["Flow.Bytes.s"]]);
        } catch (...) {
            flow.flowBytesPerSec = 0.0;
        }

        try {
            flow.flowPacketsPerSec = stod(row[header_map["Flow.Packets.s"]]);
        } catch (...) {
            flow.flowPacketsPerSec = 0.0;
        }

        try {
            flow.flowIATMean = stod(row[header_map["Flow.IAT.Mean"]]);
        } catch (...) {
            flow.flowIATMean = 0.0;
        }

        flow.label = row[header_map["Label"]];
        flow.totalPackets = flow.totalFwdPackets + flow.totalBackwardPackets;
        flow.protocolName = row[header_map["ProtocolName"]];

        flows[i - 1] = flow;
    }

    return flows;
}