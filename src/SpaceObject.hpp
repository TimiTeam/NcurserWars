#ifndef __SPACEOBJECT_HPP
# define __SPACEOBJECT_HPP
# include <iostream>
# include <ncurses.h>

class SpaceObject
{
private:
protected:
	std::string 	shape[4];
	float       	posX;
	float       	posY;
	float       	speed;
	unsigned char	height;
	unsigned char	width;
	char 			live;
    bool 			inGame;
public:
	SpaceObject();
	SpaceObject(const SpaceObject& src);
	SpaceObject(float x, float y, float speed, std::string form);
	~SpaceObject();
	float getPosX() const;
	float getPosY() const;
	unsigned char getHeight() const;
	unsigned char getWidth() const;
	void setPosX(float);
	void setPosY(float);
	void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
	void setSpeed(float newSpeed);
    bool getInGame() const;
	void setInGame(bool);
	virtual const std::string* getShape() const;
	void printObject(void) const;
	void printCollisionEfferc(void) const;
	char getLive() const;
	float getSpeed() const;
	void setLive(int live);
	SpaceObject& operator=(const SpaceObject& src);
};

#endif
