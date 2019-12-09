#include "Meteor.hpp"

Meteor::Meteor()
{
    this->inGame = false;
    this->posX = 0;
    this->posY = 0;
    this->speed = 0.2f;
    this->shape[0] = " # " ;
    this->shape[1] = "###";
    this->shape[2] = " # ";
    this->height = 3;
    this->width = 3;
    this->symbol = '#';
}

Meteor::Meteor(float x, float y, float speed, bool inGame)
{
    this->inGame = inGame;
    this->posX = x;
    this->posY = y;
    this->speed = speed;
    this->shape[0] = " #" ;
    this->shape[1] = "###";
    this->shape[2] = " # ";
    this->height = 3;
    this->width = 3;
    this->symbol = '#';
}

Meteor::~Meteor()
{

}

Meteor::Meteor(const Meteor& src)
{
    *this = src;
}
Meteor& Meteor::operator=(const Meteor& src)
{
    if (this != &src)
    {
        this->symbol = src.symbol;
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

void Meteor::setInGame(bool b)
{
    this->inGame = b;
}

const std::string* Meteor::getShape() const
{
    return this->shape;
}

char Meteor::getSymbol() const
{
    return this->symbol;
}
