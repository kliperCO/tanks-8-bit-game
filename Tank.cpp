#include <SFML/Graphics.hpp>
#include "sandbox.h"


using namespace sf;

class Tank{
protected:
    float x,y;
    float width,height,dx,dy,speed=0, current_frame = 0;
    enum Direction{Left, Right, Up, Down};
    Direction direction;
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
        sprite.scale(2,2);
        this->x=x; this->y=y;
        sprite.setTextureRect(IntRect(width,height,width,height));
    }

    virtual void update(float time){

    }

    Sprite getSprite(){
        return sprite;
    }
};