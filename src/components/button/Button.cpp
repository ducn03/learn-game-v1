#include "Button.h"

Button::Button(const sf::Font& font, const std::string& text, float x, float y) {
    label.setFont(font);
    label.setString(text);
    label.setCharacterSize(32);
    label.setPosition(x, y);
    label.setFillColor(sf::Color(180, 180, 180));
}

void Button::render(sf::RenderWindow& window) const {
    window.draw(label);
}

void Button::setSelected(bool sel) {
    selected = sel;
    label.setFillColor(sel ? sf::Color::Yellow : sf::Color(180, 180, 180));
}

bool Button::isSelected() const { return selected; }
std::string Button::getText() const { return label.getString(); }
