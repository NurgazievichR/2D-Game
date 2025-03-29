#include "graphics.h"

void drawGame(sf::RenderWindow& window,
              const std::vector<std::vector<int>>& map,
              const sf::RectangleShape& player,
              int tileSize)
{
    window.clear(sf::Color::Black);

    sf::RectangleShape block(sf::Vector2f(tileSize, tileSize));
    block.setFillColor(sf::Color::Red);

    for (int y = 0; y < map.size(); y++) {
        for (int x = 0; x < map[y].size(); x++) {
            if (map[y][x] == 1) {
                block.setPosition(x * tileSize, y * tileSize);
                window.draw(block);
            }
        }
    }

    window.draw(player);
    window.display();
}
