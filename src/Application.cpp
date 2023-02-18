#include "Application.hpp"

Application::Application() {
    mWindow.create(mMode, mTitle, sf::Style::Close, mSettings);
    mWindow.setFramerateLimit(60U);
}

void Application::run() {
    auto clock = sf::Clock();
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time stepTime{sf::seconds(1.f / 128.f)};
    while (mWindow.isOpen()) {
        sf::Time deltaTime = clock.restart();
        timeSinceLastUpdate += deltaTime;
        while (timeSinceLastUpdate > stepTime) {
            timeSinceLastUpdate -= stepTime;
            processEvents();
            update(stepTime, 4U);
        }
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

void Application::update(const sf::Time &stepTime, unsigned int steps) {
    mSimplePendulum.update(stepTime, steps);
}

void Application::render() {
    mWindow.clear(sf::Color::Black);
    mWindow.draw(mSimplePendulum);
    mWindow.display();
}
