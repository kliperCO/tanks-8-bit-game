#include <SFML/Graphics.hpp>
#include <time.h>
#include "Tank.cpp"
#include "sandbox.h"

using namespace sf;

class Enemy :public Tank{
private:
    float speed = 0.01;
    int delay_rot = 300;
    int delay_shoot = 100;
    MyRect *rect;
    int counter = 0;
public:
    std::list<Bullet>*bullets_vector;
    std::list<Bullet>::iterator it;

    Enemy(String file, int x, int y, float width, float height, std::list<Bullet>*bullets) :Tank(file, x, y, width, height){
        srand(time(NULL));
        this->direction = getRandomDirection();
        bullets_vector = bullets;
        std::cout << "(" << width*3 << "; " << height*3 << ")\n";
        rect = new MyRect(x, y, x+width*3, y+height*3);
    }

    void updateRect() {
        rect->update(x,y,x+width*3,y+height*3);
    }

    void update(float time){
        switch (direction){
            case Tank::Right: dx = speed; dy = 0;
                current_frame += 1;
                if(current_frame >= 2) current_frame = 0;
                sprite.setTextureRect(IntRect(16*(int)current_frame, 16, 16, 16));
                break;
            case Tank::Left: dx = -speed; dy = 0;
                current_frame += 1;
                if(current_frame >= 2) current_frame = 0;
                sprite.setTextureRect(IntRect( 16*(int)current_frame, 48, 16, 16));
                break;
            case Tank::Down: dx = 0; dy = speed;
                current_frame += 1;
                if(current_frame >= 2) current_frame = 0;
                sprite.setTextureRect(IntRect( 16*(int)current_frame, 32, 16, 16));
                break;
            case Tank::Up: dx = 0; dy = -speed;
                current_frame += 1;
                if(current_frame >= 2) current_frame = 0;
                sprite.setTextureRect(IntRect( 16*(int)current_frame, 0, 16, 16));
                break;
        }

        for(it=bullets_vector->begin(); it!=bullets_vector->end();it++){
            if(rect->isColliding((*it).getRect())) {
                std::cout << ++counter << ": ПОПАЛ!\n";
            }
        }

        if(delay_rot==0) {
            delay_rot = 300;
            direction = getRandomDirection();
        }
        if(delay_shoot==0) {
            delay_shoot = 100;
            //bullets_vector->push_back(*new Bullet(x, y, 4, 4, direction));
        }
        if(delay_rot>0) delay_rot--;
        if(delay_shoot>0) delay_shoot--;

//        x += dx*time;
//        y += dy*time;

        updateRect();

        if(x<=0) x = 1;
        if(y<=0) y = 1;

        sprite.setPosition(x, y);
        interactionWithObstacles();
    }
    void interactionWithObstacles(){
        for(int i=y/24; i < (y+height)/24;i++){
            for(int j=x/24; j < (x+width)/24;j++) {
                if (TileMap[i][j] == '0' || TileMap[i][j] == 'b') {
                    if (dy > 0) {
                        y = i * 24 - height*3;
                        direction = getRandomDirection();
                    }
                    if (dy < 0) {
                        y = i * 24 + 24;
                        direction = getRandomDirection();
                    }
                    if (dx > 0) {
                        x = j * 24 - width*3;
                        direction = getRandomDirection();
                    }
                    if (dx < 0) {
                        x = j * 24 + 24;
                        direction = getRandomDirection();
                    }
                }
            }
        }
    }

    int getRandomDirection(){
        return rand()%4;
    }
};