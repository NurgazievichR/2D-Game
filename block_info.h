#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>

struct BlockInfo {
    std::string name;
    sf::Texture texture;
    bool passable;

    BlockInfo(const std::string& blockName, const std::string& texturePath, bool isPassable = false)
        : name(blockName), passable(isPassable)
    {
        std::string fullPath = "media/blocks/" + texturePath;
        sf::Image img;
        if (!img.loadFromFile(fullPath)) {
            std::cerr << "Ошибка загрузки изображения: " << fullPath << std::endl;
            exit(EXIT_FAILURE);
        }

        // Приведение изображения к 65x65
        img = resizeImage(img, 65, 65);

        if (!texture.loadFromImage(img)) {
            std::cerr << "Ошибка создания текстуры из изображения: " << fullPath << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    BlockInfo() : name(""), passable(true) { }

private:
    static sf::Image resizeImage(const sf::Image& original, unsigned targetWidth, unsigned targetHeight) {
        sf::Image resized;
        resized.create(targetWidth, targetHeight);

        sf::Vector2u srcSize = original.getSize();
        for (unsigned y = 0; y < targetHeight; ++y) {
            for (unsigned x = 0; x < targetWidth; ++x) {
                // Находим соответствующий пиксель из оригинала
                unsigned srcX = x * srcSize.x / targetWidth;
                unsigned srcY = y * srcSize.y / targetHeight;
                resized.setPixel(x, y, original.getPixel(srcX, srcY));
            }
        }

        return resized;
    }
};

