#include <fstream>
#include <iostream>
#include <string>

int main() {
    size_t pos = 0, range_div, range_begin, range_end, i, j, k, total = 0,
           curr_len;
    bool ok;
    std::string line, range_str, curr, curr_substr;
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
            curr_len = curr.length();

            for (j = 1; j <= curr_len / 2; j++) {
                if (curr_len % j != 0)
                    continue;

                curr_substr = curr.substr(0, j);
                ok = true;
                for (k = j; k < curr_len; k += j) {
                    if (curr.substr(k, j) != curr_substr) {
                        ok = false;
                        break;
                    }
                }

                if (ok)
                    break;
            }

            if (ok)
                total += i;
        }
    }

    std::cout << total << std::endl;
}