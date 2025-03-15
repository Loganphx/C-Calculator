//
// Created by Logan on 3/14/2025.
//

#include <iostream>
#include "gameState.h"

gameState::gameState(sf::RenderWindow* window)
: state(window)
{

}

gameState::~gameState() {

}

void gameState::endState() {

}
void gameState::update(const float& dt) {
    std::cout << "Hello from GameStates!" << "\n";
}

void gameState::render(sf::RenderTarget* target = nullptr) {

}
