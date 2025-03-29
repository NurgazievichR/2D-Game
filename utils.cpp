#include "utils.h"
#include <fstream>

std::vector<std::vector<int>> loadMapFromFile(const std::string& filename) {
    std::vector<std::vector<int>> map;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::vector<int> row;
        for (char c : line) {
            if (c == '0') row.push_back(0);
            else if (c == '1') row.push_back(1);
            else row.push_back(0); // по умолчанию — пусто
        }
        map.push_back(row);
    }

    return map;
}

