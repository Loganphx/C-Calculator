//
// Created by Logan on 3/11/2025.
//

#ifndef CMAKESFMLPROJECT_STATE_H
#define CMAKESFMLPROJECT_STATE_H


#include <vector>
#include <fstream>
#include <sstream>
#include <SFML/Graphics/Texture.hpp>
#include <stack>
#include <map>
#include <SFML/Graphics/RenderWindow.hpp>

class state {
private:
    sf::RenderWindow* window;
    std::vector<sf::Texture> textures;
    bool quit;

public:
    state(sf::RenderWindow* window);
    virtual ~state();

    virtual void checkForEnd();

    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;
};


#endif //CMAKESFMLPROJECT_STATE_H
