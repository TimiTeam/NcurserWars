#include "Bullet.hpp"

Bullet::Bullet()
{
    this->posX = 0;
    this->posY = 0;
    this->speed = 1.5;
    this->shape[0] = "-- ";
	this->shape[1] = "   ";
    this->shape[2] = "-- ";
    this->active = false;
	this->height = 3;
	this->width = 3;
}

Bullet::Bullet(bool active, float x, float y, float speed)
{
    this->posX = x;
    this->posY = y;
    this->speed = speed;
    this->shape[0] = "-- ";
	this->shape[1] = "   ";
    this->shape[2] = "-- ";
	this->height = 3;
	this->width = 3;
    this->active = active;
}

Bullet::~Bullet()
{

}

Bullet::Bullet(const Bullet& src)
{
    *this = src;
}

Bullet& Bullet::operator=(const Bullet& src)
{
    if (this != &src)
    {
        this->posX  = src.posX;
        this->posY  = src.posY;
        this->speed = src.speed;
        this->height = src.height;
        this->live = src.live;
        this->width = src.width;
        this->height = src.height;
        this->inGame = src.inGame;
        for (size_t i = 0; i < this->height; i++)
        {
            this->shape[i] = src.shape[i];
        }
    }
    return *this;
}