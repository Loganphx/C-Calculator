#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>

std::list<sf::CircleShape> entities = {};
sf::Vector2<float> mousePos;
int main()
{
    entities = {};

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

    const auto onMouseMoved = [&window](const sf::Event::MouseMoved& mouseMoved) {
        sf::Vector2<float> pos(mouseMoved.position.x, mouseMoved.position.y);
        std::cout << "Mouse Pos: " + std::to_string(mouseMoved.position.x) + " " + std::to_string(mouseMoved.position.y) + "\n";
        mousePos = pos;
        for (const sf::CircleShape& entity : entities) {
            sf::FloatRect boundingBox = entity.getGlobalBounds();
            std::cout << std::to_string(boundingBox.position.x) + " " + std::to_string(boundingBox.position.y) + "\n";

            if(boundingBox.contains(pos)) {
                std::cout << "Overlap Detected!";
            }
        }
    };

    const auto onFocusLost = [&window](const sf::Event::FocusLost&) {
        //myGame.pause();
        // Background fps is 30.
        window.setFramerateLimit(10);
    };

    const auto onFocusGained = [&window](const sf::Event::FocusGained&) {
        //myGame.resume();
        // Foreground fps is 60
        //Todo replace this with a config value
        window.setFramerateLimit(60);
    };

    clock_t current_ticks, delta_ticks;
    clock_t fps = 0;

    sf::Font font("pixel-arial-14.otf"); // Throws sf::Exception if an error occurs

    sf::Text fps_text(font); // a font is required to make a text object
    fps_text.setCharacterSize(24); // in pixels, not points!
    fps_text.setFillColor(sf::Color::Red);
    fps_text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    sf::CircleShape circle(50.f);
    circle.setFillColor(sf::Color(100, 250, 50));
    circle.setPosition({250.f, 250.f});
    entities.push_back(circle);

    sf::RectangleShape boundBox(circle.getGlobalBounds().size);
    boundBox.setPosition(circle.getGlobalBounds().position);
    boundBox.setFillColor(sf::Color::Transparent);
    boundBox.setOutlineColor(sf::Color::Red);
    boundBox.setOutlineThickness(2.f);

    sf::Text mouseText(font); // a font is required to make a text object
    mouseText.setCharacterSize(24); // in pixels, not points!
    mouseText.setFillColor(sf::Color::Red);
    mouseText.setStyle(sf::Text::Bold | sf::Text::Underlined);
    // inside the main loop, between window.clear() and window.display()

    while (window.isOpen())
    {
        window.handleEvents(onClose, onMousePressed, onKeyPressed, onFocusLost, onFocusGained, onMouseMoved);

//        while (const std::optional event = window.pollEvent())
//        {
////            if (event->is<sf::Event::Closed>())
////            {
////                window.close();
////            }
//        }

        current_ticks = clock();
        fps_text.setString(std::to_string(fps));
        mouseText.setString(std::to_string(static_cast<int>(mousePos.x)) + " " + std::to_string(static_cast<int>(mousePos.y)));
        mouseText.setPosition(mousePos);

        window.clear();

        window.draw(fps_text);
        window.draw(circle);
        window.draw(boundBox);
        window.draw(mouseText);

        window.display();

        delta_ticks = clock() - current_ticks; //the time, in ms, that took to render the scene
        if(delta_ticks > 0)
            fps = CLOCKS_PER_SEC / delta_ticks;
//        cout << fps << endl;
    }
}
