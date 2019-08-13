//import { GameObject } from './GameObject';
//import { Box } from './Box';
//import { Input } from './Input';
//import { EnumFlags } from './Utils';

#include "Game.h"

void Game::run() {
    //b = new Box(Main.ctx);
    //registerGameObject(b);

    // document.addEventListener('keydown', function (event) {
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
    // });

    lastFrameTimeMs = 1;
    draw(lastFrameTimeMs);
}

void Game::registerGameObject(int o) {
    gameObjects.push_back(o);
}

// void Game::handleInput() {
//     Main.b.takeInput(input);

//     input.unset(Input.Left);
//     input.unset(Input.Right);
//     input.unset(Input.Down);
//     input.unset(Input.Drop);
//     input.unset(Input.RotateLeft);
//     input.unset(Input.RotateRight);
// }

void Game::update(int delta) {
    // Main.handleInput();

    for (int o : gameObjects) {
        //o.update(delta);
    }
}

void Game::draw(int timestamp) {
    update(timestamp - lastFrameTimeMs);

    // Throttle the frame rate.
    if (timestamp < lastFrameTimeMs + (1000 / maxFPS)) {
        //window.requestAnimationFrame(Main.draw);
        return;
    }
    lastFrameTimeMs = timestamp;

    //console.debug("Drawing " + gameObjects.length + " items");
    // DON'T FORGET TO LOCK THIS WHEN SWITCHING TO MULTITHREADED
    for (const int o : gameObjects) {
        o;
    }
    
    //window.requestAnimationFrame(Main.draw);
}
