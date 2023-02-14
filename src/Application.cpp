#include "Application.hpp"

#include <cmath>

Application::Application() {
    mWindow.create(mMode, mTitle, sf::Style::Close, mSettings);
    mWindow.setFramerateLimit(60U);

    mFrictionlessPivot.setOrigin(2.f, 2.f);
    mFrictionlessPivot.setPosition(400.f, 0.f);
    mBob.setOrigin(20.f, 20.f);
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

void Application::update(sf::Time deltaTime) {
    mAngularAcceleration = - mG / mL * std::sin(mTheta);
    mAngularVelocity += mAngularAcceleration;
    mAngularVelocity *= mZeta;
    mTheta += mAngularVelocity;
    mBob.setPosition(mFrictionlessPivot.getPosition() + mL * sf::Vector2f(std::sin(mTheta), std::cos(mTheta)));
}

void Application::render() {
    sf::VertexArray masslessRod(sf::LineStrip, 2);
    masslessRod[0].position = mFrictionlessPivot.getPosition();
    masslessRod[1].position = mBob.getPosition();

    mWindow.clear(sf::Color::Black);
    mWindow.draw(masslessRod);
    mWindow.draw(mFrictionlessPivot);
    mWindow.draw(mBob);
    mWindow.display();
}
