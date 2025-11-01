#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "../button/Button.h"
#include "data/domain/menu/MenuData.h"

class Menu {
public:
    void update(float dt);
    void render(sf::RenderWindow& window) const;
    void handleEvent(const sf::Event& event);
    std::string getSelectedGame() const;
    Menu(const sf::RenderWindow &window, const MenuData &menuData);

    explicit Menu(const sf::RenderWindow & win);

    void updateLayout(const sf::RenderWindow& window);

private:
    sf::Font font;
    sf::Text title;
    std::vector<Button> buttons;
    int selectedIndex = 0;
};
