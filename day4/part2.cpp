#include <fstream>
#include <iostream>
#include <vector>

int get_num_neighs(std::vector<std::vector<bool>> &map, int i, int j) {
    int nneighs = 0, k, m;

    for (k = i > 0 ? i - 1 : 0; k <= (i < map.size() - 1 ? i + 1 : i); k++) {
        for (m = j > 0 ? j - 1 : 0; m <= (j < map[i].size() - 1 ? j + 1 : j);
             m++) {
            if (k == i and m == j)
                continue;

            if (map[k][m])
                nneighs++;
        }
    }
    return nneighs;
}

int main() {
    std::string line;
    std::ifstream f = std::ifstream("input");

    int nneighs, i, j, total = 0;
    std::vector<std::vector<bool>> map, new_map;

    while (std::getline(f, line)) {
        std::vector<bool> vecline;
        for (char c : line) {
            if (c == '.')
                vecline.push_back(false);
            else if (c == '@')
                vecline.push_back(true);
        }
        new_map.push_back(vecline);
    }

    while (new_map != map) {
        map = new_map;
        for (i = 0; i < map.size(); i++) {
            for (j = 0; j < map[i].size(); j++) {
                if (!map[i][j])
                    continue;

                nneighs = get_num_neighs(map, i, j);
                if (nneighs < 4) {
                    new_map[i][j] = false;
                    total++;
                }
            }
        }
    }

    std::cout << total << std::endl;
}