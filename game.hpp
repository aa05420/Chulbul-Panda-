#pragma once 
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "functionality.hpp"
using namespace std;
/**
 * \brief This is the main game class in which we in which we start and end the game, detect keys and load the media
*/
class Game{
    //Screen dimension constants
    /**
    * \param SCREEN_WIDTH is the width of our game screen that is a constant integer 
    * \param SCREEN_HEIGHT is the height of our game screen that is a constant integer
    * \param gWindow is the window we will render to
    * \param gTexture is the texture that is currently displayed
    * \param assets is the reference to the png sprite sheets
    * \param asset_enemy is the reference to the enemy's png sprite sheets
    * \param assets_foodlife is the reference to the food and life png sprite sheets
    * \param bgmusic is the reference to the music that is being played while the game screen is open
 */

    const int SCREEN_WIDTH = 1000;
    const int SCREEN_HEIGHT = 600;

    std::vector <Functionality *> functionality;

    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //The window renderer
    SDL_Renderer* gRenderer = NULL;

    //Current displayed texture
    SDL_Texture* gTexture = NULL;
    //global reference to png image sheets
    SDL_Texture* assets=NULL;
    SDL_Texture* assets_enemy1=NULL;
    SDL_Texture* assets_enemy1_2=NULL;
    SDL_Texture* assets_enemy2=NULL;
    SDL_Texture* assets_enemy3=NULL;
    
    SDL_Texture* assets_foodlife=NULL;
    
    Mix_Music *bgMusic = NULL;
    int l; //level
public:
    /**
     * init will initialize the game and set the window with SDL and give a error if there is trouble in initialization  
     * return true if we successfully initialize the game else returns false.
    */
    bool init();
    /**
     * loadMedia will load the pictures and sound files.
     * It returns false if media is unable to load else true otherwise.
    */
    bool loadMedia();
    /** Destroys all attributes of the game */
    void close();
    /** Loads and returns the picture to be displayed on the screen*/
    SDL_Texture* loadTexture( std::string path );

    /** 
     * Implements game functionalities while the game is running 
     * It detects the keys and calls the respective function in response to each key
     * It also sets and changes the game states (won or loss) and levels.
    */
    void run();
    /** 
     * shows start screen and detect start and exit buttons.
    */
    bool start();
    /** 
     * Shows Instructions and detect "Let's Start" Button.
    */
    bool Instructions();
};

