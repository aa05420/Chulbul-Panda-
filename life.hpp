#pragma once 
#include "unit.hpp"

#include<iostream>
using namespace std;
/** \brief Keep tracks of player and enemy's life and displays them on the screen */
class Life: public Unit
{   /**
    *\param enemyLifeNum  integer value to store the number of life enemy has
    *\param playerLifeNum integer value to store the number of life player has
    *\param enemyGetHit   integer value keeps track of the number of times enemy has been hit
    *\param playerGetHit  integer value keeps track of the number of times player has been hit
    */
    int enemyLifeNum;
    int playerLifeNum;
    int enemyGetHit;
    int playerGetHit;
public:
    /** Constructor */
    Life();

    /** Destructor */
    ~Life();
    
    /** decreases player life when it's hit*/ 
    void updatePlayer(bool);

    /**  reduces life on hit.*/
    void operator --(int); 

    /**draws player life according to the hit on screen*/
    void playerDraw(SDL_Renderer* gRenderer, SDL_Texture* assets_foodlife);
    
    /**decreases enemy's life when enemy is hit*/ 
    void updateEnemy(bool);

    /**updates enemy's life when level increases*/
    void updateEnemy();

    /** draws enemy's life onto screen */ 
    void enemyDraw(SDL_Renderer* gRenderer, SDL_Texture* assets_foodlife);
    
    /** returns number of life player has left*/
    int getPlayerlife();

    /** returns number of life player has left*/
    int getEnemylife();
};


