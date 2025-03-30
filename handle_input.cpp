#include "handle_input.h"
#include "globals.h"
#include "utils.h"

void handlePlayerInput(std::vector<std::vector<int>>& map,
                       sf::RectangleShape& player,
                       sf::Clock& moveCooldown,
                       float moveDelay,
                       int tileSize)
{
    if (moveCooldown.getElapsedTime().asSeconds() >= moveDelay &&
        currentState == Playing)
    {
        sf::Vector2i direction(0, 0);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) direction.y = -1;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) direction.y = 1;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) direction.x = -1;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) direction.x = 1;

        if (direction != sf::Vector2i(0, 0)) {
            sf::Vector2i newPos = playerTile + direction;

            // Переход между картами
            bool transitioned = false;

            if (newPos.y < 0) {
                auto it = mapLinks.find({currentMap, Up});
                if (it != mapLinks.end()) {
                    currentMap = it->second;
                    map = loadMapFromFile(currentMap);
                    newPos.y = map.size() - 1;
                    transitioned = true;
                }
            } else if (newPos.y >= map.size()) {
                auto it = mapLinks.find({currentMap, Down});
                if (it != mapLinks.end()) {
                    currentMap = it->second;
                    map = loadMapFromFile(currentMap);
                    newPos.y = 0;
                    transitioned = true;
                }
            } else if (newPos.x < 0) {
                auto it = mapLinks.find({currentMap, Left});
                if (it != mapLinks.end()) {
                    currentMap = it->second;
                    map = loadMapFromFile(currentMap);
                    newPos.x = map[0].size() - 1;
                    transitioned = true;
                }
            } else if (newPos.x >= map[0].size()) {
                auto it = mapLinks.find({currentMap, Right});
                if (it != mapLinks.end()) {
                    currentMap = it->second;
                    map = loadMapFromFile(currentMap);
                    newPos.x = 0;
                    transitioned = true;
                }
            }

            // После загрузки карты, проверим коллизию
            if (map[newPos.y][newPos.x] == 0) {
                playerTile = newPos;
                player.setPosition(playerTile.x * tileSize, playerTile.y * tileSize);
                moveCooldown.restart();
            } else if (transitioned) {
                // если карта сменилась, но ячейка занята — отменим переход
                playerTile = playerTile; // останемся на месте
            }
        }
    }
}
