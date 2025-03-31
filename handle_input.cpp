#include "handle_input.h"
#include "globals.h"
#include "utils.h"

#include <iostream>

void handlePlayerInput(std::vector<std::vector<int>>& map,
                       sf::RectangleShape& player,
                       sf::Clock& moveCooldown,
                       float moveDelay,
                       int tileSize)
{
    if (currentState == Playing && moveCooldown.getElapsedTime().asSeconds() >= moveDelay)
    {
        sf::Vector2i direction(0, 0);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) direction.y = -1;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) direction.y = 1;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) direction.x = -1;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) direction.x = 1;

        if (direction != sf::Vector2i(0, 0)) {
            sf::Vector2i newPos = playerTile + direction;
            bool transitioned = false;

            // Обработка вертикального выхода за пределы
            if (newPos.y < 0) {
                auto it = mapLinks.find({currentMap, Up});
                if (it != mapLinks.end()) {
                    currentMap = it->second;
                    map = loadMapFromFile(currentMap);
                    newPos.y = static_cast<int>(map.size()) - 1;
                    transitioned = true;
                } else {
                    // Нет перехода – отменяем вертикальное смещение
                    newPos.y = playerTile.y;
                }
            } else if (newPos.y >= static_cast<int>(map.size())) {
                auto it = mapLinks.find({currentMap, Down});
                if (it != mapLinks.end()) {
                    currentMap = it->second;
                    map = loadMapFromFile(currentMap);
                    newPos.y = 0;
                    transitioned = true;
                } else {
                    newPos.y = playerTile.y;
                }
            }

            // Обработка горизонтального выхода за пределы
            if (newPos.x < 0) {
                auto it = mapLinks.find({currentMap, Left});
                if (it != mapLinks.end()) {
                    currentMap = it->second;
                    map = loadMapFromFile(currentMap);
                    newPos.x = static_cast<int>(map[0].size()) - 1;
                    transitioned = true;
                } else {
                    newPos.x = playerTile.x;
                }
            } else if (newPos.x >= static_cast<int>(map[0].size())) {
                auto it = mapLinks.find({currentMap, Right});
                if (it != mapLinks.end()) {
                    currentMap = it->second;
                    map = loadMapFromFile(currentMap);
                    newPos.x = 0;
                    transitioned = true;
                } else {
                    newPos.x = playerTile.x;
                }
            }

            if (transitioned || map[newPos.y][newPos.x] == 0) {
                playerTile = newPos;
                player.setPosition(playerTile.x * tileSize, playerTile.y * tileSize);
                moveCooldown.restart();
            }
        }
    }
}

