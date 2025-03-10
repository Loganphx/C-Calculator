#include <SFML/Graphics.hpp>

int main()
{
    auto window = sf::RenderWindow(
            sf::VideoMode({1280, 720u}),
                                   "CMake SFML Project",
                                   sf::Style::Titlebar | sf::Style::Resize | sf::Style::Close);
    window.setFramerateLimit(60);

    const auto onClose = [&window](const sf::Event::Closed&)
    {
        window.close();
    };
    const auto onMousePressed = [&window](const sf::Event::MouseButtonPressed& mousePressed) {
        if(mousePressed.button == sf::Mouse::Button::Left) {
            // Left Click!
        }
        else if(mousePressed.button == sf::Mouse::Button::Right) {
            // Right Click!
        }
        else if(mousePressed.button == sf::Mouse::Button::Middle) {
            // Middle Click!
        }
    };

    const auto onKeyPressed = [&window](const sf::Event::KeyPressed& keyPressed) {
        if(keyPressed.scancode == sf::Keyboard::Scancode::W){
            // W!
        }
        else if(keyPressed.scancode == sf::Keyboard::Scancode::A){
            // A!
        }
        else if(keyPressed.scancode == sf::Keyboard::Scancode::S){
            // S!
        }
        else if(keyPressed.scancode == sf::Keyboard::Scancode::D){
            // D!
        }
    };

    const auto onFocusLost = [&window](const sf::Event::FocusLost&) {
        //myGame.pause();
        // Background fps is 30.
        window.setFramerateLimit(30);
    };

    const auto onFocusGained = [&window](const sf::Event::FocusGained&) {
        //myGame.resume();
        // Foreground fps is 60
        //Todo replace this with a config value
        window.setFramerateLimit(60);
    };
    while (window.isOpen())
    {
        window.handleEvents(onClose, onMousePressed, onKeyPressed, onFocusLost, onFocusGained);

//        while (const std::optional event = window.pollEvent())
//        {
////            if (event->is<sf::Event::Closed>())
////            {
////                window.close();
////            }
//        }

        window.clear();
        window.display();
    }
}
