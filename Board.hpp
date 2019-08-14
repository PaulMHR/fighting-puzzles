#include <memory>
#include <SFML/Graphics.hpp>

#include "Box.hpp"
#include "BehaviourObject.hpp"

typedef std::shared_ptr<Box> BPtr;

class Board : public BehaviourObject, public RenderObject {
public:
    virtual void update(float deltaTime);
    virtual void handleInput(Input input);
    virtual void draw(sf::RenderWindow window);

    Board();
    virtual ~Board();

private:
    static const int BOARD_HEIGHT = 13;
    static const int BOARD_WIDTH = 6;
    // Milliseconds per block
    static constexpr float FALL_SPEED = 700.;

    class Grid {
    public:
        BPtr get(int row, int col);
        Grid();
        virtual ~Grid();

    private:
        BPtr grid[BOARD_HEIGHT * BOARD_WIDTH];
    } grid;

    BPtr falling[2]; //Primary in 0, secondary in 1

    void placeFalling();
    void explode();
    void generateFalling();
};
