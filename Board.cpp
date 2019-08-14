#include "Board.hpp"

// Hopefully arrays of weak_ptr are default-initialized
Board::Board() {
    generateFalling();
}
Board::~Board() {}
Board::Grid::Grid() {}
Board::Grid::~Grid() {}

void Board::Grid::draw(sf::RenderWindow& window) {
    for (BPtr box : grid) {
        if (box != nullptr) {
            box->draw(window);
        }
    }
}

Board::RandomGen::RandomGen(): rd(), gen(rd()), uniform(0,3) {}

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
    //Place into board

    explode();
    generateFalling();
}

void Board::explode() {

}

void Board::generateFalling() {

}
