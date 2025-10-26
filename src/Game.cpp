#include "../include/Game.h"

#include "SFML/Window/Event.hpp"
#include "SFML/Window/Keyboard.hpp"

Game::Game() 
    : window(sf::VideoMode(800, 600), "My Game Engine"),
      playerSpeed(200.0f),
      running(true) {
    
    window.setFramerateLimit(60);
    
    // Setup player
    player.setSize(sf::Vector2f(50.0f, 50.0f));
    player.setFillColor(sf::Color::Green);
    player.setPosition(375.0f, 275.0f);
}

void Game::run() {
    while (window.isOpen() && running) {
        float dt = clock.restart().asSeconds();
        
        processEvents();
        update(dt);
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }
    }
}

void Game::handleInput(float dt) {
    float moveX = 0.0f;
    float moveY = 0.0f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) moveY -= playerSpeed * dt;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) moveY += playerSpeed * dt;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) moveX -= playerSpeed * dt;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) moveX += playerSpeed * dt;

    player.move(moveX, moveY);
}

void Game::update(float dt) {
    handleInput(dt);
    
    // Keep player in bounds
    sf::Vector2f pos = player.getPosition();
    pos.x = std::max(0.0f, std::min(pos.x, 750.0f));
    pos.y = std::max(0.0f, std::min(pos.y, 550.0f));
    player.setPosition(pos);
}

void Game::render() {
    window.clear(sf::Color(20, 20, 30));
    window.draw(player);
    window.display();
}