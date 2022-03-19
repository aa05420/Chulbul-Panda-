#include "tailung.hpp"
#include<iostream>
using namespace std;
Tailung::~Tailung()  //
{
    cout<<"Tailung is destroyed"<<endl;
}
void Tailung::draw(SDL_Renderer* gRenderer, SDL_Texture* assets_enemy)
{
    Unit::draw(gRenderer, assets_enemy);    //draws the enemy onto the screen
}   

Tailung::Tailung(int x, int y)
{
    srcRect = {583,146,140, 140};    //default position of the enemy
    moverRect = {x, y, 235, 190};   //place the enemy at x and y coordinates of the screen
}
Tailung::Tailung()
{
    srcRect = {228,58,55, 55};          // src coorinates from assetenemypng file, they have been found using spritecow.com
    moverRect = {550, 360, 150, 150};   // initial posiiton of enemy on the screen
}
//SDL_Rect src[4] = {{196,263,x,y},{237,262,x,y},{283,261,x,y}};

//function to implement moving functionality of the enemy
void Tailung::move(char direction, int count){
    // if right key is pressed, change x coord. 
    //count keeps track of transition to be displayed on the screen
    if (direction == 'r'){
        if (count == 0){
            //initial sprite
            moverRect.x = moverRect.x + 5;
            srcRect.x = 6;
            srcRect.y = 4;
            srcRect.w = 65;
        }
        else{
            //moving sprite
            moverRect.x = moverRect.x + 5;
            srcRect.x = 228;
            srcRect.y = 58;
            srcRect.w = 55;
        }
    }   

    // if left key is pressed, change x coord. 
    //count keeps track of transition to be displayed on the screen
    else if (direction=='l') {
        //initial sprite
        if (count == 0){
            moverRect.x = moverRect.x + 5;
            srcRect.x = 6;
            srcRect.y = 4;
            srcRect.w = 65;
        }
        //moving sprite
        else{
            moverRect.x = moverRect.x + 5;
            srcRect.x = 228;
            srcRect.y = 58;
            srcRect.w = 55;
        }
    }
}
//function to implement kick functionality of the enemy
//count keeps track of enemy sprite to be displayed on the screen
void Tailung::kick(int count){    
    if (count == 0){           
        srcRect = {6,4,65,55};  //updates sprite
        moverRect.w = 171;      //sets enemy's position on screen
    }
    else if (count == 1){
        srcRect = {69,5,60,55};     
        moverRect.w = 171; moverRect.x -= 4;
    }
    else if (count == 2){
        srcRect = {129,1,60,60};
        moverRect.w = 171; moverRect.x -= 4;
    }
    else if (count == 3){
        srcRect = {201,2,60,55};
        moverRect.w = 171; moverRect.x -= 4;
    }
    else if (count == 4){
        srcRect = {6,4,65,55};
        moverRect.w = 150; moverRect.x += 4;
    }
    else if (count == 5){
        srcRect = {228,58,55,55};
        moverRect.w = 150; moverRect.x += 4;
    }
}

//function to implement punch functionality of the enemy
//count keeps track of enemy sprite to be displayed on the screen
void Tailung::punch(int count){
    if (count == 1){
        srcRect = {13, 60, 60, 55};         //changes enemy's sprite
        moverRect.w = 150; moverRect.x -= 4;    //updates position of enemy on screen
    }
    else if (count == 2){
        srcRect = {78,61,65,55};
        moverRect.w = 175;  moverRect.x -= 4;
    }
    else if (count == 3){
        srcRect = {144,58,80,55};
        moverRect.w = 211; moverRect.x -= 4;
    }
    else if (count == 4){
        srcRect = {13,60,60,55};
        moverRect.w = 150; moverRect.x += 4;
    }
    else if (count == 5){
        srcRect = {228,58,55,55};
        moverRect.x += 4;
    }
}
//function to implement fall functionality of the enemy
//count keeps track of enemy sprite to be displayed on the screen
void Tailung::fall(int count){

    if (count ==1)
    {
        cout << "tailung fall" << endl;
        moverRect.x += 10;              //update enemy position on screen
        srcRect={4, 135, 45, 70};       //changes sprite 
    }
    else if (count  == 2)
    {
        srcRect={228, 58, 55, 55};      //changes sprite 
    }
}
SDL_Rect Tailung::getCoord()
{  
    return moverRect;   //takes screen coordinates for collision detection
}