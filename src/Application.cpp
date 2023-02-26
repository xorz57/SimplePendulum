#include "Application.hpp"

Application::Application() {
    mWindow.create(mMode, mTitle, sf::Style::Close, mSettings);
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
        switch (event.type) {
            case sf::Event::Closed:
                mWindow.close();
                break;
            case sf::Event::KeyPressed:
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    mWindow.close();
                }
                break;
            default:
                break;
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
