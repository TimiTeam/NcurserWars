#ifndef __BULLET_HPP
# define __BULLET_HPP
# include <iostream>
# include "SpaceObject.hpp"

class Bullet : public SpaceObject
{

private:
    bool active;

public:
    Bullet();
    Bullet(bool active, float x, float y, float speed);
    ~Bullet();

	Bullet(const Bullet& src);
	Bullet& operator=(const Bullet& src);
};

#endif
