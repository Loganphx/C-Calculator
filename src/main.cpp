#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>
#include "game.h"

sf::Vector2<float> mousePos;
int map[10][10] = {};

int main()
{
    game game;

    game.run();

    return 0;
}
