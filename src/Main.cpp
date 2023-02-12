#include <SFML/Graphics.hpp>

#include <cmath>
#include <numbers>

int main() {
    auto window = sf::RenderWindow(sf::VideoMode(800, 600), "Simple Pendulum", sf::Style::Close);
    window.setFramerateLimit(60);

    sf::CircleShape frictionlessPivot{2};
    frictionlessPivot.setOrigin(2, 2);
    frictionlessPivot.setPosition(400, 0);

    sf::CircleShape bob{20};
    bob.setOrigin(20, 20);

    sf::VertexArray masslessRod(sf::LineStrip, 2);

    float angularAcceleration{0};
    float angularVelocity{0};
    float theta{std::numbers::pi_v<float> / 4};

    const float zeta{0.999f};
    const float g{1};
    const float l{400};

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
