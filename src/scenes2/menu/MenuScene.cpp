#include "MenuScene.h"
#include "../../components/menu/Menu.h"

MenuScene::MenuScene(sf::RenderWindow& win, SceneManager& mgr)
    : window(win), sceneManager(mgr), menu(win) {}

void MenuScene::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::Resized)
        menu.updateLayout(window);
    else
        menu.handleEvent(event);
}

void MenuScene::update(float dt) {
    menu.update(dt);
}

void MenuScene::render(sf::RenderWindow& window) {
    sf::RectangleShape bg(sf::Vector2f(window.getSize().x, window.getSize().y));
    bg.setFillColor(sf::Color(25, 25, 35));
    window.draw(bg);
    menu.render(window);
}
