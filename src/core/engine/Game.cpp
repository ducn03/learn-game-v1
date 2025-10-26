#include "Game.h"

#include <memory>

#include "scenes/menu/MenuScene.h"


Game::Game() {
    window.create(sf::VideoMode(800, 600), "Learn Game v1", sf::Style::Close);
    window.setVerticalSyncEnabled(true);
    sceneManager.changeScene(std::make_shared<MenuScene>(window, sceneManager));
}

void Game::run() {
    sf::Clock clock;
    while (isRunning && window.isOpen()) {
        float dt = clock.restart().asSeconds();
        processEvents();
        update(dt);
        render();
    }
}

void Game::processEvents() {
    sf::Event event{};
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        sceneManager.handleEvent(event);
    }
}

void Game::update(const float dt) {
    sceneManager.update(dt);
}

void Game::render() {
    window.clear(sf::Color::Black);
    sceneManager.render(window);
    window.display();
}
