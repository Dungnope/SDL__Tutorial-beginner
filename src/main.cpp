#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"
int main(int argc, char* args[]){

    //check to see whether init failed
    if(SDL_Init(SDL_INIT_VIDEO) > 0) std::cout << "HEY SDL_Init has failed. error" << SDL_GetError() << std::endl;

    //check image init failed
    if(!IMG_Init(IMG_INIT_PNG)) std::cout << "IMG_init has failed" << SDL_GetError() << std::endl;

    RenderWindow window("Hello Game v2.0", 640, 480);

    SDL_Texture* groundTexture = window.loadTexture("/home/dyul/SDL2__Platformer/res/gfx/Ground.png");

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
        //render the texture;
        window.renderer(groundTexture);
        //show the screen after render texture
        window.display();
    }

    window.cleanUp();
    SDL_Quit();

    return 0;
}