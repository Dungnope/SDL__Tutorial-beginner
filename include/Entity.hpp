#pragma once
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

//anythings
class Entity{
public:
    Entity(float p_x, float p_y, SDL_Texture* p_texture); //p_ is parameter
    float getX();
    float getY();
    SDL_Texture* getTexture();
    SDL_Rect getcurrentFrame();
private:
    //coordinate of entity
    double x, y;
    SDL_Rect currentFrame;
    SDL_Texture* texture;
};
