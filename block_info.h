#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <cstdlib>

struct BlockInfo {
    std::string name;
    sf::Texture texture;
    bool passable;

    BlockInfo(const std::string& blockName, const std::string& texturePath, bool isPassable=false)
        : name(blockName), passable(isPassable)
    {
        std::string fullPath = "media/blocks/" + texturePath;
        if (!texture.loadFromFile(fullPath)) {
            std::cerr << "Ошибка загрузки текстуры: " << fullPath << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    BlockInfo()=default;
};

