//
// Created by Logan on 3/11/2025.
//

#include "state.h"

state::state(sf::RenderWindow* window) {
    this->window = window;
    this->quit = false;
}

state::~state() {

}

void state::checkForEnd()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {

    }
}
void state::update(const float& dt) {

}

void state::render(sf::RenderTarget* target) {

}
