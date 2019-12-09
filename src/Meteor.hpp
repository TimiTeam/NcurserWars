#ifndef __METEOR_HPP
# define __METEOR_HPP
# include "SpaceObject.hpp"

class Meteor : public SpaceObject
{
protected:
    char symbol;
public:
    Meteor();
    Meteor(const Meteor& src);
	Meteor& operator=(const Meteor& src);
    Meteor(float x, float y, float speed, bool inGame);
    void setInGame(bool);
    const std::string* getShape() const;
    char  getSymbol() const;
    ~Meteor();
};

#endif
