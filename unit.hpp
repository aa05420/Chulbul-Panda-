#pragma once 
#include<SDL.h>
#include<iostream>
/**
 * \brief This is a parent class for all the child classes created from it i.e., food, life, enemies, and panda. 
*/
class Unit  
{
    protected:
    /** 
    * \param srcRect contains SDL coordinates of the assets.
    * \param moverRect contains SDL coordinates of the screen.
    */
    SDL_Rect srcRect;  
    SDL_Rect moverRect;
public:
    /** Draws objects on screen and called by child classes*/
    void draw(SDL_Renderer* gRenderer, SDL_Texture* assets);
    /** Virture destructor*/
    virtual ~Unit() = 0;
};