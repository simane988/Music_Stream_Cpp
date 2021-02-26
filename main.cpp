#include <SFML/Graphics.hpp>
#include <iostream>
#include "src/code/Background.h"


const float HEIGHT = 1080;
const float WIDTH = 1920;

int main() {

    sf::RenderWindow sfmlWin(sf::VideoMode((int)WIDTH, (int)HEIGHT), "Hello World SFML Window", sf::Style::Fullscreen);
    sf::Font font;
    //You need to pass the font file location
    if (!font.loadFromFile(//Put the filename that identify the font file you want to load
     "/home/g3ck0/Code/C++/LoFiStream/src/Roboto-Regular.ttf")) {
        return -1;
    }

    float fps = 30;
    sf::Clock loop_timer;

    sf::Texture background_texture;
    sf::Sprite background_sprite;

    Background back("/home/g3ck0/Code/C++/LoFiStream/src/img/");

    while (sfmlWin.isOpen()) {

        back.getNextSprite(background_sprite, background_texture);

        sf::Event e{};
        while (sfmlWin.pollEvent(e)) {

            switch (e.type) {
                case sf::Event::EventType::Closed:
                    sfmlWin.close();
                    break;
            }
        }

        sf::Int32 frame_duration = loop_timer.getElapsedTime().asMilliseconds();
        sf::Int32 time_to_sleep = int(1000.f/fps) - frame_duration;
        if (time_to_sleep > 0) {
            sf::sleep(sf::milliseconds(time_to_sleep));
        }
        loop_timer.restart();

        sfmlWin.clear();
        sfmlWin.draw(background_sprite);
        sfmlWin.display();
    }
    return 0;
}

//int main(){
//    Background back("/home/g3ck0/Code/C++/LoFiStream/src/img/");
//    std::cout << back.getImgAmount();
//    back.getPaths();
//    return 0;
//}