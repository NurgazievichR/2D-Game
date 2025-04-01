#include "loading.h"
#include <iostream>

void loadBlockRegistry() {
    blockRegistry[GreyTile] = BlockInfo("Grey Tile", "tile.png", true);

    // Загружаем стол (непроходимый)
    blockRegistry[Table] = BlockInfo("Table", "table.png");

    // Загружаем шкаф (непроходимый)
    // blockRegistry[Wardrobe] = BlockInfo("Wardrobe", "wardrobe.png");
}

void unloadBlockRegistry() {
    // Если потребуется явная разгрузка ресурсов, можно очистить реестр:
    blockRegistry.clear();
}
