#include "SimplePendulum.hpp"

#include <cmath>

SimplePendulum::SimplePendulum(const sf::Vector2f &position, float theta) : mTheta(theta) {
    mFrictionlessPivot.setOrigin(2.f, 2.f);
    mFrictionlessPivot.setPosition(position);
    mBob.setOrigin(20.f, 20.f);
}

void SimplePendulum::update(const sf::Time &stepTime, unsigned int steps) {
    for (unsigned int step = 0; step < steps; step++) {
        mAlpha = -mG / mL * std::sin(mTheta);
        mOmega += mAlpha * stepTime.asSeconds();
        mOmega *= mZeta;
        mTheta += mOmega * stepTime.asSeconds();
        mBob.setPosition(mFrictionlessPivot.getPosition() + mL * sf::Vector2f(std::sin(mTheta), std::cos(mTheta)));
        mMasslessRod[0].position = mFrictionlessPivot.getPosition();
        mMasslessRod[1].position = mBob.getPosition();
    }
}

void SimplePendulum::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(mMasslessRod, states);
    target.draw(mFrictionlessPivot, states);
    target.draw(mBob, states);
}
