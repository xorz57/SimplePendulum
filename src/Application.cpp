#include "Application.hpp"

Application::Application() {
    mWindow.create(mMode, mTitle, sf::Style::Close, mSettings);
}

void Application::Run() {
    auto clock = sf::Clock();
    sf::Time accumulatorTime{sf::Time::Zero};
    sf::Time deltaTime{sf::seconds(1.f / 128.f)};
    while (mWindow.isOpen()) {
        accumulatorTime += clock.restart();
        while (accumulatorTime > deltaTime) {
            accumulatorTime -= deltaTime;
            ProcessEvents();
            if (mRunning) {
                Update(deltaTime);
            }
        }
        Render();
    }
}

void Application::ProcessEvents() {
    auto event = sf::Event();
    while (mWindow.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                mWindow.close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape) {
                    mRunning = !mRunning;
                }
                break;
            default:
                break;
        }
    }
}

void Application::Update(const sf::Time &deltaTime) {
    mSimplePendulum.Update(deltaTime);
}

void Application::Render() {
    mWindow.clear(sf::Color::Black);
    mSimplePendulum.Render(mWindow);
    mWindow.display();
}
