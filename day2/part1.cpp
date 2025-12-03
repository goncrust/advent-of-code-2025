#include <fstream>
#include <iostream>
#include <string>

int main() {
    size_t pos = 0, range_div, range_begin, range_end, i, total = 0;
    std::string line, range_str, curr;
    std::ifstream f = std::ifstream("input");
    std::getline(f, line);

    while (pos != std::string::npos) {
        pos = line.find(',');
        range_str = pos != std::string::npos ? line.substr(0, pos) : line;
        line.erase(0, pos + 1);

        range_div = range_str.find('-');
        range_begin = std::stoul(range_str.substr(0, range_div));
        range_end =
            std::stoul(range_str.substr(range_div + 1, std::string::npos));

        for (i = range_begin; i <= range_end; i++) {
            curr = std::to_string(i);
            if (curr.length() % 2 != 0)
                continue;

            if (curr.substr(0, curr.length() / 2) ==
                curr.substr(curr.length() / 2, std::string::npos))
                total += i;
        }
    }

    std::cout << total << std::endl;
}