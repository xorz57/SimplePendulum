#pragma once

#include <SFML/Graphics.hpp>

#include <numbers>

class SimplePendulum : public sf::Drawable {
public:
    SimplePendulum(const sf::Vector2f &position, float theta);

    void update(const sf::Time &stepTime, unsigned int steps);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    sf::CircleShape mFrictionlessPivot{2.f};
    sf::CircleShape mBob{20.f};
    sf::VertexArray mMasslessRod{sf::LineStrip, 2};

    float mAlpha{0.f};
    float mOmega{0.f};
    float mTheta{std::numbers::pi_v<float> / 4.f};

    const float mZeta{0.999f};
    const float mG{100.f};
    const float mL{300.f};
};