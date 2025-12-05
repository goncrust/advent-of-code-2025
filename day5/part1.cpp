#include <fstream>
#include <iostream>
#include <vector>

int main() {
    std::string line;
    std::ifstream f = std::ifstream("input");

    std::vector<std::pair<size_t, size_t>> ranges;
    while (std::getline(f, line) && line != "") {
        std::pair<size_t, size_t> range;

        range.first = std::stoull(line.substr(0, line.find("-")));
        range.second =
            std::stoull(line.substr(line.find("-") + 1, std::string::npos));
        ranges.push_back(range);
    }

    size_t curr;
    int total = 0;
    while (std::getline(f, line)) {
        curr = std::stoull(line);

        for (std::pair<size_t, size_t> r : ranges) {
            if (curr >= r.first && curr <= r.second) {
                total++;
                break;
            }
        }
    }

    std::cout << total << std::endl;
}