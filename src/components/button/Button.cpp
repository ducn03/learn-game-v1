#pragma once
#include <SFML/Graphics.hpp>
#include <string>

#include "utils/TextUtils.h"

class Button {
private:
    sf::RectangleShape shape;
    sf::Text text;

    sf::Color normalColor{70, 70, 70};
    sf::Color hoverColor{100, 100, 160};
    sf::Color activeColor{50, 180, 90};
    sf::Color textColor{sf::Color::White};

    bool hovered = false;
    bool active = false;

public:
    Button(const sf::Font& sharedFont, const std::string& label, float x, float y) {
        // Khung nút
        shape.setSize({250.f, 50.f});
        shape.setPosition(x, y);
        shape.setFillColor(normalColor);
        shape.setOutlineThickness(2);
        shape.setOutlineColor(sf::Color::Black);

        // Text (UTF-8 -> SFML UTF-32)
        text.setFont(sharedFont);
        text.setString(TextUtils::utf8(label));
        text.setCharacterSize(28);
        text.setFillColor(textColor);

        // Căn giữa text
        sf::FloatRect bounds = text.getLocalBounds();
        text.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
        text.setPosition(x + shape.getSize().x / 2.f, y + shape.getSize().y / 2.f);
    }

    void setHovered(bool value) { hovered = value; }
    void setActive(bool value) { active = value; }

    bool isMouseOver(const sf::Vector2f& mousePos) const {
        return shape.getGlobalBounds().contains(mousePos);
    }

    void update(float) {
        if (active)
            shape.setFillColor(activeColor);
        else if (hovered)
            shape.setFillColor(hoverColor);
        else
            shape.setFillColor(normalColor);
    }

    void render(sf::RenderWindow& window) const {
        window.draw(shape);
        window.draw(text);
    }

    std::string getText() const {
        std::string sfStr = text.getString();
        return sfStr;
    }

    void setPosition(float x, float y) {
        shape.setPosition(x, y);
        text.setPosition(x + shape.getSize().x / 2.f, y + shape.getSize().y / 2.f);
    }

    sf::FloatRect getBounds() const { return shape.getGlobalBounds(); }
};
