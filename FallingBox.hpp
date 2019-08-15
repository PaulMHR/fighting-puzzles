#pragma once

#include "Utils.hpp"
#include "Box.hpp"
#include "RenderObject.hpp"
#include "BehaviourObject.hpp"

class FallingBox: public RenderObject, public BehaviourObject {
public:
    static constexpr float FALL_SPEED = 700.;


    void handleInput(Input keypress);
    void draw(sf::RenderWindow& window);
    void update(float deltaTime);
    int lowestPoint();

    void newBoxes(BPtr c, BPtr p) {
        centre = c;
        peripheral = p;
        direction = Orientation(UPWARD);
    }

    BPtr getCentre() { return centre; }
    BPtr getPeripheral() { return peripheral; }
private:
    BPtr centre;
    BPtr peripheral;
    Orientation direction;

    void rotateRight();
    void rotateLeft();
};

