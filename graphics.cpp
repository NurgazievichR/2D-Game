#include "graphics.h"
#include "block_info.h"
#include "globals.h"

void drawGame(sf::RenderWindow& window,
              const std::vector<std::vector<int>>& map,
              const sf::RectangleShape& player,
              int tileSize)
{
    window.clear(sf::Color::Black);

    sf::Sprite sprite;
    for (int y = 0; y < map.size(); y++) {
        for (int x = 0; x < map[y].size(); x++) {
            int cell = map[y][x];

            // Безопасное приведение к enum
            BlockType type = static_cast<BlockType>(cell);

            // Проверяем, есть ли такой блок в реестре
            auto it = blockRegistry.find(type);
            if (it != blockRegistry.end()) {
                sprite.setTexture(it->second.texture);
                sprite.setPosition(x * tileSize, y * tileSize);
                window.draw(sprite);
            }
        }
    }

    window.draw(player);
    window.display();
}
