#pragma once

#include "SimplePendulum.hpp"

class Application {
public:
    Application();

    void run();

private:
    void processEvents();

    void update(const sf::Time &stepTime, unsigned int steps = 1U);

    void render();

    sf::RenderWindow mWindow;
    sf::VideoMode mMode{800U, 600U};
    sf::String mTitle{"SimplePendulum"};
    sf::ContextSettings mSettings{0U, 0U, 8U};

    SimplePendulum mSimplePendulum{{400.f, 0.f}, std::numbers::pi_v<float> / 4.f};
};
