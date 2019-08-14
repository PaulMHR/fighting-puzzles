#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Input.hpp"

const float MIN_FRAME_LENGTH = 16;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Puzzle Fight!");
    auto oldTime = std::chrono::steady_clock::now();
    auto newTime = oldTime;
    float deltaTime;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            // Add input
            if (event.type == sf::Event::KeyPressed)
            {
                // determine which key was pressed
                Input keypress;
                switch (event.key.code) {
                    case sf::Keyboard::Key::W: keypress = Input(Drop); break;
                    case sf::Keyboard::Key::A: keypress = Input(Left); break;
                    case sf::Keyboard::Key::S: keypress = Input(Down); break;
                    case sf::Keyboard::Key::D: keypress = Input(Right); break;
                    case sf::Keyboard::Key::E: keypress = Input(RotateRight); break;
                    case sf::Keyboard::Key::Q: keypress = Input(RotateLeft); break;
                    default:
                        continue;
                }
                // pass along to game
                Game::addInput(keypress);
            }
        }

        window.clear();

        newTime = std::chrono::steady_clock::now();
        deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(newTime - oldTime).count();
        if (deltaTime < MIN_FRAME_LENGTH) {
            auto sleep_time = std::chrono::milliseconds(static_cast<int>(MIN_FRAME_LENGTH - deltaTime));
            if (sleep_time > std::chrono::milliseconds(0)) {
                std::this_thread::sleep_for(sleep_time);
            }
            continue;
        }
        oldTime = newTime;
        Game::update(deltaTime);
        Game::draw(window);
        window.display();
    }

    return 0;
}
