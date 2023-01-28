#include <SFML/Graphics.hpp>

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    auto window = sf::RenderWindow(sf::VideoMode(800, 600), "Simple Pendulum", sf::Style::Close, settings);
    window.setFramerateLimit(60);
    while (window.isOpen()) {
        auto event = sf::Event();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::Black);
        window.display();
    }
    return 0;
}
