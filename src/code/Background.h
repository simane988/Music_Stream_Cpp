//
// Created by g3ck0 on 26.02.2021.
//

#ifndef LOFISTREAM_BACKGROUND_H
#define LOFISTREAM_BACKGROUND_H

#include <iostream>
#include <vector>
#include <filesystem>
#include <algorithm>
#include <SFML/Graphics.hpp>

class Background {
private:
    int imgAmount = 0;
    int curPos = 0;
    const float HEIGHT = 1080;
    const float WIDTH = 1920;
    sf::Vector2u size;
    std::vector<std::string> imgPaths;

public:
    explicit Background(const std::string& initialPath);
    void getNextSprite(sf::Sprite &sprite, sf::Texture &texture);
};


#endif //LOFISTREAM_BACKGROUND_H
