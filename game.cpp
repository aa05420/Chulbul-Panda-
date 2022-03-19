#include "game.hpp"


bool Game::init()
{
	//Initialization flag
	bool success = true;
	l = 1;
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );		
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "HU Mania", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
				if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
				{
					printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}


bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;
	
	// loads the start screen texture 
    gTexture = loadTexture("StartScreen.png");
	SDL_RenderPresent(gRenderer); //displays the updated renderer
	SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);	

	//if no texture is set, an error is displayed
	if(gTexture==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	//sets background music
	bgMusic = Mix_LoadMUS( "panda.mp3" );

	// if background music is not set, display error.
	if(bgMusic == NULL){
		printf("Unable to load music: %s \n", Mix_GetError());
		success = false;
	}
	//return bool indicating where the game's media has been successfully set up
	return success;
}

void Game::close()
{
	//Free loaded images
	SDL_DestroyTexture(assets);
	SDL_DestroyTexture(assets_enemy1);
	SDL_DestroyTexture(assets_enemy2);
	SDL_DestroyTexture(assets_enemy3);

	//set assets to NULL
	assets=NULL;
	assets_enemy1 = NULL;
	assets_enemy2 = NULL;
	assets_enemy3 = NULL;
	SDL_DestroyTexture(gTexture);
	
	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;
	Mix_FreeMusic(bgMusic);
	bgMusic = NULL;
	//Quit SDL subsystems
	IMG_Quit();
	Mix_Quit();
	SDL_Quit();
}

SDL_Texture* Game::loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;	

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}

bool Game::Instructions()
	{
	//load the Instructions screen
	gTexture = loadTexture("Instuctions.png");
	SDL_RenderPresent(gRenderer); //displays the updated renderer
	SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
	// quit takes on a bool value to indicate if user has requested to close the game
	bool quit = false;
	// create a mouse event
	SDL_Event evn;
	// if the button is pressed, play1 will return true
	bool play1 = false;
	while( !quit )
	{ 
		//Handle events on queue
		while( SDL_PollEvent( &evn ) != 0 )
		{
			//User requests quit
			if( evn.type == SDL_QUIT )
			{
				quit = true;
				}

			// two variables to store mouse x and y coordinates
			int x, y;
    		
			// if the mouse is in motion
			if (evn.type == SDL_MOUSEMOTION){		
                x = evn.motion.x;			//store x coord of the mouse
                y = evn.motion.y;			//store y coord of the mouse 
				//std::cout<<"Mouse Position = {"<< evn.motion.x << " "<<evn.motion.y<<"}"<<endl;

				//play button 
                if ((x >= 364) && (x <= 650 ) && (y >=534) && (y <= 559)){			//if the mouse coords lie on the region of 
					std::cout<<"I am at INSTRUCTIONS!"<<endl;						//screen where start button is displayed
					gTexture = loadTexture("Instructionsclicked.png");				//change the screen to display a clicked version of start
                    SDL_RenderPresent(gRenderer); //displays the updated renderer
					SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
				}
				else{
					//std::cout<<"I am nowhere!"<<endl;
					gTexture = loadTexture("Instuctions.png");	//else the screen remains the same since mouse isnt hovering on a button
					SDL_RenderPresent(gRenderer);				//displays the upSdated renderer
					SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
				}
			
    		}

			if (evn.type == SDL_MOUSEBUTTONDOWN){  				//this calls an event, checks if a mouse button is pressed 
				if( evn.button.button == SDL_BUTTON_LEFT ){		//if left mouse button is pressed
					x = evn.button.x;							//store x and y coordinates of the screen where the mouse is placed 
					y = evn.button.y;
					//play button is pressed
					if ((x >= 364) && (x <= 650 ) && (y >=534) && (y <= 559)){
					std::cout<<"START is pressed"<<endl;
					play1=true;
					std::cout<< "PLAY" << std::boolalpha << play1 <<endl;
					//the player pressed play button and therefro
					return play1;
					break;
					}
				}	
			}
		}
	}
}

bool Game::start()
{	// if the user requests to close the game, quit returns true else false
	bool quit = false;
	// if the user requests to play the game, play1 returns true else false
	bool play1 = false;
	
    gTexture = loadTexture("StartScreen.png");			//initial screen with no buttons highlighted
	SDL_RenderPresent(gRenderer); 						//displays the upSdated renderer
	SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
	SDL_Event ev;	//event
	while( !quit )
	{ 
		//Handle events on queue
		while( SDL_PollEvent( &ev ) != 0 )
		{
			//User requests quit
			if( ev.type == SDL_QUIT )
			{
				quit = true;
				}
			
			// two variables to store mouse x and y coordinates
			int x, y;
    		// if the mouse is in motion
			if (ev.type == SDL_MOUSEMOTION){
                x = ev.motion.x;			//store x coord of the mouse
                y = ev.motion.y;			//store y coord of the mouse
				//std::cout<<"Mouse Position = {"<< ev.motion.x << " "<<ev.motion.y<<"}"<<endl;

				//play button 
                if ((x >= 543) && (x <= 788 ) && (y >=241) && (y <= 286)){ 	//if mouse is over play button
					std::cout<<"I am at play!"<<endl;
					gTexture = loadTexture("GameStart.jpeg");				//change screen to highlight play button
                    SDL_RenderPresent(gRenderer); 							//displays the updated renderer
					SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
				}

				else if((x > 543) && (x < 782) && (y > 337) && (y < 387)){	//if mouse is over exit button
					std::cout<<"I am at exit!"<<endl;
					gTexture = loadTexture("GameExit.jpeg");				//change screen to highlight exit button
                    SDL_RenderPresent(gRenderer); 							//displays the updated renderer
					SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
        		}
				else{
					//std::cout<<"I am nowhere!"<<endl;						//if mouse is not over any button, display initial screen
					gTexture = loadTexture("StartScreen.png");
					SDL_RenderPresent(gRenderer); 							//displays the upSdated renderer
					SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
				}
			
    		}

			if (ev.type == SDL_MOUSEBUTTONDOWN){  //this calls an event, I assume that you already know how to make an event right? 
				if( ev.button.button == SDL_BUTTON_LEFT ){
					x = ev.button.x;
					y = ev.button.y;
					//play button is pressed
					if ((x >= 543) && (x <= 788 ) && (y >=241) && (y <= 286)){
					std::cout<<"Play button is pressed"<<endl;
					play1=true;
					std::cout<< "PLAY" << std::boolalpha << play1 <<endl;
					return play1;
					break;
					}
				}	
			}

			if (ev.type == SDL_MOUSEBUTTONDOWN){  //this calls an event, I assume that you already know how to make an event right? 
				if( ev.button.button == SDL_BUTTON_LEFT ){
					x = ev.button.x;
					y = ev.button.y;
				//play button is pressed
					if((x > 543) && (x < 782) && (y > 337) && (y < 387)){
						std::cout<<"Exit button is pressed"<<endl;
						play1=false;
						std::cout<< "PLAY" << std::boolalpha << play1 <<endl;
						return play1;
					}
				}
			}
		}
	}
}

