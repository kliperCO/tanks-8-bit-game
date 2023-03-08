#pragma once
#include <SFML/Graphics.hpp>
#include "Bullet.cpp"
#include "sandbox.h"

using namespace sf;

class Tank{
protected:
    float x,y;
    float width,height,dx,dy,speed=0, current_frame = 0;
    enum Direction{Left, Right, Up, Down};
    int direction;
    bool is_alive = true;

    String file;

    Image image;
    Texture texture;
    Sprite sprite;
public:
    Tank(String file, int x, int y, float width, float height){
        this->x=x; this->y=y;
        this->file = file;
        this->width = width, this->height = height;

        image.loadFromFile("..//Image//"+file);

        texture.loadFromImage(image);

        sprite.setTexture(texture);
        sprite.scale(3,3);
        sprite.setTextureRect(IntRect(width,height,width,height));
    }

    virtual void interactionWithObstacles(){
        for(int i=y/24; i < (y+height)/24;i++){
            for(int j=x/24; j < (x+width)/24;j++) {
                if (TileMap[i][j] == '0' || TileMap[i][j] == 'b') {
                    if (dy > 0) {
                        y = i * 24 - height*3;
                    }
                    if (dy < 0) {
                        y = i * 24 + 24;
                    }
                    if (dx > 0) {
                        x = j * 24 - width*3;
                    }
                    if (dx < 0) {
                        x = j * 24 + 24;
                    }
                }
            }
        }
    }

    void destroy(){

    }

    Sprite getSprite(){
        return sprite;
    }
    bool isAlive(){
        return is_alive;
    }
};