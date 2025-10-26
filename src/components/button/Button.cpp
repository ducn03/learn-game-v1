#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Window/Event.hpp"

class Button {
public:
    sf::RectangleShape shape;
    sf::Text text;
    sf::Color normalColor;
    sf::Color hoverColor;
    sf::Color activeColor;
    bool isHovered = false;
    bool isPressed = false;

    Button(const sf::Vector2f& size, const sf::Font& font, const std::string& label) {
        shape.setSize(size);
        normalColor = sf::Color(100, 100, 250);
        hoverColor = sf::Color(150, 150, 250);
        activeColor = sf::Color(80, 80, 200);
        shape.setFillColor(normalColor);

        text.setFont(font);
        text.setString(label);
        text.setCharacterSize(28);
        text.setFillColor(sf::Color::White);
    }

    void setPosition(const sf::Vector2f& pos) {
        shape.setPosition(pos);
        text.setPosition(pos.x + 15, pos.y + 10);
    }

    void update(const sf::Vector2f& mousePos) {
        isHovered = shape.getGlobalBounds().contains(mousePos);
        if (isHovered) {
            shape.setFillColor(hoverColor);
        } else {
            shape.setFillColor(normalColor);
        }
    }

    bool handleClick(const sf::Event& event, const sf::Vector2f& mousePos) {
        if (isHovered && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            shape.setFillColor(activeColor);
            isPressed = true;
            return true;
        }
        if (event.type == sf::Event::MouseButtonReleased && isPressed) {
            isPressed = false;
            shape.setFillColor(isHovered ? hoverColor : normalColor);
        }
        return false;
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
        window.draw(text);
    }
};
