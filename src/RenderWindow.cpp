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

void RenderWindow::cleanUp(){
    //turn off the window
    SDL_DestroyWindow(window);
}