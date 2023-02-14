#include "Pendulum.hpp"

#include <cmath>

Pendulum::Pendulum() {
    mFrictionlessPivot.setOrigin(2.f, 2.f);
    mFrictionlessPivot.setPosition(400.f, 0.f);
    mBob.setOrigin(20.f, 20.f);
}

void Pendulum::update(const sf::Time &deltaTime) {
    mAngularAcceleration = -mG / mL * std::sin(mTheta);
    mAngularVelocity += mAngularAcceleration;
    mAngularVelocity *= mZeta;
    mTheta += mAngularVelocity;
    mBob.setPosition(mFrictionlessPivot.getPosition() + mL * sf::Vector2f(std::sin(mTheta), std::cos(mTheta)));
}

void Pendulum::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    sf::VertexArray masslessRod(sf::LineStrip, 2);
    masslessRod[0].position = mFrictionlessPivot.getPosition();
    masslessRod[1].position = mBob.getPosition();
    target.draw(masslessRod, states);
    target.draw(mFrictionlessPivot, states);
    target.draw(mBob, states);
}