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
    falling.update(deltaTime);
    if (falling.lowestPoint() < 0) {
        placeFalling();
    }
}

void Board::handleInput(Input input) {
    if (input != Input(Drop)) {
        falling.handleInput(input);
    } else {
        // TODO: make blocks drop full distance.
        // probably with looping and passing "down"s
    }
}

void Board::draw(sf::RenderWindow& window) {
    grid.draw(window);
    falling.draw(window);
}

void Board::placeFalling() {
    BPtr box = falling.getCentre();
    grid.set(std::move(box));
    box = falling.getPeripheral();
    grid.set(std::move(box));

    explode();
    generateFalling();
}

void Board::explode() {

}

void Board::generateFalling() {
    BPtr first_box = std::make_shared<Box>();
    first_box->coord = STARTING_MAIN[0];
    first_box->colour = randomGen.colour();

    BPtr second_box = std::make_shared<Box>();
    second_box->coord = STARTING_MAIN[1];
    second_box->colour = randomGen.colour();

    falling.newBoxes(first_box, second_box);
}
