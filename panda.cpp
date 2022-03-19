#include "panda.hpp"
#include<iostream>
#include <SDL.h>
using namespace std;
Panda::~Panda()  //Destructor 
{
    cout<<"Panda is destroyed"<<endl;
}
/**
    *getCoord returns moverRect for collision detection*/
SDL_Rect Panda::getCoord()
{  
    return moverRect;
}
/**
    *Draws Panda on Screen*/ 
void Panda::draw(SDL_Renderer* gRenderer, SDL_Texture* assets)
{
    
    Unit::draw(gRenderer, assets);  // draws the panda from the media file assets
}
/**
    Constructor with SDL coordinate arguments*/
Panda::Panda(int x, int y)
{
    srcRect = {5,120,58,90};        // src coorinates for steady position
    moverRect = {x, y, 150, 200};   // moverect if x and y are provided. 
}
/**
    *Default constructor*/ 
Panda::Panda()
{
    srcRect = {5,120,58,90};         // src coorinates for steady position
    moverRect = {200, 340, 150, 200};// moverect for default
}
/**
    *Move() enables Panda to move left and right*/ 
void Panda::move(char direction){
   
    //cout<<"move"<<endl;
    if (direction == 'r')           // if panda has to move to right
    {
    int speed = 100;               // animation speed 
    // array for different frames of transition
    SDL_Rect frames[4] = {{122,120, 49, 90},{171,120, 65, 90},{403,120, 53, 90},{5,120,58,90}};
    // array for different width for every transition
    int width[4] = {120, 145, 135, 145};
    // sets the frame number according to speed
    int  frame = (SDL_GetTicks()/speed)%3;
    moverRect.x += 10;            // movement in the x direction 
    srcRect = frames[frame];      // sets the srcRect
    moverRect.w = width[frame];   // sets the moverRect
    }

    else if (direction=='l')     // if the panda needs to move to left 
    {
    int speed = 53;
    SDL_Rect frames[3] = {{122,120, 49, 90},{171,120, 65, 90},{5,120,58,90}};
    int width[3] = {120, 150, 140};
    int  frame = (SDL_GetTicks()/speed)%3;
    moverRect.x -= 10;          // moves in the negative x direction
    srcRect = frames[frame];
    moverRect.w = width[frame];
    }
   
   
}
/**
    *Kick() enables Panda to kick*/ 
void Panda::kick(int i)
{
    // checks the value of i and changes the srcRect and moverRect accordingly
    if (i == 1)        
    {
        srcRect = {151, 12, 85, 90};
        moverRect.x += 10;
    }
    if (i ==3 )
    {
        srcRect = {151, 12, 85, 90};
        moverRect.x -= 5;
    }
    if (i == 2)
    {
        srcRect = {27, 217, 100, 90};
        moverRect.x += 10;
    }
    else if (i == 5)
    {
        srcRect = {5,120,58,90};
        moverRect.x -= 5;
    }
}
/**
    *punch() enables Panda to transition for a punch*/
void Panda::punch(int i){
    // checks the value of i and changes the srcRect and moverRect accordingly
    if (i == 1)      
    {
       srcRect={377,218,90,93};
        moverRect.x += 10;
    }
    else if (i == 2 || i == 4)
    {
        srcRect = {275,215,90,93};
        if (moverRect.x < 950) moverRect.x += 10;
        else moverRect.x -= 15;
    }
    else if (i == 3)
    {    srcRect = {247, 6,90,93};
         moverRect.x += 10;
    }
    else if (i == 5)
    {
        srcRect = {5,120,58,90};
        moverRect.x -= 15;
    }
}
/**
    *fall() enables Panda to transition for a fall*/
void Panda::fall(int i){
// checks the value of i and changes the srcRect and moverRect accordingly
    if (i == 1)           
    {
        moverRect.x -= 10;
        srcRect={16,312,100,100};
    }
    
    else if (i == 2)
    {
        moverRect.x -= 20;
        srcRect = {123,321,95,95};
    }
    else if (i == 3)
    {
        srcRect = {222, 316,100,100};
        moverRect.x -= 20;
    }
    else if (i == 4){
        srcRect = {322,343,100,60};
       // moverRect.y += 30;
        moverRect.w = 190;
        moverRect.x -= 20;
        moverRect = {moverRect.x, 440, moverRect.w, 80};
    }
    else if (i == 5){
        srcRect = {27,432,80, 80};
        moverRect.w = 150;
        moverRect.h = 200;
        moverRect.x -= 20;
        moverRect = {moverRect.x, 340, moverRect.w, moverRect.h};
    }
    else if (i == 7)
    {
       srcRect = {320,417,70,105};
       moverRect.w = 145; moverRect.h = 190;
    } 
    else if (i == 8)
    {
       srcRect = {5,120,58,90};
       moverRect.w = 145; moverRect.h = 190;
    } 
}