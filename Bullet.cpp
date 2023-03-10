#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <list>
#include "sandbox.h"

using namespace sf;

class Bullet {
private:
    enum Direction {
        Left, Right, Up, Down
    };
    int direction;
    float speed = 0.5;
    float x, y, dx, dy, width, height;

    Image bullet_image;
    Texture bullet_texture;
    Sprite bullet_sprite;
public:
    bool isAlive = true;

    Bullet(int x, int y, float width, float height, int direction) {
        bullet_image.loadFromFile("..//Image//bullet_4.png");
        bullet_texture.loadFromImage(bullet_image);

        bullet_sprite.setTexture(bullet_texture);
        bullet_sprite.scale(1, 1);
        bullet_sprite.setTextureRect(IntRect(0, 0, width, height));

        this->direction = direction;
        this->x = x + (48 - width) / 2;
        this->y = y + (48 - height) / 2;

        switch (direction) {
            case Left:
                this->x -= 32;
                break;
            case Right:
                this->x += 32;
                break;
            case Up:
                this->y -= 32;
                break;
            case Down:
                this->y += 32;
                break;
        }

        this->width = width, this->height = height;
    }

    void update(float time) {
        switch (direction) {
            case Right:
                dx = speed;
                dy = 0;
                break;
            case Left:
                dx = -speed;
                dy = 0;
                break;
            case Down:
                dx = 0;
                dy = speed;
                break;
            case Up:
                dx = 0;
                dy = -speed;
                break;
        }

        x += dx * time;
        y += dy * time;

        bullet_sprite.setPosition(x, y);

        for (int i = y / 24; i < (y + height) / 24; i++) {
            for (int j = x / 24; j < (x + width) / 24; j++) {
                if (TileMap[i][j] == '0' || TileMap[i][j] == 'b') isAlive = false;
            }
        }
    }

    Sprite getSprite() {
        return bullet_sprite;
    }

    MyRect *getRect() {
        return new MyRect(x, y, x + width, y + height);
    }
};
