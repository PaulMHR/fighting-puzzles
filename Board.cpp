#include "Board.hpp"

// Hopefully arrays of weak_ptr are default-initialized
Board::Board() {}
Board::~Board() {}
Board::Grid::Grid() {}
Board::Grid::~Grid() {}

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

void Board::draw(sf::RenderWindow window) {
    
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
