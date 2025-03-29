#include "transitions.h"
#include "globals.h"
#include "utils.h"

#include <iostream>

void tryMapTransition(sf::RectangleShape& player) {
    // Вниз
    if (playerTile.y == map.size() - 1 && sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        auto it = mapLinks.find({currentMap, Down});
        if (it != mapLinks.end()) {
            currentMap = it->second;
            map = loadMapFromFile(currentMap);
            playerTile.y = 0;
            player.setPosition(playerTile.x * tileSize, playerTile.y * tileSize);
        }
    }

    // Вверх
    else if (playerTile.y == 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        auto it = mapLinks.find({currentMap, Up});
        if (it != mapLinks.end()) {
            currentMap = it->second;
            map = loadMapFromFile(currentMap);
            playerTile.y = map.size() - 1;
            player.setPosition(playerTile.x * tileSize, playerTile.y * tileSize);
        }
    }

    // Вправо
    else if (playerTile.x == map[0].size() - 1 && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        auto it = mapLinks.find({currentMap, Right});
        if (it != mapLinks.end()) {
            currentMap = it->second;
            map = loadMapFromFile(currentMap);
            playerTile.x = 0;
            player.setPosition(playerTile.x * tileSize, playerTile.y * tileSize);
        }
    }

    // Влево
    else if (playerTile.x == 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        auto it = mapLinks.find({currentMap, Left});
        if (it != mapLinks.end()) {
            currentMap = it->second;
            map = loadMapFromFile(currentMap);
            playerTile.x = map[0].size() - 1;
            player.setPosition(playerTile.x * tileSize, playerTile.y * tileSize);
        }
    }
}
