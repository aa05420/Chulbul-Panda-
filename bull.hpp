#pragma once
#include "unit.hpp"
/**
 * \brief This class constructs the object of the enemy Bull and performs its action and collision functions
*/
class Bull: public Unit{
    
public:
    /** changes the sprite coordinates that corresponds to the punch move */
    void punch(int count);
    /** returns the SDL_Rect coordinates of Bull if called */
    SDL_Rect getCoord();
    /** changes the sprite coordinates that corresponds to the direction the enemy is 
    *moving */
    void move(char direction,int count);
    /** draws the enemy from the sprite sheet based on the updated sprite coordinates*/
    void draw(SDL_Renderer* gRenderer, SDL_Texture* assets_enemy);  
    void fall(int );
    /** Constuctor for the Bull class which initializes the attributes of this class 
    * to their default values */
    Bull(); 
    /* destructor initializing */
    ~Bull();           
    
    /**Constructor for Bull which takes two parameters x and y and
     * places an object of the Bull class at these x and y coordinates */ 
    Bull(int x, int y);                           
};