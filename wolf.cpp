#include "wolf.hpp"
#include<iostream>
using namespace std;

Wolf::~Wolf()  //destrucctor
{
    cout<<"Wolf is destroyed"<<endl;
}

void Wolf::draw(SDL_Renderer* gRenderer, SDL_Texture* assets_enemy) //draws wolf
{
    Unit::draw(gRenderer, assets_enemy);  
}   

Wolf::Wolf(int x, int y)    //constrcutor with arguement if given 
{
    srcRect = {583,146,140, 140};
    moverRect = {x, y, 235, 190};
}
Wolf::Wolf()                //default constructor
{
    srcRect = {2,4,40, 50};// src coorinates from assets.png file, they have been found using spritecow.com
    moverRect = {550, 350, 140, 175};// it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
}
void Wolf::move(char direction, int count){ //checks if wolf has to move left or right 
    if (direction == 'r'){  //checks if direction is right so changes transtion accodrding to number "count"
        if (count == 0){
            moverRect.x = moverRect.x + 5;
            srcRect.x = 2;
            srcRect.y = 59;
        }
        else if (count == 1){
            moverRect.x = moverRect.x + 5;
            srcRect.x = 425;
            srcRect.y = 60;
            srcRect.w = 50;
            moverRect.w = 175;
        }
        else if (count == 2){
            moverRect.x = moverRect.x + 5;
            srcRect.x = 95;
            srcRect.y = 60;
            srcRect.w = 50;
            moverRect.w = 175;
        }
        else if (count == 3){
            moverRect.x = moverRect.x + 5;
            srcRect.x = 146;
            srcRect.y = 60;
            srcRect.w = 50;
            moverRect.w = 175;
        }
        else if (count == 4){
            moverRect.x = moverRect.x + 5;
            srcRect.x = 95;
            srcRect.y = 60;
            srcRect.w = 50;
            moverRect.w = 175;
        }
        else if (count == 5){
            moverRect.x = moverRect.x + 5;
            srcRect.x = 2;
            srcRect.y = 4;
            srcRect.w = 40;
            moverRect.w = 140;
        }
    }
    else if (direction=='l') {//checks if direction is left
        if(moverRect.x < 950)    moverRect.x +=  5;
        if (count == 0){
            srcRect.x = 2;
            srcRect.y = 59;
        }
        else if (count == 1){
            srcRect.x = 45;
            srcRect.y = 60;
            srcRect.w = 50;
            moverRect.w = 175;
        }
        else if (count == 2){
            srcRect.x = 95;
            srcRect.y = 60;
            srcRect.w = 50;
            moverRect.w = 175;
        }
        else if (count == 3){
            srcRect.x = 146;
            srcRect.y = 60;
            srcRect.w = 50;
            moverRect.w = 175;
        }
        else if (count == 4){
            srcRect.x = 95;
            srcRect.y = 60;
            srcRect.w = 50;
            moverRect.w = 175;
        }
        else if (count == 5){
            srcRect.x = 2;
            srcRect.y = 4;
            srcRect.w = 40;
            moverRect.w = 140;
        }
    }
}
void Wolf::punch(int count){ //punches according to transition number "count"
    if (count == 1){
        srcRect = {1,235,50,50};
        moverRect.w = 175;
    }
    else if (count == 2){
        srcRect = {155,234,70,50};
        moverRect.w = 211;
    }
    else if (count == 3){
        srcRect = {299,234,70,50};
        moverRect.w = 211;
    }
    else if (count == 4){
        srcRect = {375,234,90,50};
        moverRect.w = 211;
    }
    else if (count == 5)
    {
        srcRect = {601,234,60,50};
    }
    else if  (count == 6)
    {
        srcRect = {2,4,40, 50};
        moverRect.w = 175;
    }
}
void Wolf::fall(int count){//falls according to transition number and changes width in some transition for falling
    if (count == 1)
    {
        moverRect.x += 20;
        srcRect={148, 326, 43, 41};
        
    }
    else if (count  == 2)
    {
        moverRect.x += 10;
        srcRect = {196, 341, 60, 26};
        moverRect = {moverRect.x, 390, 200, 130};
    }
    else if (count == 3)
    {
        srcRect = {148, 326, 43, 41};
        moverRect.x += 10;
        moverRect = {moverRect.x, 350, 140, 175};
    }
    else if (count == 4)
        srcRect = {2,4,40, 50};
}
// void Panda::original_state(){
//     Panda panda;
//     srcRect = panda.srcRect;
// }
SDL_Rect Wolf::getCoord()
{  
    return moverRect;
}