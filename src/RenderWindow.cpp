#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>

#include"RenderWindow.hpp"

RenderWindow::RenderWindow(const char* p_title, int p_width, int p_height):window(nullptr), render(nullptr)
{
    //according to position: title window, window postiiton x & y, width of window, height of window, show window/hide window
    //this will show the window
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_width, p_height, SDL_WINDOW_SHOWN);

    if(window == nullptr) std::cout << "Window failed to init" << SDL_GetError() << std::endl;

    //tell sdl to find if have gpu to run, mean find a way to run faster
    //this will show the program
    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{
    SDL_Texture* texture = nullptr;
    //first texutre is null, point to nothing then it point to render screen and show p_filePath
    texture = IMG_LoadTexture(render, p_filePath);
    if(texture == nullptr){
        std::cout << "Failed to load texture: " << SDL_GetError() << std::endl;
    }
    return texture;

}
void RenderWindow::cleanUp(){
    //turn off the window is SDL_Window* window;
    SDL_DestroyWindow(window);
}

void RenderWindow::clearScreen(){
    //clear whole screen which is SDL_Renderer* render;
    SDL_RenderClear(render);
}

void RenderWindow::renderer(SDL_Texture* p_texture){
    // copy texture from source and the render will point p_texture;
    SDL_RenderCopy(render, p_texture, nullptr, nullptr);
}

void RenderWindow::display(){
    //show render on screen SDL_Renderer* render;
    SDL_RenderPresent(render);
}