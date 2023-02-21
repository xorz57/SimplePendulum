#include "Application.hpp"

Application::Application() {
    mWindow.create(mMode, mTitle, sf::Style::Close, mSettings);
    mWindow.setFramerateLimit(60U);
}

void Application::run() {
    auto clock = sf::Clock();
    sf::Time accumulatorTime = sf::Time::Zero;
    sf::Time deltaTime{sf::seconds(1.f / 128.f)};
    while (mWindow.isOpen()) {
        accumulatorTime += clock.restart();
        while (accumulatorTime > deltaTime) {
            accumulatorTime -= deltaTime;
            processEvents();
            update(deltaTime);
        }
        render();
    }
}

void Application::processEvents() {
    auto event = sf::Event();
    while (mWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
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
