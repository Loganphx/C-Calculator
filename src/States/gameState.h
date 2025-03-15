//
// Created by Logan on 3/14/2025.
//

#ifndef CMAKESFMLPROJECT_GAMESTATE_H
#define CMAKESFMLPROJECT_GAMESTATE_H

#include "../state.h"

class gameState :
        public state
{
public:
    gameState(sf::RenderWindow* window);
    virtual ~gameState();

    void endState();

    void update(const float& dt);
    void render(sf::RenderTarget* target);
};


#endif //CMAKESFMLPROJECT_GAMESTATE_H
