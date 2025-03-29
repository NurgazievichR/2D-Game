#include "handle_input.h"
#include "globals.h"

void handlePlayerInput(std::vector<std::vector<int>>& map,
                       sf::RectangleShape& player,
                       sf::Clock& moveCooldown,
                       float moveDelay,
                       int tileSize)
{
    if (moveCooldown.getElapsedTime().asSeconds() >= moveDelay &&
        currentState == Playing)
    {
        sf::Vector2i newPos = playerTile;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && newPos.y > 0)
            newPos.y--;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && newPos.y < map.size() - 1)
            newPos.y++;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && newPos.x > 0)
            newPos.x--;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && newPos.x < map[0].size() - 1)
            newPos.x++;

        if (map[newPos.y][newPos.x] == 0) {
            playerTile = newPos;
            player.setPosition(playerTile.x * tileSize, playerTile.y * tileSize);
            moveCooldown.restart();
        }
    }
}
