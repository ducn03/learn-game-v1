#include "Menu.h"
#include <iostream>

#include "core/logger/Logger.h"
#include "utils/TextUtils.h"

Menu::Menu(const sf::RenderWindow& window) {
    font.loadFromFile("../../resources/fonts/Roboto-Regular.ttf");

    title.setFont(font);

    const std::string rawText = u8"Đức học làm game - v1";
    title.setString(TextUtils::utf8(rawText));

    title.setCharacterSize(40);
    title.setFillColor(sf::Color::Cyan);
    title.setStyle(sf::Text::Bold);

    std::vector<std::string> games = {"Tetris", "Snake", "Flappy Bird", "Pong", "Exit"};
    for (const auto& name : games) {
        buttons.emplace_back(font, name, 0.f, 0.f);
    }

    buttons[selectedIndex].setHovered(true);
    updateLayout(window);
}

void Menu::updateLayout(const sf::RenderWindow& window) {
    const auto winSize = window.getSize();
    const float centerX = winSize.x / 2.f;

    // Title setup
    const auto bounds = title.getLocalBounds();
    title.setOrigin(bounds.width / 2.f, bounds.height / 2.f);

    // Giữ title ở khoảng 15% chiều cao cửa sổ
    const float titleY = winSize.y * 0.15f;
    title.setPosition(centerX, titleY);

    // Buttons setup
    const float totalHeight = buttons.size() * 80.f;  // 80 = khoảng cách giữa các nút
    float startY = titleY + 120.f;              // cách title một đoạn cố định

    if (const float availableSpace = winSize.y - startY - 60.f; availableSpace < totalHeight) {
        // Nếu màn hình nhỏ, giảm spacing giữa các nút
        float spacing = availableSpace / buttons.size();
        startY = titleY + 100.f;
        for (auto& btn : buttons) {
            btn.setPosition(centerX - 125.f, startY);
            startY += spacing;
        }
    } else {
        // Bình thường thì giữ spacing đẹp
        for (auto& btn : buttons) {
            btn.setPosition(centerX - 125.f, startY);
            startY += 80.f;
        }
    }
}


void Menu::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::Resized)
        return;

    if (event.type == sf::Event::MouseMoved) {
        sf::Vector2f pos(event.mouseMove.x, event.mouseMove.y);
        for (auto& btn : buttons)
            btn.setHovered(btn.isMouseOver(pos));
    }

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2f pos(event.mouseButton.x, event.mouseButton.y);
        for (auto& btn : buttons)
            btn.setActive(btn.isMouseOver(pos));
    }

    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2f pos(event.mouseButton.x, event.mouseButton.y);
        for (auto& btn : buttons) {
            if (btn.isMouseOver(pos)) {
                Logger::success("Clicked: " + btn.getText());
            }
            btn.setActive(false);
        }
    }
}

void Menu::update(const float dt) {
    for (auto& btn : buttons)
        btn.update(dt);
}

void Menu::render(sf::RenderWindow& window) const {
    window.draw(title);
    for (auto& btn : buttons)
        btn.render(window);
}

std::string Menu::getSelectedGame() const {
    return buttons[selectedIndex].getText();
}
