#include "Menu2Scene.h"
#include "../../components/menu/Menu.h"
#include "data/repository/menu/MenuRepository.h"

Menu2Scene::Menu2Scene(sf::RenderWindow& win, SceneManager& mgr)
    : window(win), sceneManager(mgr), menu(win, MenuRepository::loadMenu()) {
    MenuData menuData = MenuRepository::loadMenu();
    menu = Menu(window, menuData);
}

void Menu2Scene::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::Resized)
        menu.updateLayout(window);
    else
        menu.handleEvent(event);
}

void Menu2Scene::update(const float dt) {
    menu.update(dt);
}

void Menu2Scene::render(sf::RenderWindow& window) {
    sf::RectangleShape bg(sf::Vector2f(window.getSize().x, window.getSize().y));
    bg.setFillColor(sf::Color(25, 25, 35));
    window.draw(bg);
    menu.render(window);
}
