#include <SFML/Graphics.hpp>
#include "sandbox.h"

using namespace sf;

class Player{
public:
    float x,y,width,height,dx,dy,speed=0;
    int direction = 0;
    String file;
    Image image;
    Texture texture;
    Sprite sprite;

    Player(String File, int X, int Y, float Width, float Height){
        file = File;
        width = Width, height = Height;
        image.loadFromFile("..//Image//"+file);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.scale(7,7);
        x=X;y=Y;
        sprite.setTextureRect(IntRect(width,height,width,height));
    }

    void update(float time){
        switch (direction){
            case 0: dx = speed; dy = 0;
                break;
            case 1: dx = -speed; dy = 0;
                break;
            case 2: dx = 0; dy = speed;
                break;
            case 3: dx = 0; dy = -speed;
                break;
        }

        x += dx*time;
        y += dy*time;

        speed = 0;
        sprite.setPosition(x, y);
    }

    void control(){

    }
};

int main(){

    RenderWindow window(VideoMode(640, 480), "Tanks! 8-bit Game");

    Image map_image;
    map_image.loadFromFile("..//Image//Sandbox.png");
    Texture map_texture;
    map_texture.loadFromImage(map_image);
    Sprite map_sprite;
    map_sprite.setTexture(map_texture);

    Player player("Player.png", 50, 25, 16, 16);

    Clock clock;
    float current_frame = 0 ;

    while (window.isOpen()){

        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 800;

        Event event;
        while (window.pollEvent(event)){
            if (event.type == Event::Closed) window.close();
        }

        if(Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)){
            player.direction=1; player.speed =0.1;
            current_frame += 0.005*time;
            if(current_frame > 2) current_frame -= 2;
            player.sprite.setTextureRect(IntRect(16*(int)current_frame, 16, 16, 16));
        }
        if(Keyboard::isKeyPressed(Keyboard::Right)){
            player.direction=0; player.speed =0.1;
            current_frame += 0.005*time;
            if(current_frame > 2) current_frame -= 2;
            player.sprite.setTextureRect(IntRect( 16*(int)current_frame, 48, 16, 16));
        }
        if(Keyboard::isKeyPressed(Keyboard::Up)){
            player.direction=3; player.speed =0.1;
            current_frame += 0.005*time;
            if(current_frame > 2) current_frame -= 2;
            player.sprite.setTextureRect(IntRect( 16*(int)current_frame, 0, 16, 16));
        }
        if(Keyboard::isKeyPressed(Keyboard::Down)){
            player.direction=2; player.speed =0.1;
            current_frame += 0.005*time;
            if(current_frame > 2) current_frame -= 2;
            player.sprite.setTextureRect(IntRect( 16*(int)current_frame, 32, 16, 16));
        }

        player.update(time);

        window.clear();

        for(int i = 0; i < HEIGHT_MAP; i++)
        for(int j = 0; j < WIDHT_MAP; j++){
            if(TileMap[i][j] == ' ') map_sprite.setTextureRect(IntRect(0, 0, 32, 32));
            if(TileMap[i][j] == 's') map_sprite.setTextureRect(IntRect(32, 0, 32, 32));
            if((TileMap[i][j] == '0')) map_sprite.setTextureRect(IntRect(64, 0, 32, 32));

            map_sprite.setPosition(j* 32, i * 32);

            window.draw(map_sprite);
        }

        window.draw(player.sprite);
        window.display();
    }
}