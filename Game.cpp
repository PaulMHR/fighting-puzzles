#include <iostream>

#include "Game.hpp"
#include "Box.hpp"
#include "Board.hpp"

std::vector<ROPtr> Game::renderObjects;
std::vector<BOPtr> Game::behaviourObjects;
std::queue<Input> Game::inputQueue;

void Game::registerRenderObject(ROPtr o) {
    renderObjects.push_back(std::move(o));
}

void Game::registerBehaviourObject(BOPtr o) {
    behaviourObjects.push_back(std::move(o));
}

void Game::handleInput() {
    while (!inputQueue.empty()) {
        Input keypress = inputQueue.front();
        inputQueue.pop();
        // process keypress
    }
}

void Game::addInput(Input keypress) {
    inputQueue.push(keypress);
}

void Game::update(float deltaTime) {
    Game::handleInput();

    for (BOPtr& o : behaviourObjects) {
        o->update(deltaTime);
    }
}

void Game::draw(sf::RenderWindow& window) {
    // DON'T FORGET TO LOCK THIS WHEN SWITCHING TO MULTITHREADED
    for (const ROPtr& o : renderObjects) {
        o->draw(window);
    }
}

void Game::start() {
    auto board = std::make_shared<Board>();
    registerBehaviourObject(board);
    registerRenderObject(board);
}
