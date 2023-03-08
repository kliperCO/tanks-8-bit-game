#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <list>
using namespace sf;

class Bullet{
private:
    enum Direction{Left, Right, Up, Down};
    int direction;
    float speed = 0.8;
    float x, y, dx, dy, width, height;

    Image bullet_image;
    Texture bullet_texture;
    Sprite bullet_sprite;
public:
    Bullet(int x, int y, float width, float height, int direction){
        bullet_image.loadFromFile("..//Image//bullet_4.png");
        bullet_texture.loadFromImage(bullet_image);

        std::cout << "(" << x << "; " << y << ")\n";

        bullet_sprite.setTexture(bullet_texture);
        bullet_sprite.scale(1,1);
        bullet_sprite.setTextureRect(IntRect(0,0,width,height));

        this->direction=direction;
        this->x=(16*3+x+width)/2; this->y=(16*3+y+height)/2;
        this->width = width, this->height = height;
    }

    void update(float time){
        switch (direction){
            case Right: dx = speed; dy = 0;
                break;
            case Left: dx = -speed; dy = 0;
                break;
            case Down: dx = 0; dy = speed;
                break;
            case Up: dx = 0; dy = -speed;
                break;
        }
        x += dx*time;
        y += dy*time;
        if(x<=0) x = 1;
        if(y<=0) y = 1;

        bullet_sprite.setPosition(x,y);

        //destroy();
    }

    Sprite getSprite(){
        return bullet_sprite;
    }

    void kill(){

    }
//    void destroy(std::list<Bullet>* bullets_vector){
//        for(int i=y/8; i < (y+height)/8;i++){
//            for(int j=x/8; j < (x+width)/8;j++) {
//                if (TileMap[i][j] == '0' || TileMap[i][j] == 'b') {
////                    for(int i = 0; i< bullets_vector.size())
//
//                }
//            }
//        }
//    }
};