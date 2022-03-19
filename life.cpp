
#include "life.hpp"

#include<iostream>
Life::~Life()  //destructor 
{
    cout<<"Life is destroyed"<<endl;
}

using namespace std;
int Life::getPlayerlife() //shows life of player 
{  
    return playerLifeNum;
}

void Life::operator--(int) //reduces player life on hit 
{
   
    Life::playerLifeNum--;
}
int Life::getEnemylife()    //shows enemy life 
{  
    return enemyLifeNum;
}

Life :: Life() :playerLifeNum(6), playerGetHit(0), enemyLifeNum(6), enemyGetHit(0) {}
void Life :: playerDraw(SDL_Renderer* gRenderer, SDL_Texture* assets_Lifelife) //draws player life accoding to hit 
{
    if (playerLifeNum == 1)
    {
	    Unit::srcRect = {49, 160, 152, 36};
	    Unit::moverRect = {20, 10, 160, 40};
    }
	else if (playerLifeNum == 2)
    {
	    Unit::srcRect = {49, 204, 152, 37};
	    Unit::moverRect = {20, 10, 160, 40};
    }

    else if (playerLifeNum == 3)
    {
	    Unit::srcRect = {49, 249, 152, 37};
	    Unit::moverRect = {20, 10, 160, 40};
    }

    else if (playerLifeNum == 4)
    {
	    Unit::srcRect = {49, 293, 152, 37};
	    Unit::moverRect = {20, 10, 160, 40};
    }

    else if (playerLifeNum == 5)
    {
	    Unit::srcRect = {49, 338, 152, 37};
	    Unit::moverRect = {20, 10, 160, 40};
    }

    else if (playerLifeNum == 6)
    {
	    Unit::srcRect = {49, 382, 152, 37};
	    Unit::moverRect = {20, 10, 160, 40};
    }
    Unit::draw(gRenderer, assets_Lifelife);
}

void Life :: enemyDraw(SDL_Renderer* gRenderer, SDL_Texture* assets_Lifelife) //draws enemy life according to the hit
{
    if (enemyLifeNum == 1)
    {
	    Unit::srcRect = {49, 160, 152, 36};
	    Unit::moverRect = {820, 10, 160, 40};
    }
	else if (enemyLifeNum == 2)
    {
	    Unit::srcRect = {49, 204, 152, 37};
	    Unit::moverRect = {820, 10, 160, 40};
    }

    else if (enemyLifeNum == 3)
    {
	    Unit::srcRect = {49, 249, 152, 37};
	    Unit::moverRect = {820, 10, 160, 40};
    }

    else if (enemyLifeNum == 4)
    {
	    Unit::srcRect = {49, 293, 152, 37};
	    Unit::moverRect = {820, 10, 160, 40};
    }

    else if (enemyLifeNum == 5)
    {
	    Unit::srcRect = {49, 338, 152, 37};
	    Unit::moverRect = {820, 10, 160, 40};
    }

    else if (enemyLifeNum == 6)
    {
	    Unit::srcRect = {49, 382, 152, 37};
	    Unit::moverRect = {820, 10, 160, 40};
    }
    Unit::draw(gRenderer, assets_Lifelife);
}



void Life:: updatePlayer(bool newlevel) //called on hit
{
    //SDL_RenderClear(gRenderer);
    if (newlevel)
    {
    playerLifeNum = 6;
    playerGetHit= 0; 
    }
}

void Life:: updateEnemy() //reduces life of enemy
{
   Life::enemyLifeNum --;
}

void Life:: updateEnemy( bool newLevel) //updates life  on change in level
{
    if (newLevel)
    {
       enemyLifeNum = 6;
       enemyGetHit = 0;
    }
   
        
}
