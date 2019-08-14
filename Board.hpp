#pragma once

#include <memory>
#include <random>
#include <SFML/Graphics.hpp>

#include "Box.hpp"
#include "BehaviourObject.hpp"

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

    class Grid : public RenderObject {
    public:
        BPtr get(int row, int col);
        void draw(sf::RenderWindow& window);
        Grid();
        virtual ~Grid();
    private:
        BPtr grid[BOARD_HEIGHT * BOARD_WIDTH];
    } grid;

    BPtr falling[2]; //Primary in 0, secondary in 1

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
