#pragma once 
#include<SDL.h>
#include "panda.hpp"
#include "tailung.hpp"
#include "wolf.hpp"
#include "bull.hpp"
#include "life.hpp"
#include "food.hpp"
using namespace std;
/** 
    * \brief Implements the entire game functionality, sets the level and performs transitions 
    * on enemy, life, food, and player.
    */
class Functionality
{   
   /**
    * \param tailung constructs the object of the enemy class Tailung
    * \param panda constructs the object of the player class Panda
    * \param Life consturcts the object of the class Life
    * \param Food constructs the object of the class Food
    * \param level is an integer that increments as level changes
    * \param state is a string which stores the current stat of the game; "Running","Lost","Won"
    * \param gRenderer is the window rederer 
    * \param assets is the texture of the sprite sheet of panda
    * \param assets_enemy is the texture of the sprite sheet of Tailung 
    * \param assets_foodlife is the texture of the food and life bar sprite sheet. 
    * \param b is an integer array that detects which key is pressed to call functions accordingly
    * \param state is a string initialized to "Running" and updates to "Won" or "Loss" as per the state of the game
    */
    Tailung tailung;       
    Panda panda; 
    Wolf wolf;
    Bull bull;
    int count = 0;  
    Life life;         
    Food food;
    int level;
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;
    SDL_Texture *assets_enemy1;
    SDL_Texture *assets_enemy2;
    SDL_Texture *assets_enemy3;
    SDL_Texture *assets_foodlife;
    int *b = new int[5]{0, 0, 0, 0, 0};
    int *t = new int[4]{0,0,0,0};
    string state = "Running";
    void level1();
    void level2();
    void level3();
   
public:
    /**
     * This constructor initializes the attributes of SDL.
     * \param gRenderer is the window renderer
     * \param SDL_Tecture points at the images texture
    */
    Functionality(SDL_Renderer *, SDL_Texture *,SDL_Texture *,SDL_Texture *, SDL_Texture *, SDL_Texture *, int); //constructor
    ~Functionality();
    /** 
     * renders each image on screen
     * It displays the transitions of each object as it changes with respect to the functions called.
     */
    void drawObjects();
    /** Updates the value from 0 to 1 in the int array b when the respective function is called. */
    void getkeys(int i);
    
    /** checks the state of the game
    *if the player runs out food or life, it sets the state to "Lost"
    *if the enemy life reaches zero, and the player has not run out of food,
    *it sets the state to "Won"
    *the function returns the state
    */
    pair<string, int> checkState();
};
/////////////////////////////// Updated ////////////////////////////////////////////////////////////