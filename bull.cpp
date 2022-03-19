#include<iostream>

#include "bull.hpp"
using namespace std;

Bull::~Bull() //destructor
{   
    cout<<"Bull is destroyed"<<endl;
}
void Bull::draw(SDL_Renderer* gRenderer, SDL_Texture* assets)
{
    
    Unit::draw(gRenderer, assets);  //draws the bull onto the screen from the png file
}
Bull::Bull(int x, int y)
{   
    //Args - int x, int y
    //places the bull on the screen at the coordinates x and y
    srcRect = {407,900,200,150};
    moverRect = {x, y, 300, 200};   
}
Bull::Bull()
{   // places the bull at its initial position
    srcRect = {407,900,200,150};
    moverRect = {550, 340, 300, 200};
}
//SDL_Rect src[4] = {{196,263,x,y},{237,262,x,y},{283,261,x,y}};
void Bull::move(char direction, int i){
    //cout<<"move"<<endl;

    // if the right arrow key is pressed
    // int i keeps track of bull's transistion
    if (direction == 'r')
    {   
        if (i == 1)
        {
            srcRect = {1196,900,200,150};    //sprite coords are changed
            if (moverRect.x + moverRect.w < 950) moverRect.x += 10;               //moves to the right
             
        }
        else if (i == 2)
        {
            srcRect = {796,900,200,150};        //sprite coords are changed
            if (moverRect.x + moverRect.w < 950) moverRect.x += 10;                  //moves to the right
            
        }

        else if (i == 3)
        { 
            srcRect ={1196,900,200,150};        //sprite coords are changed
            moverRect.x -= 10;                  //moves to the right
            
        }

        else if(i == 4)
        {
            srcRect = {400,900,200,150};        //sprite coords are changed
        }
        
        moverRect = {moverRect.x, 330, 300, 200};      
    }
    
    // if left arrow key is pressed
    else if (direction=='l')
    {
        if ((i == 1 || i == 4))
        {
            srcRect = {1196,900,200,150};
             moverRect.x -= 10;          // move bull to the left by 10
            
        }
        else if ((i == 2))
        {
            srcRect = {796,900,200,150};
            moverRect.x -= 10;          // move bull to the left by 10
           
        }

        else if (i == 3)
        { 
            srcRect ={1185,425, 200, 120};
            moverRect.x -= 10;          // move bull to the left by 10
            
        }

        else if(i == 5)
        {
            srcRect = {407,900,200,150};            //sprite coords are changed
        }
        
        moverRect = {moverRect.x, 330, 145, 190};    
    }
}

void Bull::punch(int i)
{
    // int i keeps track of the transition to be displayed on the screen
    if (i == 1)
    {
       srcRect={1003,1275,200, 150}; //sprite coords are changed
        moverRect.x -= 10;            //moves to the right
    }
    else if (i == 2)
    {
        srcRect = {812,1248,200, 170}; //sprite coords are changed
        moverRect.x -= 10;              //moves to the right 
    }
    else if (i == 3)
    {   
        srcRect = {1225, 708,150,170};  //sprite coords are changed
        moverRect.x += 10;              //moves to the right
    }
    else if(i == 6)
    {
        srcRect = {407,900,200,150};    //sprite coords are changed
    }
}

void Bull::fall(int i){
    // int count keeps track of the fall transisitions to be displayed on the screen
    
    if (i == 1)
    {
        if (moverRect.x + moverRect.w < 950) moverRect.x += 10;     //checking if it doesn't cross the boundary of screen, then move
       srcRect={823,1227,180,200};
    }
    else if (i == 2)
    {
        if (moverRect.x + moverRect.w < 950) moverRect.x += 10;     //checking if it doesn't cross the boundary of screen, then move
        srcRect = {667,1231,150,200};
    }
    else if (i == 3)
    {
        srcRect = {1079, 1441,180,160};
        if (moverRect.x + moverRect.w < 950) moverRect.x += 10;     //checking if it doesn't cross the boundary of screen, then move
    }
    else if (i == 4)
    {
        srcRect = {963,1611,200, 160};
        if (moverRect.x + moverRect.w < 950) moverRect.x += 10;     //checking if it doesn't cross the boundary of screen, then move
    }
    else if (i == 5)
    {
        srcRect = {760,1608,200, 160};
        if (moverRect.x + moverRect.w < 950) moverRect.x += 10;     //checking if it doesn't cross the boundary of screen, then move
    }
    else if (i == 6)
    {
        srcRect = {1247, 1464, 130, 140};
        moverRect.x -= 10;     
    }
    else if (i == 7)
    {
        srcRect = {407,900,200,150};
    }
}
SDL_Rect Bull::getCoord()
{  
    return moverRect;          //gets coordinates of the currently displayed sprite image
}   

