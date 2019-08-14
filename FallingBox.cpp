#include "FallingBox.hpp"

void FallingBox::draw(sf::RenderWindow& window) {
    centre->draw(window);
    peripheral->draw(window);
}

void FallingBox::update(float deltaTime) {
    centre->coord.f -= deltaTime / FALL_SPEED;
    peripheral->coord.f -= deltaTime / FALL_SPEED;
}

void FallingBox::handleInput(Input keypress) {
    // TODO: implement
}

