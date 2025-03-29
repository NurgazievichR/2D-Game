#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

void drawGame(sf::RenderWindow& window, const std::vector<std::vector<int>>& map, const sf::RectangleShape& player, int tileSize);
