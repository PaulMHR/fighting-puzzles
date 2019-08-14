#include "Board.hpp"

Coord Board::STARTING_MAIN[2] = {{2, 12, 0}, {2, 13, 0}};

// Hopefully arrays of weak_ptr are default-initialized
Board::Board() {
    generateFalling();
}
Board::~Board() {}

void Board::BoxGrid::draw(sf::RenderWindow& window) {
    for (BPtr box : grid) {
        if (box != nullptr) {
            box->draw(window);
        }
    }
}

Board::RandomGen::RandomGen(): uniform(0,3), rd(), gen(rd()) {}

Colour Board::RandomGen::colour() {
    return (Colour)uniform(gen);
}

void Board::update(float deltaTime) {
    for (BPtr box : falling) {
        box->coord.f -= (deltaTime / FALL_SPEED);
    }
    if (falling[0]->coord.y < 0) {
        placeFalling();
    }
}

void Board::handleInput(Input input) {

}

void Board::draw(sf::RenderWindow& window) {
    grid.draw(window);
    for (BPtr box : falling) {
        box->draw(window);
    }
}

void Board::placeFalling() {
    for (BPtr box : falling) {
        grid.set(std::move(box));
    }

    explode();
    generateFalling();
}

void Board::explode() {

}

void Board::generateFalling() {
    for (int i = 0; i < 2; ++i) {
        falling[i] = std::make_shared<Box>();
        falling[i]->coord = STARTING_MAIN[i];
        falling[i]->colour = randomGen.colour();
    }
}
