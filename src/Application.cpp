#include "Application.hpp"

Application::Application() {
    mWindow.create(mMode, mTitle, sf::Style::Close, mSettings);
    mWindow.setFramerateLimit(60U);
}

void Application::run() {
    auto clock = sf::Clock();
    while (mWindow.isOpen()) {
        sf::Time deltaTime = clock.restart();
        processEvents();
        update(deltaTime);
        render();
    }
}

void Application::processEvents() {
    auto event = sf::Event();
    while (mWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            mWindow.close();
        }
    }
}

void Application::update(const sf::Time &deltaTime) {
    mSimplePendulum.update(deltaTime);
}

void Application::render() {
    mWindow.clear(sf::Color::Black);
    mWindow.draw(mSimplePendulum);
    mWindow.display();
}
