#include "MenuScene.h"

#include <iostream>

#include "../src/components/button/Button.h"

MenuScene::MenuScene(sf::RenderWindow& win, SceneManager& mgr)
    : window(win), sceneManager(mgr) {

    font.loadFromFile("C:/Windows/Fonts/arial.ttf");

    title.setFont(font);
    title.setString("Learn Game v1");
    title.setCharacterSize(40);
    title.setFillColor(sf::Color::Cyan);
    title.setPosition(150, 100);

    std::vector<std::string> games = {"Tetris", "Snake", "Flappy Bird", "Pong", "Exit"};
    float startY = 220.f;
    for (auto& name : games) {
        buttons.emplace_back(font, name, 200.f, startY);
        startY += 60.f;
    }
    buttons[selectedIndex].setSelected(true);
}

void MenuScene::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
            buttons[selectedIndex].setSelected(false);
            selectedIndex = (selectedIndex - 1 + buttons.size()) % buttons.size();
            buttons[selectedIndex].setSelected(true);
        } else if (event.key.code == sf::Keyboard::Down) {
            buttons[selectedIndex].setSelected(false);
            selectedIndex = (selectedIndex + 1) % buttons.size();
            buttons[selectedIndex].setSelected(true);
        } else if (event.key.code == sf::Keyboard::Enter) {
            std::cout << "✅ Selected: " << buttons[selectedIndex].getText() << "\n";
        }
    }
}

void MenuScene::render(sf::RenderWindow& window) {
    sf::RectangleShape bg(sf::Vector2f(window.getSize().x, window.getSize().y));
    bg.setFillColor(sf::Color(20, 20, 30));
    window.draw(bg);
    window.draw(title);

    for (auto& btn : buttons)
        btn.render(window);
}

void MenuScene::update(float dt) {

}

