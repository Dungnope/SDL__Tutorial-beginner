#pragma once
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

class RenderWindow{
    public:
        RenderWindow(const char* p_title, int p_width, int p_height);

        //to load texture
        SDL_Texture* loadTexture(const char* p_filePath);
        void cleanUp(); //destroy window
        void clearScreen();
        void renderer(SDL_Texture* p_texture);
        void display();
    private:
        SDL_Window* window;
        SDL_Renderer* render;
};

