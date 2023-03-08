#include <SFML/Graphics.hpp>
using namespace sf;

static void setTexture(String file){
    Image image;
    image.loadFromFile("..//Image//" + file);
    Texture texture;
    texture.loadFromImage(image);
    Sprite map_sprite;
    map_sprite.setTexture(texture);
}