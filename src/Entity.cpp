#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

#include "Entity.hpp"

Entity::Entity(float p_x, float p_y, SDL_Texture* p_texture)
:x(p_x), y(p_y), texture(p_texture)
{
}