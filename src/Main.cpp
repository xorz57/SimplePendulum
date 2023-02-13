#include <SFML/Graphics.hpp>

#include <cmath>
#include <numbers>

int main() {
    auto window = sf::RenderWindow(sf::VideoMode(800U, 600U), sf::String("Simple Pendulum"), sf::Style::Close, sf::ContextSettings(0U, 0U, 8U));
    window.setFramerateLimit(60U);

    sf::CircleShape frictionlessPivot{2.f};
    frictionlessPivot.setOrigin(2.f, 2.f);
    frictionlessPivot.setPosition(400.f, 0.f);

    sf::CircleShape bob{20.f};
    bob.setOrigin(20.f, 20.f);

    sf::VertexArray masslessRod(sf::LineStrip, 2);

    float angularAcceleration{0.f};
    float angularVelocity{0.f};
    float theta{std::numbers::pi_v<float> / 4.f};

    const float zeta{0.999f};
    const float g{1.f};
    const float l{400.f};

    while (window.isOpen()) {
        auto event = sf::Event();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        angularAcceleration = - g / l * std::sin(theta);
        angularVelocity += angularAcceleration;
        angularVelocity *= zeta;
        theta += angularVelocity;
        bob.setPosition(frictionlessPivot.getPosition() + l * sf::Vector2f(std::sin(theta), std::cos(theta)));

        masslessRod[0].position = frictionlessPivot.getPosition();
        masslessRod[1].position = bob.getPosition();

        window.clear(sf::Color::Black);
        window.draw(masslessRod);
        window.draw(frictionlessPivot);
        window.draw(bob);
        window.display();
    }
    return 0;
}
