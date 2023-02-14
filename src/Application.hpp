#pragma once

#include <SFML/Graphics.hpp>

#include <numbers>

class Application {
public:
    Application();

    void run();

private:
    void processEvents();

    void update(sf::Time deltaTime);

    void render();

    sf::RenderWindow mWindow;
    sf::VideoMode mMode{800U, 600U};
    sf::String mTitle{"SimplePendulum"};
    sf::ContextSettings mSettings{0U, 0U, 8U};

    sf::CircleShape mFrictionlessPivot{2.f};
    sf::CircleShape mBob{20.f};

    float mAngularAcceleration{0.f};
    float mAngularVelocity{0.f};
    float mTheta{std::numbers::pi_v<float> / 4.f};

    const float mZeta{0.999f};
    const float mG{1.f};
    const float mL{400.f};
};
