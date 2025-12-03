#include <fstream>
#include <iostream>
#include <string>

#define MAX_VALUE 99

int main() {
    int current = 50, total = 0, step;
    char op;
    std::string line;

    std::ifstream f = std::ifstream("input");

    while (std::getline(f, line)) {
        op = line[0];
        step = std::stoi(line.substr(1, std::string::npos));

        op == 'R' ? current += step : current -= step;
        current %= MAX_VALUE + 1;
        if (current < 0)
            current += MAX_VALUE + 1;

        if (current == 0)
            total++;
    }

    std::cout << total << std::endl;
}