#include <SFML/Graphics.hpp>
#include "view.h"
#include "Tank.cpp"
#include "Bullet.cpp"
#include <iostream>
#include <vector>
#include <list>

using namespace sf;

class Player : public Tank{
private:
    int delay = 100;
public:
    std::list<Bullet>* bullets_vector;
    Player(String file, int x, int y, float width, float height, std::list<Bullet>*bullets) :Tank(file, x, y, width, height) {
        bullets_vector = bullets;
    }
    void update(float time){
        switch (direction){
            case Tank::Right: dx = speed; dy = 0;
                break;
            case Tank::Left: dx = -speed; dy = 0;
                break;
            case Tank::Down: dx = 0; dy = speed;
                break;
            case Tank::Up: dx = 0; dy = -speed;
                break;
        }

        x += dx*time;
        y += dy*time;

        if(x<=0) x = 1;
        if(y<=0) y = 1;

        speed = 0;
        sprite.setPosition(x, y);

        interactionWithObstacles();
        control();
        getPlayerCoordinateForView(getPlayerCoordinateX(),getPlayerCoordinateY());
    }

    void control(){
        if(Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)){
            direction=Left; speed = 0.1;
            current_frame += 1;
            if(current_frame >= 2) current_frame = 0;
            sprite.setTextureRect(IntRect(16*(int)current_frame, 16, 16, 16));
        }
        if(Keyboard::isKeyPressed(Keyboard::Right)){
            direction=Right; speed =0.1;
            current_frame += 1;
            if(current_frame >= 2) current_frame = 0;
            sprite.setTextureRect(IntRect( 16*(int)current_frame, 48, 16, 16));
        }
        if(Keyboard::isKeyPressed(Keyboard::Up)){
            direction=Up; speed =0.1;
            current_frame += 1;
            if(current_frame >= 2) current_frame = 0;
            sprite.setTextureRect(IntRect( 16*(int)current_frame, 0, 16, 16));
        }
        if(Keyboard::isKeyPressed(Keyboard::Down)){
            direction=Down; speed =0.1;
            current_frame += 1;
            if(current_frame >= 2) current_frame = 0;
            sprite.setTextureRect(IntRect( 16*(int)current_frame, 32, 16, 16));
        }
        if(Keyboard::isKeyPressed(Keyboard::Space)){
            if(delay==0) {
                delay = 100;
                bullets_vector->push_back(*new Bullet(getPlayerCoordinateX(), getPlayerCoordinateY(), 4, 4, direction));
            }
        }
    }

    float getPlayerCoordinateX(){
        return x;
    }
    float getPlayerCoordinateY(){
        return y;
    }
//    bool getShot(){
//        return shot;
//    }
//    bool setShot(bool shot){
//        this->shot=shot;
//    }
};