#include <fstream>
#include <iostream>
#include <vector>

int main() {
    std::string line;
    std::ifstream f = std::ifstream("input");

    std::vector<std::pair<size_t, size_t>> ranges;
    bool found;
    while (std::getline(f, line) && line != "") {
        std::pair<size_t, size_t> nr;

        nr.first = std::stoull(line.substr(0, line.find("-")));
        nr.second =
            std::stoull(line.substr(line.find("-") + 1, std::string::npos));
        ranges.push_back(nr);
    }

    // merge ranges
    for (int i = 0; i < ranges.size() - 1; i++) {
        found = false;
        for (int j = i + 1; j < ranges.size(); j++) {
            if (ranges[i].first >= ranges[j].first &&
                ranges[i].second <= ranges[j].second) {
                found = true;
            } else if (ranges[i].first >= ranges[j].first &&
                       ranges[i].first <= ranges[j].second) {
                ranges[j].second = ranges[i].second;
                found = true;
            } else if (ranges[i].second >= ranges[j].first &&
                       ranges[i].second <= ranges[j].second) {
                ranges[j].first = ranges[i].first;
                found = true;
            } else if (ranges[i].first < ranges[j].first &&
                       ranges[i].second > ranges[j].second) {
                ranges[j] = ranges[i];
                found = true;
            }
        }

        if (found) {
            ranges.erase(ranges.begin() + i);
            i--;
        }
    }

    size_t total = 0;
    for (std::pair<size_t, size_t> r : ranges) {
        total += r.second - r.first + 1;
    }

    std::cout << total << std::endl;
}