#include <SFML/Graphics.hpp>

#include "utils.cpp"
#include "globals.h"
#include "graphics.h"
#include "handle_input.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(tileSize * mapWidth, tileSize * mapHeight), "2D");
    window.setFramerateLimit(60);

    map = loadMapFromFile(currentMap);

    sf::RectangleShape player(sf::Vector2f(tileSize, tileSize));
    player.setFillColor(sf::Color::Green);
    player.setPosition(playerTile.x * tileSize, playerTile.y * tileSize);

    sf::RectangleShape block(sf::Vector2f(tileSize, tileSize));
    block.setFillColor(sf::Color::Red);

    sf::Clock moveCooldown;
    float moveDelay = 0.125f;

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        handlePlayerInput(map, player, moveCooldown, moveDelay, tileSize);

        drawGame(window, map, player, tileSize);
        window.display();
    }

    return 0;
}
