#include <SDL2/SDL.h>
#include <iostream>

// Kích thước màn hình
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main(int argc, char* args[]) {
    // 1. Khởi tạo SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    
    std::cout << "Test" << std::endl;

    // 2. Tạo cửa sổ game
    SDL_Window* window = SDL_CreateWindow("First game test for structure - Test Movement", 
                            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
                            SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // 3. Tạo bộ dựng hình (Renderer)
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // 4. Khởi tạo nhân vật (Hình chữ nhật)
    SDL_Rect player = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 50, 50 }; // x, y, width, height
    int moveSpeed = 5;

    // 5. Vòng lặp Game (Game Loop)
    bool quit = false;
    SDL_Event e;

    while (!quit) {
        // Xử lý sự kiện (Input)
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            // Kiểm tra bấm phím
            else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_UP:    player.y -= moveSpeed; break;
                    case SDLK_DOWN:  player.y += moveSpeed; break;
                    case SDLK_LEFT:  player.x -= moveSpeed; break;
                    case SDLK_RIGHT: player.x += moveSpeed; break;
                }
            }
        }

        // --- XỬ LÝ ĐỒ HỌA ---
        // Màu nền (Đen)
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Vẽ nhân vật (Xanh lá)
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderFillRect(renderer, &player);

        // Cập nhật màn hình
        SDL_RenderPresent(renderer);
        
        // Giới hạn tốc độ vòng lặp (khoảng 60 FPS)
        SDL_Delay(16);
    }

    // 6. Giải phóng bộ nhớ
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}