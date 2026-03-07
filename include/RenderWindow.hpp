#pragma once
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

#include "Entity.hpp"
class RenderWindow{
    public:
        RenderWindow(const char* p_title, int p_width, int p_height);

        //to load texture
        SDL_Texture* loadTexture(const char* p_filePath);

        int getRefreshRate();
        void cleanUp(); //destroy window
        void clearScreen(); //to delete buffer
        void renderer(Entity& p_entity);
        void display();
    private:
        SDL_Window* window;
        SDL_Renderer* render;
};

