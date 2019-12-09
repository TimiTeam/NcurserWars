#ifndef __ASTEROIDHORDE_HPP
#define __ASTEROIDHORDE_HPP
#include "Meteor.hpp"

class AsteroidHorde
{
protected:
	Meteor *meteors;
	int size;

public:
	AsteroidHorde();
	AsteroidHorde(int size);
	~AsteroidHorde();

	AsteroidHorde(const AsteroidHorde& src);
	void setRandomPositionToAll(int rangeFromX, int rangeToX, int randeFromY, int randeToY);
	void drawAllMeteors(int maxScreenX);
	Meteor *getMeteors();
	void setSpeedToAll(float speed);
	int getSize() const;
	AsteroidHorde& operator=(const AsteroidHorde& src);
};

#endif
