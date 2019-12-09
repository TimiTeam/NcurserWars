#include "SpaceObject.hpp"

SpaceObject::SpaceObject() : posX(0.f), posY(0.f), speed(0.5f), height(1), width(1)
{
    this->shape[0] = ".";
    this->live = 1;
}

SpaceObject::SpaceObject(float x, float y, float speed, std::string form) : posX(x), posY(y), speed(speed)
{
    this->height = 1;
    this->live = 1;
    this->width = form.length();
    this->shape[0] = form;
}

SpaceObject::~SpaceObject()
{
}

SpaceObject::SpaceObject(const SpaceObject& src)
{
    *this = src;
}

SpaceObject& SpaceObject::operator=(const SpaceObject& src)
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

float SpaceObject::getPosX() const
{
    return this->posX;
}
float SpaceObject::getPosY() const
{
    return this->posY;
}

void SpaceObject::moveUp()
{
    this->posY -= this->speed;
}
void SpaceObject::moveDown()
{
    this->posY += this->speed;
}
void SpaceObject::moveLeft()
{
    this->posX -= this->speed;
}
void SpaceObject::moveRight()
{
    this->posX += this->speed;
}

void SpaceObject::setPosX(float x)
{
    this->posX = x;
}

void SpaceObject::setPosY(float y)
{
    this->posY = y;
}

unsigned char SpaceObject::getHeight() const
{
    return this->height;
}
unsigned char SpaceObject::getWidth() const
{
    return this->width;
}

const std::string *SpaceObject::getShape() const
{
    return this->shape;
}

char SpaceObject::getLive() const
{
    return this->live;
}

void SpaceObject::setLive(int live)
{
    this->live = live;
}

bool SpaceObject::getInGame() const
{
    return this->inGame;
}

void SpaceObject::setSpeed(float speed)
{
    this->speed = speed;
}

float SpaceObject::getSpeed() const
{
    return this->speed;
}

void SpaceObject::setInGame(bool b)
{
    this->inGame = b;
}

void SpaceObject::printObject() const
{
    for (int i = 0; i < this->height; i++)
    {
        mvprintw((int)this->posY + i, (int)this->posX, this->shape[i].c_str());
    }
}

void SpaceObject::printCollisionEfferc(void) const
{
    mvprintw((int)this->posY,    (int)this->posX, "\\ | /");
    mvprintw((int)this->posY + 1, (int)this->posX, "- * -");
    mvprintw((int)this->posY + 2, (int)this->posX, "/ | \\");
    
}