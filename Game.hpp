
//import { Box } from './Box';
//import { EnumFlags } from './Utils';

#include <vector>
#include <SFML/Graphics.hpp>

#include "Input.hpp"
#include "GameObject.hpp"

class Game {
public:
    static void update(float deltaTime);
    static void draw(sf::RenderWindow& window);
    // static void registerGameObject(GOPtr o);
    static void handleInput();

private:
    static std::vector<GOPtr> gameObjects; //Should be GameObject
    //static Box b;
    //static input : EnumFlags<Input> = new EnumFlags<Input>();
};
