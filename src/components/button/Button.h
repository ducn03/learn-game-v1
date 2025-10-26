#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Button {
public:
    Button(const sf::Font& font, const std::string& text, float x, float y);

    void render(sf::RenderWindow& window) const;
    void handleEvent(const sf::Event& event);
    void setSelected(bool selected);
    bool isSelected() const;
    std::string getText() const;

private:
    sf::Text label;
    bool selected = false;
};
