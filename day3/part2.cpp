#include <fstream>
#include <iostream>
#include <math.h>

int find_biggest_index(std::string str) {
    int i, curr, biggest = -1, idx;
    for (i = 0; i < str.length(); i++) {
        curr = str[i] - '0';
        if (curr > biggest) {
            biggest = curr;
            idx = i;
        }
    }

    return idx;
}

int main() {
    std::string line;
    std::ifstream f = std::ifstream("input");

    int i, idx;
    size_t total = 0;
    while (std::getline(f, line)) {
        idx = find_biggest_index(line.substr(0, line.length() - 11));
        total += (line[idx] - '0') * std::pow(10, 11);

        for (i = 10; i >= 0; i--) {
            idx +=
                find_biggest_index(line.substr(idx + 1, line.length() - i - idx - 1)) + 1;
            total += (line[idx] - '0') * (std::pow(10, i));
        }
    }

    std::cout << total << std::endl;
}