//
// Created by Logan on 3/11/2025.
//

#ifndef CMAKESFMLPROJECT_STATE_H
#define CMAKESFMLPROJECT_STATE_H


#include <vector>
#include <fstream>
#include <sstream>
#include <SFML/Graphics/Texture.hpp>

class state {
private:
    std::vector<sf::Texture> textures;

public:
    state();
    virtual ~state();

    virtual void update() = 0;
    virtual void render() = 0;
};


#endif //CMAKESFMLPROJECT_STATE_H
