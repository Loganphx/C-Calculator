#include <SFML/Graphics.hpp>

int main()
{
    auto window = sf::RenderWindow(
            sf::VideoMode({1280, 720u}),
                                   "CMake SFML Project",
                                   sf::Style::Titlebar | sf::Style::Resize | sf::Style::Close);
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            else if(const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>())
            {
                if(mousePressed->button == sf::Mouse::Button::Left) {
                    // Left Click!
                }
                else if(mousePressed->button == sf::Mouse::Button::Right) {
                    // Right Click!
                }
            }
        }

        window.clear();
        window.display();
    }
}
