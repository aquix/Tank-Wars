#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SFML/Graphics.hpp>
#include "Collision.h"
#include <list>
#include <cmath>


using namespace sf;

double convertMeters(double meters);
double convertSpeed(double speed);
double sqr(double x);

class GameObject
{
protected:
    Vector2f position;
    Sprite sprite;
    double speed;
    double angle;
    bool checkCollision(GameObject *obj);
public:
    GameObject(Vector2f pos, Texture &tex, IntRect rect);

    Vector2f getPos();
    void setSpeed(double speed);
    void setAngle(double angle);
    Sprite getSprite();

    void draw(RenderWindow &window);
};



#endif // !GAMEOBJECT_H