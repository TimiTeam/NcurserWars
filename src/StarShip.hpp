#ifndef __STARSHIP_HPP
# define __STARSHIP_HPP
# include "SpaceObject.hpp"
# include "AsteroidHorde.hpp"
# include "Bullet.hpp"

class StarShip : public SpaceObject
{
static const char maxBullet;
private:
	Bullet      bullet[50];
	int         killAsteroids;
	char        activeBullet;
	int         score;
public:
	StarShip();
	StarShip(const StarShip& src);
	~StarShip();
	void shoot();
	void bulletChangeState(int maxWinX, AsteroidHorde& as);
	int getKillAsteroids() const;
	void setKillAsteroids(int kkk);
	bool checkCollision(AsteroidHorde &as);
	int getScore() const;
	void setScore(int score);
	void resetStarShip();
	StarShip& operator=(const StarShip& src);
};
#endif