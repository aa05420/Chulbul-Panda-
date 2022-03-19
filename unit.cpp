#include "unit.hpp"

#include<iostream>

void Unit::draw(SDL_Renderer* gRenderer, SDL_Texture* assets)
{   
    //draws object
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}
Unit:: ~Unit(){
    std::cout<<"in the destructor"; //destructor
}
