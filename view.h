#include <SFML/Graphics.hpp>
using namespace sf;

static View view;
static View getPlayerCoordinateForView(float x, float y){
    view.setCenter(x+100,y);
    return view;
}