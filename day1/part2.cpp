#include <fstream>
#include <iostream>
#include <string>

#define MAX_VALUE 99

int main() {
    int current = 50, total = 0, step;
    char op;
    std::string line;
    bool already_in_zero;

    std::ifstream f = std::ifstream("input");

    while (std::getline(f, line)) {
        already_in_zero = !current;

        op = line[0];
        step = std::stoi(line.substr(1, std::string::npos));

        op == 'R' ? current += step : current -= step;

        if (current < 1) {
            total += -current / (MAX_VALUE + 1);
            total += already_in_zero ? 0 : 1;
        } else if (current > MAX_VALUE) {
            total += current / (MAX_VALUE + 1);
        }
        
        current %= MAX_VALUE + 1;
        if (current < 0) current += MAX_VALUE + 1;

        std::cout << line << ": " << total << std::endl;
    }

    std::cout << total << std::endl;
}