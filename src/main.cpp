#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include<vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Ultils.hpp"
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
        Entity(Vector2f(32, 0), groundTexture),
        Entity(Vector2f(32, 32), groundTexture),
        Entity(Vector2f(0, 64), groundTexture),
        Entity(Vector2f(64, 64), groundTexture),
    };

    {    
        Entity plank(Vector2f(0, 32), groundTexture2);
        entities.push_back(plank);
    }

    bool gameRunning = true; 
    
    const float timeStep = 0.01;
    float accumulator = 0.0f;
    float currentTime = utils::hireTimeInSeconds();

    //to make event;
    SDL_Event event;

    //make the window show until destroy event trigger with 'X'
    while(gameRunning)
    {
        int startTick = SDL_GetTicks();

        float newTime = utils::hireTimeInSeconds();
        float frameTime = newTime - currentTime;

        currentTime = newTime;
        
        accumulator += frameTime;

        while(accumulator >= timeStep)
        {
            while(SDL_PollEvent(&event)){
                if(event.type == SDL_QUIT) gameRunning = false;
            }

            accumulator -= timeStep;

        }

        // const float alpha = accumulator / timeStep; // 50%

        //clear whole screen
        window.clearScreen();
        //render the tetexture

        for(Entity& e : entities){
            window.renderer(e);
        }

        //show the screen after render texture
        window.display();

        int frameTicks = SDL_GetTicks() - startTick;

        if(frameTicks < 1000 / window.getRefreshRate()){
            SDL_Delay(1000 / window.getRefreshRate() - frameTicks);
        }
        
    }

    window.cleanUp();
    SDL_Quit();

    return 0;
}