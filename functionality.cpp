#include "Functionality.hpp"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <list>
#include <unistd.h>
using namespace std;

void Functionality::getkeys(int i) //gets the key pressed by setting the corresponding array value to 1
{  
    b[i] = 1; //array value at relevant index is set to 1
}

pair<string, int> Functionality::checkState() //checks and updates the state of the game and performs relevant functions
{
    int p = life.getPlayerlife();
    int e = life.getEnemylife();
    int safe = food.getNotHit();
    bool l = false;
    if (safe == 0 || p == 0 && state != "Won") //updates to 'Lost' if player's life or food becomes zero 
        state = "Lost";
    else if ((safe != 0 || p != 0) && e == 0 && level == 3 && state != "Lost") //updates to 'Won' if its the final level and enemy's loses all lives
        state = "Won";
    else if ((safe != 0 || p != 0) && e == 0 && level == 2) //if level two is won it proceeds to level 3
    {
        //cout<<"here"<<endl;
        level = 3;
        food.update(level, true); // food, player and enemy lives are updated 
        life.updatePlayer(true);
        life.updateEnemy(true);
    }
    else if ((safe != 0 || p != 0) && e == 0 && level == 1)//if level one is won it proceeds to level 2
    {
        //cout<<"level change"<<endl;
        level = 2;
        food.update(level, true);
        life.updatePlayer(true);
        life.updateEnemy(true);
    }
    return {state, level}; //returns state ans=d level
}
void Functionality::level1(){     //implementation of level 1 functionality
    panda.draw(gRenderer, assets);  //panda object is diplayed on the screen
    SDL_Rect mp = panda.getCoord(); //screen Coorinates of Panda
    SDL_Rect mt = tailung.getCoord();//screen Coorinates of Tailung
    if (SDL_HasIntersection(&mp, &mt) == true && b[0] != 0) //collision is checked
    {
        food--; // food gets reduced
        life--; //panda's life is reduced
        b[4] = 1; // enables falling motion of panda
        panda.fall(b[4]);  //calls panda's fall function
        b[4] ++;
        int r;
        r = rand() % 2; //initializes a random integer r for the move of the enemy
        if (r == 1){
            t[2] = 1; //punch function of the enemy is enabled
        }
        else{
            t[3] = 1; //kick function of the enemy is enabled
        }
    }
    
    else if (b[0]) // if right key is pressed
    {   
        panda.move('r'); //call move with right direction
        if(b[0] < 7)     //causing all transitions till it reaches to the the last transition and becomes 0
            b[0] ++;
        else 
            b[0] = 0;
    }
    else if (b[1])  
    {   //if left key is pressed
        panda.move('l'); //call move with left direction
        if(b[1] < 7)     //causing all transitions till it reaches to the the last transition and becomes 0
            b[1] ++;
        else 
            b[1] = 0;
    }
    if (b[2])
    {  // if down key is pressed, call kick function
        panda.kick(b[2]); //call kick
        if(b[2] < 6)     //causing all transitions till it reaches to the the last transition and becomes 0
            b[2] ++;
        else 
            b[2] = 0;
    }
    else if (b[3])
    {   //if up key is pressed, call punch function
        panda.punch(b[3]); //call punch
        if(b[3] < 9)     //causing all transitions till it reaches to the the last transition and becomes 0
            b[3] ++;
        else 
            b[3] = 0;
    }
    else if (b[4])
    {   //call function when panda is hit
        panda.fall(b[4]); //call fall
        if(b[4] < 9)     //causing all transitions till it reaches to the the last transition and becomes 0
            b[4] ++;
        else 
            b[4] = 0;
    }
    {
    tailung.draw(gRenderer, assets_enemy1);     //draws the enemy "Tailung" onto screen
    //cout << "one" << endl;
    }
    //if enemy is kicked or punched
    if ((b[2] != 0 || b[3] != 0) && SDL_HasIntersection(&mp, &mt) == true) 
    {
        t[4] =1; 
        life.updateEnemy();                 //update enemy's life
        if (life.getEnemylife()==0){        //if enemy's life runs out, set fall value to 1.
            t[4] = 1;
        } 
    }
    if (t[1]){
        tailung.move('r', t[1]);    //call move with left direction         
        if(t[1] < 2)                //causing all transitions till it reaches to the last transition and becomes 0
            t[1] ++;
        else 
            t[1] = 0;
    }
    else if (t[2]){
        tailung.kick(t[2]);         //call kick
        if(t[2] < 6)                //causing all transitions till it reaches to the last transition and becomes 0
            t[2] ++;
        else 
            t[2] = 0;
    }
    else if (t[3]){
        tailung.punch(t[3]);        //call punch
        if(t[3] < 5)                //causing all transitions till it reaches to the the last transition and becomes 0
            t[3] ++;
        else 
            t[3] = 0;
    }
    else if (t[4])
    {
        tailung.fall(t[4]);         //call fall
        if(t[4] < 3)                //causing all transitions till it reaches to the the last transition and becomes 0
            t[4] ++;
        else 
            t[4] = 0;
    }
}  
void Functionality::level2(){           //functions for level 2
    panda.draw(gRenderer, assets);      //panda object is diplayed on the screen
    SDL_Rect mp = panda.getCoord();     //screen Coorinates of Panda
    SDL_Rect mt = wolf.getCoord();      //screen Coorinates of Wolf
    if (SDL_HasIntersection(&mp, &mt) == true && b[0] != 0)         //collision is checked
    {
        food--;             //food gets reduced
        life--;             //life gets reduced
        b[4] = 1;           //enables falling motion of panda
        panda.fall(b[4]);   //calling fall of panda
        b[4] ++;
        t[2] = 1;           //punch function of the enemy is enabled
    }
    
    else if (b[0])          //if right key is pressed
    {
        panda.move('r');    //call move with left direction
        if(b[0] < 7)        //causing all transitions till it reaches to the the last transition and becomes 0
            b[0] ++;
        else 
            b[0] = 0;
    }
    else if (b[1])          //if left key is pressed
    {
        panda.move('l');    //call left with left direction
        if(b[1] < 7)        //causing all transitions till it reaches to the the last transition and becomes 0
            b[1] ++;
        else 
            b[1] = 0;
    }
    else if (b[2])          //if down key is pressed
    {
        panda.kick(b[2]);   //call kick
        if(b[2] < 6)        //causing all transitions till it reaches to the the last transition and becomes 0
            b[2] ++;
        else 
            b[2] = 0;
    }
    else if (b[3])          // if up key is pressed
    {
        panda.punch(b[3]);  //call punch 
        if(b[3] < 9)        //causing all transitions till it reaches to the the last transition and becomes 0
            b[3] ++;
        else 
            b[3] = 0;
    }
    else if (b[4])          // if got hit key is pressed
    {
        panda.fall(b[4]);   //call fall
        if(b[4] < 9)        //causing all transitions till it reaches to the the last transition and becomes 0
            b[4] ++;
        else 
            b[4] = 0;
    }
    wolf.draw(gRenderer, assets_enemy2);
    //if enemy is kicked or punched
    if ((b[2] != 0 || b[3] != 0) && SDL_HasIntersection(&mp, &mt) == true)
    {
        t[3] =1;            //fall element is added 
        life.updateEnemy(); //reduces life of enemy
    }
    if (t[1]){
        wolf.move('r', t[1]);   //call move with right direction
        if(t[1] < 2)            //causing all transitions till it reaches to the the last transition and becomes 0
            t[1] ++;
        else 
            t[1] = 0;
    }
    else if (t[2]){
        wolf.punch(t[2]);       //call punch 
        if(t[2] < 7)            //causing all transitions till it reaches to the the last transition and becomes 0
            t[2] ++;
        else 
            t[2] = 0;
    }
    else if (t[3])
    {
        wolf.fall(t[3]);        //call fall
        if(t[3] < 5)            //causing all transitions till it reaches to the the last transition and becomes 0
            t[3] ++;
        else 
            t[3] = 0;
    }
}
void Functionality::level3(){               //implementation of level 1 functionality
    panda.draw(gRenderer, assets);          //panda object is diplayed on the screen
    SDL_Rect mp = panda.getCoord();         //screen Coorinates of Panda
    SDL_Rect mt = bull.getCoord();          //screen Coorinates of Bull 

    if (SDL_HasIntersection(&mp, &mt) == true && b[0] != 0)     //collision is checked
    {
        food--;                  // food gets reduced
        life--;                  //panda's life is reduced
        b[4] = 1;                //enables falling motion of panda
        panda.fall(b[4]);        // calling fall of panda
        b[4] ++;                 //calls panda's fall function
        t[3] = 1;                //kick function of the enemy is enabled
    }
    
    else if (b[0])               // if right key is pressed
    {
        panda.move('r');         //call move with right direction
        if(b[0] < 7)             //causing all transitions till it reaches to the the last transition and becomes 0
            b[0] ++;
        else 
            b[0] = 0;
    }
    else if (b[1])              // if left key is pressed
    { 
        panda.move('l');        //call move with left direction
        if(b[1] < 7)            //causing all transitions till it reaches to the the last transition and becomes 0
            b[1] ++;
        else 
            b[1] = 0;
    }
    if (b[2])                   //if down key is pressed
    {
        panda.kick(b[2]);       //call kick
        if(b[2] < 6)            //causing all transitions till it reaches to the the last transition and becomes 0
            b[2] ++;
        else 
            b[2] = 0;
    }   
    else if (b[3])              // if up key is pressed
    {
        panda.punch(b[3]);      //call punch 
        if(b[3] < 9)            //causing all transitions till it reaches to the the last transition and becomes 0
            b[3] ++;
        else 
            b[3] = 0;
    }
    else if (b[4])              // if got hit key is pressed
    {
        panda.fall(b[4]);       //call fall
        if(b[4] < 9)            //causing all transitions till it reaches to the the last transition and becomes 0
            b[4] ++;
        else 
            b[4] = 0;
    }
    bull.draw(gRenderer, assets_enemy3);             //draws the enemy "Bull" onto screen

    //if enemy is kicked or punched
    if ((b[2] != 0 || b[3] != 0) && SDL_HasIntersection(&mp, &mt) == true)  
    {
        if (b[2]){                      //if the enemy is kicked
            //cout<<"kicked"<<endl;
            t[4] =1;                    //enable fall
            life.updateEnemy();         //update enemy's life
            //if (life.getEnemylife()==0){        
               // t[4] = 1;
            //}
        }
        else if (b[3]){                         //if the enemy is punched
            //cout<<"punched"<<endl;
            t[0] = 1;
            life.updateEnemy();                 //updates enemy's life
            //if (life.getEnemylife()==0){
                //t[4] = 1;
            //}
        }
    }
    if (t[0]){
        bull.move('r', t[0]);  //call move with right direction
        if(t[0] < 5)           //causing all transitions till it reaches to the the last transition and becomes 0
            t[0] ++;
        else 
            t[0] = 0;
    }
    if (t[1]){
        bull.move('l', t[1]);  //call move with left direction
        if(t[1] < 6)           //causing all transitions till it reaches to the the last transition and becomes 0
            t[1] ++;
        else 
            t[1] = 0;
    }
    else if (t[3]){
        bull.punch(t[3]);      //call punch
        if(t[3] < 7)           //causing all transitions till it reaches to the the last transition and becomes 0
            t[3] ++;
        else 
            t[3] = 0;
    }
    else if (t[4])
    {
        bull.fall(t[4]);       //call fall
        if(t[4] < 8)           //causing all transitions till it reaches to the the last transition and becomes 0
            t[4] ++;
        else 
            t[4] = 0;
    }
}  
void Functionality::drawObjects()
{
    if (level == 1)                                 //if on level 1, it should call the level 1 function for perfomance
        Functionality::level1();
    else if (level == 2)                            //if on level 2, it should call the level 2 function for perfomance
        Functionality::level2();
    else                                            //if on level 3, it should call the level 3 function for perfomance
        Functionality::level3();
    life.playerDraw(gRenderer, assets_foodlife);    //draws life of player 
    life.enemyDraw(gRenderer, assets_foodlife);     //draws life of enemy
    food.draw(gRenderer, assets_foodlife, level);   //draws food of player
}
     



Functionality::Functionality(SDL_Renderer *renderer, SDL_Texture *asst, SDL_Texture *ass1,SDL_Texture *ass2,SDL_Texture *ass3, SDL_Texture *fl, int l):gRenderer(renderer), assets(asst), assets_enemy1(ass1),assets_enemy2(ass2),assets_enemy3(ass3),assets_foodlife(fl), level(l)
{
} //constructor

Functionality::~Functionality(){ //destructor
    cout<<"Functionality is destroyed"<<endl;
    panda.~Panda();              //destroy Panda
    wolf.~Wolf();                //destroy wolf
    tailung.~Tailung();          //destroy tailung
    bull.~Bull();                //destroy panda
    food.~Food();                //destroy food
    life.~Life();                //destroy life
    delete [] b;                 //deleting Panda function detecting array
    delete [] t;                 //deleting Enemy function detecting array
}
