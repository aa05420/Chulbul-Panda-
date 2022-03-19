#pragma once
#include "unit.hpp"
/**
 * \brief This class constructs the object of the enemy Wolf and performs its action and collision functions
*/
class Wolf: public Unit{
    
public:
    /** changes the sprite coordinates that corresponds to the punch move */
    void punch(int count);
    /** returns the SDL_Rect coordinates of wolf if called */
    void fall(int count);

    /** Get screen coordinates of Wolf */
    SDL_Rect getCoord();
    /** changes the sprite coordinates that corresponds to the direction the enemy is 
    *moving */
    void move(char direction,int count);
    /** draws the enemy from the sprite sheet based on the updated sprite coordinates*/
    void draw(SDL_Renderer* gRenderer, SDL_Texture* assets_enemy);  

    /** Constuctor for the Wolf class which initializes the attributes of this class 
    * to their default values */
    Wolf();

    /** Destructor*/           
    ~Wolf();

    /**Constructor for Wolf which takes two parameters x and y and
     * places an object of the Wolf class at these x and y coordinates */ 
    Wolf(int x, int y);                           
};