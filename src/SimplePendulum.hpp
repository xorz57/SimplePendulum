#pragma once

#include <SFML/Graphics.hpp>

#include <numbers>

class SimplePendulum {
public:
    SimplePendulum(const sf::Vector2f &position, float theta);

    void Update(const sf::Time &deltaTime);

    void Render(sf::RenderTarget &target) const;

private:
    sf::CircleShape mFrictionlessPivot{2.f};
    sf::CircleShape mBob{20.f};
    sf::VertexArray mMasslessRod{sf::LineStrip, 2};

    sf::Vector2f mPosition;

    float mOmega{0.f};
    float mTheta{std::numbers::pi_v<float> / 4.f};

    const float mZeta{0.999f};
    const float mGravitationalAcceleration{1000.f};
    const float mLength{300.f};
    const float mMass{20.f};
};