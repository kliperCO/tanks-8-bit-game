#include <SFML/Graphics.hpp>
#include "view.h"
#include "Tank.cpp"

using namespace sf;

class Player : public Tank{
public:
    Player(String file, int x, int y, float width, float height) :Tank(file, x, y, width, height){}
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
    }

    void interactionWithObstacles(){
        for(int i=y/8; i < (y+height)/8;i++){
            for(int j=x/8; j < (x+width)/8;j++) {
                if (TileMap[i][j] == '0' || TileMap[i][j] == 'b') {
                    if (dy > 0) {
                        y = i * 8 - height;
                    }
                    if (dy < 0) {
                        y = i * 8 + 8;
                    }
                    if (dx > 0) {
                        x = j * 8 - width;
                    }
                    if (dx < 0) {
                        x = j * 8 + 8;
                    }
                }
            }
        }
    }

    float getPlayerCoordinateX(){
        return x;
    }
    float getPlayerCoordinateY(){
        return y;
    }
};