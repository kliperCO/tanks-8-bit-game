#include <SFML/Graphics.hpp>
#include "sandbox.h"

using namespace sf;

class Tank{
protected:
    float x,y;
    float width,height,dx,dy,speed=0, current_frame = 0;
    enum Direction{Left, Right, Up, Down};
    int direction;
    String file;
    Image image;
    Texture texture;
    Sprite sprite;
public:
    Tank(String file, int x, int y, float width, float height){
        this->file = file;
        this->width = width, this->height = height;
        image.loadFromFile("..//Image//"+file);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.scale(3,3);
        this->x=x; this->y=y;
        sprite.setTextureRect(IntRect(width,height,width,height));
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

    void destroy(){

    }

    Sprite getSprite(){
        return sprite;
    }
    int getDirection(){
        return direction;
    }
};