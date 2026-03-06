#pragma once
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

#include "Math.hpp"

//anythings
class Entity{
public:
    Entity(Vector2f p_position, SDL_Texture* p_texture); //p_ is parameter
    Vector2f& getPos();
    SDL_Texture* getTexture();
    SDL_Rect getcurrentFrame();
private:
    //coordinate of entity
    Vector2f position;
    SDL_Rect currentFrame;
    SDL_Texture* texture;
};
