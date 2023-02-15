#include "Pendulum.hpp"

#include <cmath>

Pendulum::Pendulum(const sf::Vector2f &position, float theta) : mTheta(theta) {
    mFrictionlessPivot.setOrigin(2.f, 2.f);
    mFrictionlessPivot.setPosition(position);
    mBob.setOrigin(20.f, 20.f);
}

void Pendulum::update(const sf::Time &deltaTime) {
    mAngularAcceleration = -mG / mL * std::sin(mTheta);
    mAngularVelocity += mAngularAcceleration;
    mAngularVelocity *= mZeta;
    mTheta += mAngularVelocity;
    mBob.setPosition(mFrictionlessPivot.getPosition() + mL * sf::Vector2f(std::sin(mTheta), std::cos(mTheta)));
    mMasslessRod[0].position = mFrictionlessPivot.getPosition();
    mMasslessRod[1].position = mBob.getPosition();
}

void Pendulum::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(mMasslessRod, states);
    target.draw(mFrictionlessPivot, states);
    target.draw(mBob, states);
}
