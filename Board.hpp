#pragma once

#include <memory>
#include <random>
#include <SFML/Graphics.hpp>

#include "Box.hpp"
#include "BehaviourObject.hpp"
#include "FallingBox.hpp"

class Board : public BehaviourObject, public RenderObject {
public:
    virtual void update(float deltaTime);
    virtual void handleInput(Input input);
    virtual void draw(sf::RenderWindow& window);

    Board();
    virtual ~Board();

private:
    static const int BOARD_HEIGHT = 13;
    static const int BOARD_WIDTH = 6;
    // Milliseconds per block
    static constexpr float FALL_SPEED = 700.;

    static Coord STARTING_MAIN[2];

    class BoxGrid : public Grid<BOARD_HEIGHT, BOARD_WIDTH, BPtr>, public RenderObject {
    public:
        void draw(sf::RenderWindow& window);
    } grid;

    FallingBox falling;

    void placeFalling();
    void explode();
    void generateFalling();

    class RandomGen {
    public:
        Colour colour();
        RandomGen();
    private:
        std::uniform_int_distribution<> uniform;
        std::random_device rd;
        std::mt19937 gen;
    } randomGen;
};
