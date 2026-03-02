#pragma once
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

class RenderWindow2{
    public:
        RenderWindow2(const char* p_title, int p_width, int p_height);
        void cleanUp();
    private:
        SDL_Window* window;
        SDL_Renderer* render;
};

