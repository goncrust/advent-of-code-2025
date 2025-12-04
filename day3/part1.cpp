#include <fstream>
#include <iostream>

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

    int idx, total = 0;
    while (std::getline(f, line)) {
        idx = find_biggest_index(line.substr(0, line.length() - 1));
        total += (line[idx] - '0') * 10;

        idx += find_biggest_index(line.substr(idx + 1, std::string::npos)) + 1;
        total += line[idx] - '0';
    }

    std::cout << total << std::endl;
}