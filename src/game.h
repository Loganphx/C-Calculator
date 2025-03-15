//
// Created by Logan on 3/11/2025.
//

#include <SFML/Graphics.hpp>
#include "state.h"

#ifndef CMAKESFMLPROJECT_GAME_H
#define CMAKESFMLPROJECT_GAME_H


class game {
private:

    sf::RenderWindow *window;
    std::optional<sf::Event> sfEvent;

    sf::Clock dtClock;
    float dt;

    std::stack<state*> states;
    sf::Font f = sf::Font("pixel-arial-14.otf");
    sf::Text clockText = sf::Text(f);

    void initWindow();
    void initStates();
public:
    game();
    virtual ~game();

    void updateDt();
    void updateSFMLEvents();
    void update();
    void render();
    void run();
};


#endif //CMAKESFMLPROJECT_GAME_H
