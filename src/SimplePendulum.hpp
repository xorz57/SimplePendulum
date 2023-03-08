#pragma once

#include <SFML/Graphics.hpp>

#include <numbers>

class SimplePendulum : public sf::Drawable {
public:
    SimplePendulum(const sf::Vector2f &position, float theta);

    void update(const sf::Time &deltaTime);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    sf::CircleShape mFrictionlessPivot{2.f};
    sf::CircleShape mBob{20.f};
    sf::VertexArray mMasslessRod{sf::LineStrip, 2};

    float mOmega{0.f};

    sf::Vector2f mPosition;
    float mTheta{std::numbers::pi_v<float> / 4.f};

    const float mZeta{0.999f};
    const float mGravitationalAcceleration{1000.f};
    const float mLength{300.f};
    const float mMass{20.f};
};