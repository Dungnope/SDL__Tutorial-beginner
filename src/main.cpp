#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include<vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"
int main(int argc, char* args[]){

    //check to see whether init failed
    if(SDL_Init(SDL_INIT_VIDEO) > 0) std::cout << "HEY SDL_Init has failed. error" << SDL_GetError() << std::endl;

    //check image init failed
    if(!IMG_Init(IMG_INIT_PNG)) std::cout << "IMG_init has failed" << SDL_GetError() << std::endl;

    RenderWindow window("Hello Game v2.0", 1024, 576);
    SDL_Texture* groundTexture = window.loadTexture("/home/dyul/SDL2__Platformer/res/gfx/Ground.png");
    SDL_Texture* groundTexture2 = window.loadTexture("/home/dyul/SDL2__Platformer/res/gfx/Ground2.png");
    
    //initilize entity
    // Entity entities[4] = {
    //     Entity(32, 0, groundTexture),
    //     Entity(32, 32, groundTexture),
    //     Entity(0, 64, groundTexture),
    //     Entity(64, 64, groundTexture),
    // };

    std::vector<Entity> entities = {
        Entity(32, 0, groundTexture),
        Entity(32, 32, groundTexture),
        Entity(0, 64, groundTexture),
        Entity(64, 64, groundTexture),
    };

    {    
        Entity plank(32, 0, groundTexture2);
        entities.push_back(plank);
    }

    bool gameRunning = true; 
    
    //to make event;
    SDL_Event event;

    //make the window show until destroy event trigger with 'X'
    while(gameRunning)
    {
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT) gameRunning = false;
        }
        //clear whole screen
        window.clearScreen();
        //render the tetexture

        for(Entity& e : entities){
            window.renderer(e);
        }

        //show the screen after render texture
        window.display();
    }

    window.cleanUp();
    SDL_Quit();

    return 0;
}