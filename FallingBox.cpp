#include "FallingBox.hpp"

void FallingBox::draw(sf::RenderWindow& window) {
    centre->draw(window);
    peripheral->draw(window);
}

void FallingBox::update(float deltaTime) {
    centre->coord.f -= deltaTime / FALL_SPEED;
    peripheral->coord.f -= deltaTime / FALL_SPEED;
}

int FallingBox::lowestPoint() {
    int lowest_point = centre->coord.y;
    if (direction == Orientation(DOWNWARD)) {
        lowest_point = peripheral->coord.y;
    }
    return lowest_point;
}

void FallingBox::handleInput(Input keypress) {
    switch (keypress) {
        //TODO: add checks for collision
        case Drop:
            // should have been caught by Board!
            // Do we throw exception? Assert(false)?
            // Just let it pass by?
            break;
        case Left:
            centre->coord.x -= 1;
            peripheral->coord.x -= 1;
            break;
        case Right:
            centre->coord.x += 1;
            peripheral->coord.x += 1;
            break;
        case Down:
            centre->coord.y -= 1;
            peripheral->coord.y -= 1;
            break;
        case RotateRight:
            rotateRight();
            break;
        case RotateLeft:
            rotateLeft();
            break;
    }
}

void FallingBox::rotateRight() {
    switch (direction) {
        case UPWARD:
            direction = Orientation(RIGHTWARD);
            peripheral->coord.x += 1;
            peripheral->coord.y -= 1;
            break;
        case RIGHTWARD:
            direction = Orientation(DOWNWARD);
            peripheral->coord.x -= 1;
            peripheral->coord.y -= 1;
            break;
        case DOWNWARD:
            direction = Orientation(LEFTWARD);
            peripheral->coord.x -= 1;
            peripheral->coord.y += 1;
            break;
        case LEFTWARD:
            direction = Orientation(UPWARD);
            peripheral->coord.x += 1;
            peripheral->coord.y += 1;
            break;
    }
}

void FallingBox::rotateLeft() {
    switch (direction) {
        case UPWARD:
            direction = Orientation(LEFTWARD);
            peripheral->coord.x -= 1;
            peripheral->coord.y -= 1;
            break;
        case LEFTWARD:
            direction = Orientation(DOWNWARD);
            peripheral->coord.x += 1;
            peripheral->coord.y -= 1;
            break;
        case DOWNWARD:
            direction = Orientation(RIGHTWARD);
            peripheral->coord.x += 1;
            peripheral->coord.y += 1;
            break;
        case RIGHTWARD:
            direction = Orientation(UPWARD);
            peripheral->coord.x -= 1;
            peripheral->coord.y += 1;
            break;
    }
}

