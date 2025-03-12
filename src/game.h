//
// Created by Logan on 3/11/2025.
//

#include <SFML/Graphics.hpp>

#ifndef CMAKESFMLPROJECT_GAME_H
#define CMAKESFMLPROJECT_GAME_H


class game {
private:

    sf::RenderWindow *window;
    std::optional<sf::Event> sfEvent;

    void initWindow();
public:
    game();
    virtual ~game();

    void updateSFMLEvents();
    void update();
    void render();
    void run();
};


#endif //CMAKESFMLPROJECT_GAME_H
