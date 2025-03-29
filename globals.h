#pragma once
#include <string>
#include <SFML/System/Vector2.hpp>

inline constexpr int tileSize = 40;
inline constexpr int mapWidth = 20;
inline constexpr int mapHeight = 15;

inline std::string currentMap = "maps/map1.txt";

enum State {
    Playing,
    Talking,
    Paused
};

inline State currentState = Playing;

inline sf::Vector2i playerTile = {2, 2};

enum Direction {
    Up,
    Down,
    Left,
    Right
};

inline std::vector<std::vector<int>> map;

inline std::map<std::pair<std::string, Direction>, std::string> mapLinks = {
    {{"maps/map1.txt", Right}, "maps/map2.txt"},
    {{"maps/map2.txt", Left}, "maps/map1.txt"},

    {{"maps/map1.txt", Down},  "maps/map3.txt"},
    {{"maps/map3.txt", Up},  "maps/map1.txt"},

    {{"maps/map3.txt", Down},  "maps/map4.txt"},
    {{"maps/map4.txt", Up},  "maps/map3.txt"},
};