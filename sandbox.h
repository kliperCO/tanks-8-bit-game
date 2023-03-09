#include <SFML/Graphics.hpp>
#ifndef SOME_STRING_H
#define SOME_STRING_H

static const int HEIGHT_MAP = 28;
static const int WIDHT_MAP = 40;

static sf::String TileMap[HEIGHT_MAP]={
        "0000000000000000000000000000000000000000",
        "0                                      0",
        "0                                      0",
        "0                                      0",
        "0                                      0",
        "0                                      0",
        "0                                      0",
        "0                                      0",
        "0              www                     0",
        "0              vvv                     0",
        "0                                      0",
        "0                                      0",
        "0        bbbbbb                        0",
        "0        bwwvwb                        0",
        "0        bvwvwb                        0",
        "0        bbbbbb                        0",
        "0                                      0",
        "0                                      0",
        "0                   bbbbbb             0",
        "0                   b    b             0",
        "0                                      0",
        "0                                      0",
        "0                                      0",
        "0             wwvwvw                   0",
        "0             wvwvvv                   0",
        "0                                      0",
        "0                                      0",
        "0000000000000000000000000000000000000000",

};


struct MyRect{
public:
    int x1, y1, x2, y2;

    MyRect(int x1, int y1, int x2, int y2) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }

    void update(int x1, int y1, int x2, int y2) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }

    bool isColliding(MyRect* bullet){
        if(x1 < bullet->x2 && x2 > bullet->x1 && y1 < bullet->y2 && y2 > bullet->y1) return true;
        return false;
    }
};
#endif