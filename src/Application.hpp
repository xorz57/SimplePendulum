#pragma once

#include "SimplePendulum.hpp"

class Application {
public:
    Application();

    void Run();

private:
    void ProcessEvents();

    void Update(const sf::Time &deltaTime);

    void Render();

    sf::RenderWindow mWindow;
    sf::VideoMode mMode{800U, 600U};
    sf::String mTitle{"SimplePendulum"};
    sf::ContextSettings mSettings{0U, 0U, 8U};

    bool mRunning{true};

    SimplePendulum mSimplePendulum{{400.f, 0.f}, std::numbers::pi_v<float> / 4.f};
};
