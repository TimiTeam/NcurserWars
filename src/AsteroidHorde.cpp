#include "AsteroidHorde.hpp"

AsteroidHorde::AsteroidHorde()
{
	this->size = 0;
	this->meteors = new Meteor[this->size];
	for (int i = 0; i < this->size; i++)
	{
		this->meteors[i] = Meteor();
	}
}

AsteroidHorde::AsteroidHorde(int size)
{
	this->size = size;
	this->meteors = new Meteor[this->size];
	for (int i = 0; i < this->size; i++)
	{
		this->meteors[i] = Meteor();
	}
}

void AsteroidHorde::setRandomPositionToAll(int rangeFromX, int rangeToX, int rangeFromY, int rangeToY)
{
	for (int i = 0; i < this->size; i++)
	{
		this->meteors[i].setPosX((rand() * time(NULL) % rangeToX + rangeFromX));
		this->meteors[i].setPosY((rand() * time(NULL) % rangeToY + rangeFromY));
	}
}

void AsteroidHorde::drawAllMeteors(int maxScreenX)
{
	for (int i = 0; i < this->size; i++)
	{
		int x = this->meteors[i].getPosX();
		bool in = this->meteors[i].getInGame();

		if (in && x < maxScreenX - 4)
		{
			this->meteors[i].printObject();
		}
		if (x <= 0 || !in)
		{
			this->meteors[i].setPosX(((rand() + time(NULL) + x) % maxScreenX + maxScreenX));
			this->meteors[i].setInGame(true);
		}
		this->meteors[i].moveLeft();
	}
}

AsteroidHorde::~AsteroidHorde()
{
	delete [] this->meteors;
}

Meteor *AsteroidHorde::getMeteors()
{
    return this->meteors;
}
int AsteroidHorde::getSize() const
{
    return this->size;
}

void AsteroidHorde::setSpeedToAll(float speed)
{
    for (int i = 0; i < this->size; i++)
	{
		this->meteors[i].setSpeed(speed);
	}   
}

AsteroidHorde::AsteroidHorde(const AsteroidHorde& src)
{
    *this = src;
}
AsteroidHorde& AsteroidHorde::operator=(const AsteroidHorde& src)
{
    if (this != &src)
    {
		this->size = src.size;
		this->meteors = src.meteors;
    }
    return *this;
}