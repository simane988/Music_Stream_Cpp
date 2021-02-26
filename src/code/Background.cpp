//
// Created by g3ck0 on 26.02.2021.
//

#include "Background.h"

Background::Background(const std::string& initialPath) {
    for (const std::filesystem::directory_entry& p : std::filesystem::directory_iterator(initialPath)){
        imgPaths.push_back(p.path());
        imgAmount++;
    }
    imgAmount--;
    std::sort(imgPaths.begin(), imgPaths.end());

    sf::Texture textureTmp;
    textureTmp.loadFromFile(imgPaths[0]);
    size = textureTmp.getSize();
}

void Background::getNextSprite(sf::Sprite &sprite, sf::Texture &texture) {
    if(curPos == imgAmount) {
        curPos = 0;
    }
    texture.loadFromFile(imgPaths[curPos++]);

    sprite.setTexture(texture);
    sprite.setScale(WIDTH/size.x, HEIGHT/size.y);
//    spriteTmp.setOrigin(0, 0);
}

