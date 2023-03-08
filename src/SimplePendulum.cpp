#include "SimplePendulum.hpp"

#include <cmath>

SimplePendulum::SimplePendulum(const sf::Vector2f &position, float theta) : mPosition(position), mTheta(theta) {
    mFrictionlessPivot.setOrigin(2.f, 2.f);
    mFrictionlessPivot.setPosition(mPosition);
    mBob.setOrigin(20.f, 20.f);
}

void SimplePendulum::update(const sf::Time &deltaTime) {
    const float force = -mMass * mGravitationalAcceleration * std::sin(mTheta);
    const float acceleration = force / mMass;
    const float angularAcceleration = acceleration / mLength;
    mOmega += angularAcceleration * deltaTime.asSeconds();
    mOmega *= mZeta;
    mTheta += mOmega * deltaTime.asSeconds();
    mBob.setPosition(mPosition + mLength * sf::Vector2f(std::sin(mTheta), std::cos(mTheta)));
    mMasslessRod[0].position = mPosition;
    mMasslessRod[1].position = mBob.getPosition();
}

void SimplePendulum::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(mMasslessRod, states);
    target.draw(mFrictionlessPivot, states);
    target.draw(mBob, states);
}
