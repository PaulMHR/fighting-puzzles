#pragma once

#include <vector>
#include <queue>
#include <SFML/Graphics.hpp>

#include "Input.hpp"
#include "RenderObject.hpp"
#include "BehaviourObject.hpp"

class Game {
public:
    static void start();
    static void update(float deltaTime);
    static void draw(sf::RenderWindow& window);
    static void registerRenderObject(ROPtr o);
    static void registerBehaviourObject(BOPtr o);
    static void handleInput();
    static void addInput(Input keypress);

private:
    static std::vector<ROPtr> renderObjects;
    static std::vector<BOPtr> behaviourObjects;
    static std::queue<Input> inputQueue;
    //static Box b;
    //static input : EnumFlags<Input> = new EnumFlags<Input>();
};
