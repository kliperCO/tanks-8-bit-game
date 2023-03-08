#include <SFML/Graphics.hpp>
#include "Player.cpp"
#include "Enemy.cpp"
#include <iostream>

int main(){
    RenderWindow window(VideoMode(640*2, 480*2), "Tanks! 8-bit Game");
    view.reset(FloatRect(0,0,640*2,480*2));

    Image map_image;
    map_image.loadFromFile("..//Image//borders-line.png");
    Texture map_texture;
    map_texture.loadFromImage(map_image);
    Sprite map_sprite;
    map_sprite.setTexture(map_texture);

    std::list<Bullet> bullets;
    std::list<Bullet>::iterator it;

    std::list<Enemy> enemies;
    std::list<Enemy>::iterator it_enemy;

    Player player("Player.png", 50, 25, 16, 16, &bullets);

    Clock clock;
    while (window.isOpen()){

        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 800;

        Event event;
        while (window.pollEvent(event)){
            if (event.type == Event::Closed) window.close();
        }

        player.update(time);
        if(enemies.empty()){
            enemies.push_back(*new Enemy("Enemy.png", 500, 100, 16, 16, &bullets));
        }

        for(it=bullets.begin(); it!=bullets.end();it++){
            if((*it).isAlive)(*it).update(time);
            else bullets.erase(it++);
        }

        for(it_enemy=enemies.begin(); it_enemy!=enemies.end();it_enemy++){
            if((*it_enemy).isAlive())(*it_enemy).update(time);
            else enemies.erase(it_enemy++);
        }

        window.setView(view);
        window.clear();

        for(int i = 0; i < HEIGHT_MAP; i++) {
            for (int j = 0; j < WIDHT_MAP; j++) {
                if (TileMap[i][j] == ' ') map_sprite.setTextureRect(IntRect(0, 0, 8, 8));
                if (TileMap[i][j] == 'w') map_sprite.setTextureRect(IntRect(32, 0, 8, 8));
                if (TileMap[i][j] == 'v') map_sprite.setTextureRect(IntRect(24, 0, 8, 8));
                if (TileMap[i][j] == 'b') map_sprite.setTextureRect(IntRect(8, 0, 8, 8));
                if (TileMap[i][j] == '0') map_sprite.setTextureRect(IntRect(16, 0, 8, 8));

                map_sprite.setScale(3,3);
                map_sprite.setPosition(j * 24, i * 24);

                window.draw(map_sprite);
            }
        }

        for(it=bullets.begin(); it!=bullets.end();it++){
            window.draw((*it).getSprite());
        }
        for(it_enemy=enemies.begin(); it_enemy!=enemies.end();it_enemy++){
            window.draw((*it_enemy).getSprite());
        }

        window.draw(player.getSprite());
        window.display();
    }
}