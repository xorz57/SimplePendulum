#pragma once

#include "Pendulum.hpp"

class Application {
public:
    Application();

    void run();

private:
    void processEvents();

    void update(const sf::Time &deltaTime);

    void render();

    sf::RenderWindow mWindow;
    sf::VideoMode mMode{800U, 600U};
    sf::String mTitle{"SimplePendulum"};
    sf::ContextSettings mSettings{0U, 0U, 8U};

    Pendulum mPendulum{{400.f, 0.f}, std::numbers::pi_v<float> / 4.f};
};
