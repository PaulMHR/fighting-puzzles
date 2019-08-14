#include "Game.hpp"
#include "Box.hpp"

std::vector<ROPtr> Game::renderObjects;
std::vector<BOPtr> Game::behaviourObjects;
std::queue<Input> Game::inputQueue;

void Game::registerRenderObject(ROPtr&& o) {
    renderObjects.push_back(std::move(o));
}

void Game::registerBehaviourObject(BOPtr&& o) {
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

    Box test_box = Box();
    test_box.draw(window);
    // sf::CircleShape shape(100.f);
    // shape.setFillColor(sf::Color::Green);
    // window.draw(shape);
    // console.debug("Drawing " + gameObjects.length + " items");
    // DON'T FORGET TO LOCK THIS WHEN SWITCHING TO MULTITHREADED
    for (const ROPtr& o : renderObjects) {
        o->draw(window);
    }
}
