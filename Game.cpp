#include "Game.hpp"

std::vector<ROPtr> Game::renderObjects;
std::vector<BOPtr> Game::behaviourObjects;

void Game::registerRenderObject(ROPtr&& o) {
    renderObjects.push_back(std::move(o));
}

void Game::registerBehaviourObject(BOPtr&& o) {
    behaviourObjects.push_back(std::move(o));
}

// void Game::handleInput() {
    //     switch (event.key) {
    //         case "ArrowLeft":
    //             input.set(Input.Left);
    //         case "ArrowRight":
    //             input.set(Input.Right);
    //         case "ArrowUp":
    //             input.set(Input.Drop);
    //         case "ArrowDown":
    //             input.set(Input.Down);
    //         case "Z":
    //             input.set(Input.RotateLeft);
    //         case "X":
    //             input.set(Input.RotateRight);
    //     }
//     Main.b.takeInput(input);

//     input.unset(Input.Left);
//     input.unset(Input.Right);
//     input.unset(Input.Down);
//     input.unset(Input.Drop);
//     input.unset(Input.RotateLeft);
//     input.unset(Input.RotateRight);
// }

void Game::update(float deltaTime) {
    // Main.handleInput();

    for (BOPtr& o : behaviourObjects) {
        o->update(deltaTime);
    }
}

void Game::draw(sf::RenderWindow& window) {
    
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    window.draw(shape);
    //console.debug("Drawing " + gameObjects.length + " items");
    // DON'T FORGET TO LOCK THIS WHEN SWITCHING TO MULTITHREADED
    for (const ROPtr& o : renderObjects) {
        o->draw(window);
    }
}
