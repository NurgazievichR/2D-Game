#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

void handlePlayerInput(std::vector<std::vector<int>>& map, sf::RectangleShape& player, sf::Clock& moveCooldown, float moveDelay, int tileSize);
