#pragma once
#include "unit.hpp"

/**
 * \brief This class constructs the object of the player Panda and performs its action and collision functions
*/
class Panda: public Unit{
    int count;
public:Panda(); 
     /** constructor that intializes a Panda object with SDL Rect values
      *  at particular x and y location on the screen
      * \param x is the x coordiate
      * \param y is the y coordinate
    */           
    Panda(int x, int y); 
    /** Destructor to destroy the object*/
    ~Panda();
    /** renders an image of the Panda on the screen*/
    void draw(SDL_Renderer*, SDL_Texture* assets);  
    /** enables left and right movement of the Panda with respect to the char direction given as input*/   
    void move(char direction);
    /** displays the kick animation of the Panda through image transitions*/
    void kick(int);
    /** displays the punch animation of the Panda through image transitions*/
    void punch(int); 
    /** displays the fall animation of the Panda through image transitions*/
    void fall(int); 
    /** returns the moverRect coordinates for the Panda object*/
    SDL_Rect getCoord();
    
                        
};