void Game::run( )
{	// if the user requests to close the game, quit returns true else false
	bool quit = false;
	SDL_Event e;			//event
	
	//loads media on screen for level 1 
	assets = loadTexture("Pandaspritesheet.png");	
	assets_enemy1 = loadTexture("tailung.png");
	assets_enemy2 = loadTexture("wolf.png");
	assets_enemy3 = loadTexture("bull.png");
	assets_foodlife = loadTexture("food_life.png");
    gTexture = loadTexture("level 1.png");
	//HUMania humania(gRenderer, assets_enemy);

	//Vector that stores the functionality for levels 
	functionality.push_back(new Functionality(gRenderer, assets, assets_enemy1,assets_enemy2,assets_enemy3, assets_foodlife, l));	
	while( !quit )
	{
		//Handle events on queue
		static bool flag2 = false; static bool flag3 = false;
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
				
			}

			if(e.type == SDL_KEYDOWN){						//if a key is pressed
                if (e.key.keysym.sym == SDLK_RIGHT){		//if the right arrow key is pressed
					functionality[l-1]->getkeys(0);			//set int param in get key to 0
				}
					
				else if	(e.key.keysym.sym == SDLK_LEFT){	//if left arrow key is pressed
					functionality[l-1]->getkeys(1);			//set int param in get key to 1
				}	
				else if (e.key.keysym.sym == SDLK_DOWN){	//if down arrow key is pressed
					functionality[l-1]->getkeys(2);			//set int param in get key to 2
				}
				else if (e.key.keysym.sym ==SDLK_UP){		//if up arrow key is pressed
					functionality[l-1]->getkeys(3);			//set int param in get key to 3
					
				}
			}
		}

			if( Mix_PlayingMusic() == 0 )
			{
				//Play the music
				Mix_PlayMusic( bgMusic, 2 );
			}
			SDL_RenderClear(gRenderer); //removes everything from renderer
			SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);//Draws background to renderer
			//***********************draw the objects here********************

			functionality[l-1]->drawObjects();								//draw objects for level on screen
			auto [state, newLevel] = functionality[l-1]->checkState();		//check the state of the current level 
			//cout<<state<<endl;	

			//if the player reaches level 2 and the game is running 
			if (newLevel == 2 && state == "Running" && flag2 == false)
			{
				SDL_RenderClear(gRenderer);  						//clear screen
				gTexture = loadTexture("level 2.png");				//display level 2 screen
				SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);	
				//increase level
				l++;
				//add functionality i vector for level 3
				functionality.push_back(new Functionality(gRenderer, assets, assets_enemy1,assets_enemy2,assets_enemy3, assets_foodlife, l));
				flag2 = true;										//not to get in this condition again 
			}
			
			//if the player reaches level 3 and the game is running 
			else if (newLevel == 3  && state == "Running" && flag3 == false)
			{
				SDL_RenderClear(gRenderer);  						//clear screen
				gTexture = loadTexture("level 3.png");				//add level 3 pic
				SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
				//increase level
				l++;
				//add functionality i vector for level 3
				functionality.push_back(new Functionality(gRenderer, assets, assets_enemy1,assets_enemy2,assets_enemy3, assets_foodlife, l));
				flag3 = true;										//not to get in this condition again 
			}
			if (state == "Lost")									//if game is lost
			{
				SDL_RenderClear(gRenderer); 						//clear screen
				gTexture = loadTexture("game over.png");			//add game over pic
				SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);    
				
			}
			if (state == "Won")										//if game is won
			{
				SDL_RenderClear(gRenderer);  						//clear screen
				gTexture = loadTexture("game won.png");				//add game won pic
				SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);	
			}
			

		//****************************************************************
    	SDL_RenderPresent(gRenderer); //displays the updated renderer

	    SDL_Delay(200);	//causes sdl engine to delay for specified miliseconds
		}
	delete functionality[l-1];	//deletes level 3
	functionality.pop_back();   //pops out level 3 functionality class
	delete functionality[l-2];	//deletes level 2
	functionality.pop_back();   //pops out level 2 functionality class
	delete functionality[l-3];	//deletes level 1
	functionality.pop_back();   //pops out level 1 functionality class
}