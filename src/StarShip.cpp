#include "StarShip.hpp"

const char StarShip::maxBullet = 50;

StarShip::StarShip()
{
    this->posX = 10.f;
    this->posY = 10.f;
    this->shape[0] = "   |\\-   ";
    this->shape[1] = "~>привет$>";
    this->shape[2] = "   |/-   ";
    this->height = 3;
    this->width = shape[2].length();
    this->speed = 1.8f;
    this->score = 0;
    this->live = 3;
    this->killAsteroids = 0;
    this->activeBullet = 0;
    this->inGame = true;
    for (int i = 0; i < 50; i++)
    {
        this->bullet[i] = Bullet(false, 0, 0, 2.f);
    }
}

StarShip::~StarShip()
{
}

StarShip::StarShip(const StarShip& src)
{
    *this = src;
}

StarShip& StarShip::operator=(const StarShip& src)
{
    if (this != &src)
    {
	    this->killAsteroids = src.killAsteroids;
	    this->activeBullet = src.activeBullet;
	    this->score = src.score;
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
        for (size_t i = 0; i < 50; i++)
        {
            this->bullet[i] = src.bullet[i];
        }
    }
    return *this;
}


int StarShip::getKillAsteroids() const
{
    return this->killAsteroids;
}

bool compare(SpaceObject bullet, SpaceObject meteor)
{
    bool x = 0;
    bool y = 0;
    int bX = bullet.getPosX();
    int bY = bullet.getPosY();
    int mX = meteor.getPosX();
    int mY = meteor.getPosY();
    if (bX <= mX && ((bX + bullet.getWidth()) >= mX))
        x = 1;
    if (bX >= mX && ((bX + bullet.getWidth()) <= mX + meteor.getWidth()))
        x = 1;
    if ((bX <= (mX + meteor.getWidth())) && ((bX + bullet.getWidth()) >= mX + meteor.getWidth()))
        x = 1;
    if (bY <= mY && ((bY + bullet.getHeight()) >= mY))
        y = 1;
    if (bY >= mY && ((bY + bullet.getHeight()) <= (mY + meteor.getHeight())))
        y = 1;
    if ((bY <= (mY + meteor.getHeight())) && ((bY + bullet.getHeight()) >= (mY + meteor.getHeight())))
        y = 1;
    if (x == 1 && y == 1)
        return (true);
    return (false);
}

void StarShip::bulletChangeState(int maxWinX, AsteroidHorde &as)
{
    int character;
    int charsTwo;
    int charsThree;
    for (int i = 0; i < 50; i++)
    {
        if (this->bullet[i].getInGame() == true)
        {
            if (this->bullet[i].getPosX() >= maxWinX - 5)
            {
                this->bullet[i].setInGame(false);
                this->activeBullet--;
                continue;
            }
            this->bullet[i].moveRight();
            character = mvinch(this->bullet[i].getPosY(), this->bullet[i].getPosX());
            charsTwo = mvinch(this->bullet[i].getPosY() + 1, this->bullet[i].getPosX());
            charsThree = mvinch(this->bullet[i].getPosY() + 2, this->bullet[i].getPosX());
            char symb = as.getMeteors()[0].getSymbol();
            if ((char)character == symb || (char)charsTwo == symb || (char)charsThree == symb)
            {
                Meteor *mt = as.getMeteors();
                for (int j = 0; j < as.getSize(); j++)
                {
                    if (compare(this->bullet[i], mt[j]))
                    {
                        mt[j].setInGame(false);
                        mt[j].setPosX(maxWinX + 10);
                        this->bullet[i].setInGame(false);
                        this->activeBullet--;
                        this->killAsteroids++;
                        break;
                    }
                }
            }
            if (this->bullet[i].getInGame())
            {
                this->bullet[i].printObject();
            }
        }
    }
}

void StarShip::shoot()
{
    if (this->activeBullet >= 50)
        return;
    for (int i = 0; i < 50; i++)
    {
        if (this->bullet[i].getInGame() == false)
        {
            this->bullet[i].setPosX(this->posX + this->width);
            this->bullet[i].setPosY(this->posY);
            this->bullet[i].setInGame(true);
            this->activeBullet++;
            break;
        }
    }
}

void StarShip::setKillAsteroids(int kkk)
{
    this->killAsteroids = kkk;
}

int StarShip::getScore() const
{
    return this->score;
}

void StarShip::setScore(int score)
{
    this->score = score;
}

void StarShip::resetStarShip()
{
    setKillAsteroids(0);
    setLive(3);
    setScore(0);
    setInGame(true);
}

bool StarShip::checkCollision(AsteroidHorde &as)
{
    int charact;
    char symbol;
    symbol = as.getMeteors()[0].getSymbol();
    bool run = true;
    for (int y = 0; y < this->height + 1 && run; y++)
    {
        for (int x = 0; x < this->width + 1 && run; x++)
        {
			charact = mvinch(this->posY + y, this->posX + x);
			if ((char)charact == symbol){
                this->live--;
                for (int i = 0; i < as.getSize(); i++){
                    if (compare(*this, as.getMeteors()[i]))
                    {
                        as.getMeteors()[i].setInGame(false);
                    }
                }
                run = false;
                if (this->live == 0)
                    this->inGame = false;
                break;
            }
        }
    }
    return (run == false);
}
