#pragma once
#include "unit.hpp"
/**
 * \brief This class constructs the object of the enemy Tailung and performs its action and collision functions
*/
class Tailung: public Unit{
    
public:
    /** changes the sprite coordinates that corresponds to the kick move */
    void kick(int count);
    /** changes the sprite coordinates that corresponds to the punch move */
    void punch(int count);
    /** returns the SDL_Rect coordinates of tailung if called */
    SDL_Rect getCoord();
    /** changes the sprite coordinates that corresponds to the direction the enemy is 
    *moving */
    void move(char direction,int count);
    /** draws the enemy from the sprite sheet based on the updated sprite coordinates*/
    void draw(SDL_Renderer*, SDL_Texture* assets_enemy);  

    /** changes the sprite coordinates according to fall*/
    void fall(int count);
    /** Constuctor for the Tailung class which initializes the attributes of this class 
    * to their default values */
    Tailung();   
    /**Destructor*/        
    ~Tailung();
    /**Constructor for Tailung which takes two parameters x and y and
     * places an object of the Tailung class at these x and y coordinates */ 
    Tailung(int x, int y);
                           
};