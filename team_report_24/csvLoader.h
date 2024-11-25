//
// Created by csimo on 24. 10. 21.
//

class csvLoader {
private:
    string filename;
public:
    csvLoader(const string& f) : filename(f) {}

    vector<TrafficFlow> load() {
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
    }
};
