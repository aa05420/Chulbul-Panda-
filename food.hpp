#pragma once
#include<iostream>
#include "unit.hpp"
/** 
    * \brief Implements food for each level.
    */
class Food: public Unit
{
/**
    * \param foodNum takes the picture number according to level.
    * \param nothit is the number of pictures draw.
    */
    int foodNum;
    int nothit;
   
public:
/** 
     * renders each image on screen
     */
    void draw(SDL_Renderer* gRenderer, SDL_Texture* assets_foodlife, int level);
    /** 
     * checks level for food pic
     */
    void checkLevel(int level);
    /** 
     * renders food for new level on screen
     * It displays the transitions of each object as it changes with respect to the functions called.
     */
    void update(int level, bool);
    /** 
     * Constructor
     */
    Food();
    /** 
     * destructor
     */
    ~Food();
    /** 
     * reduces food on hit.
     */
    void operator--(int);
    /** 
     * returns food left
     */
    int getNotHit();
};