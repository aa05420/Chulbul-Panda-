#include "food.hpp"

#include<iostream>
using namespace std;

Food::~Food()  //destructor 
{
    cout<<"Food is destroyed"<<endl;
}

Food:: Food():foodNum(0), nothit(6){} //constructor

int Food::getNotHit()               //returns number of food left
{  
    return nothit;
}
void Food:: operator--(int)     //overloading to reduce food
{
    nothit--;
}


void Food::checkLevel(int level) //check picture of food according to level
{
    if (level == 1) foodNum = 1;
    else if (level == 2) foodNum = 2;
    else if (level == 3) foodNum = 3;
    else foodNum = 0;
    //cout<<foodNum;

} 
void Food:: draw(SDL_Renderer* gRenderer, SDL_Texture* assets_foodlife, int level)
{
    checkLevel(level);
    int x = 160;
    if  (foodNum == 1)       // noodles
    {
        Unit::srcRect = {387, 23, 174, 113};
        
        for(int row=0;row<nothit;row++)  //for each image of food
        {
            x += 50;
            Unit::moverRect = {x, 10, 40, 40};
            Unit::draw( gRenderer, assets_foodlife);
	    }
    }
    else if  (foodNum == 2)  // radish
    {
        Unit::srcRect = {41, 10, 132, 128};
        for(int row=0;row<nothit;row++) //for each image of food
        {
            x += 50;
            Unit::moverRect = {x, 10, 40, 40};
            Unit::draw( gRenderer, assets_foodlife);
	    }
    }
    else if  (foodNum == 3)  // dumplings
    {
        Unit::srcRect = {217, 8, 156, 122};
        for(int row=0;row<nothit;row++)  //for each image of food
        {
            x += 50;
            Unit::moverRect = {x, 10, 40, 40};
            Unit::draw( gRenderer, assets_foodlife);
	    }
    }

}

void Food:: update(int level, bool newLevel) //updates new food on new level and change number of food to be drawn
{
    if(newLevel)
    {
        checkLevel(level);
        nothit = 6;
    }
}