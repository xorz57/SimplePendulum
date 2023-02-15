#pragma once

#include <SFML/Graphics.hpp>

#include <numbers>

class Pendulum : public sf::Drawable {
public:
    Pendulum(const sf::Vector2f &position, float theta);

    void update(const sf::Time &deltaTime);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    sf::CircleShape mFrictionlessPivot{2.f};
    sf::CircleShape mBob{20.f};
    sf::VertexArray mMasslessRod{sf::LineStrip, 2};

    float mAngularAcceleration{0.f};
    float mAngularVelocity{0.f};
    float mTheta{std::numbers::pi_v<float> / 4.f};

    const float mZeta{0.999f};
    const float mG{1.f};
    const float mL{400.f};
};