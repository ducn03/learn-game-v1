#include "Game.h"

#include <memory>
#include "scenes/menu/MenuScene.h"

Game::Game() {
    // ✅ Cho phép resize & full window control
    window.create(sf::VideoMode(1280, 720), "Learn - How to make a Game v1", sf::Style::Default);

    // ✅ Bật VSync để tránh chớp / xé hình
    window.setVerticalSyncEnabled(true);

    // ✅ Load scene đầu tiên
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
        // ✅ Xử lý đóng cửa sổ
        if (event.type == sf::Event::Closed)
            window.close();

        // ✅ Xử lý resize để không bị co giãn sai tỉ lệ
        if (event.type == sf::Event::Resized) {
            sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
            window.setView(sf::View(visibleArea));
        }

        // ✅ Gửi event cho scene hiện tại
        sceneManager.handleEvent(event);
    }
}

void Game::update(const float dt) {
    sceneManager.update(dt);
}

void Game::render() {
    // ✅ Dùng màu nền nhẹ cho menu, đỡ đau mắt khi hover nhiều
    window.clear(sf::Color(30, 30, 40));
    sceneManager.render(window);
    window.display();
}
