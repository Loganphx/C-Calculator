#include <SFML/Graphics.hpp>
#include <list>

std::list<sf::Transformable> entities = {};

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

//    const auto onMouseMoved = [&window](const sf::Event::MouseMoved& mouseMoved) {
//        for (int i = 0; i < entities.size(); ++i) {
//            if(mouseMoved.position.x)
//        }
//    };

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

        current_ticks = clock();

        window.clear();

        sf::Font font("pixel-arial-14.otf"); // Throws sf::Exception if an error occurs

        sf::Text text(font); // a font is required to make a text object
        text.setString(std::to_string(fps));
        text.setCharacterSize(24); // in pixels, not points!
        text.setFillColor(sf::Color::Red);
        text.setStyle(sf::Text::Bold | sf::Text::Underlined);


        // inside the main loop, between window.clear() and window.display()
        window.draw(text);

        sf::CircleShape shape(50.f);
        entities.push_back(shape);

        shape.setFillColor(sf::Color(100, 250, 50));
        shape.setPosition({250.f, 250.f});
        window.draw(shape);

        window.display();

        delta_ticks = clock() - current_ticks; //the time, in ms, that took to render the scene
        if(delta_ticks > 0)
            fps = CLOCKS_PER_SEC / delta_ticks;
//        cout << fps << endl;
    }
}
