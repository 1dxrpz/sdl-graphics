#define SDL_MAIN_HANDLED
#define PI 3.14159265359
#include <iostream>
//#include <SDL2/SDL.h>
#include "src/lib/matrix.h"
#include <math.h>

const int WIDTH = 800, HEIGHT = 600;


//WinMain

int main(int argc, char *argv[])
{
    srand((unsigned) time(NULL));

    vec3* vec = new vec3(1, 1, 1);
    
    vec
        ->toMatrix()
        ->rotate(90 * PI / 180, 0 * PI / 180, 0 * PI / 180)
        ->toVec3()
        ->display();

    // mat2->transpose()->display();
    // std::cout << std::endl;
    

    /*
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *win = SDL_CreateWindow("Hello world", 
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED, 
            WIDTH,
            HEIGHT, 
            SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_OPENGL);
    SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(renderer, 100, 100, 300, 300);
    SDL_RenderPresent(renderer);

    if (win == NULL)
    {
        std::cout << "Error: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    mesh Mesh;
    
    SDL_Event winEvent;

    while (true)
    {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        for (int i = 0; i < 360; i++)
        {
            SDL_RenderDrawLine(renderer, 
                (int)(std::cos(i * PI / 180) * 200) + 200,
                (int)(std::sin(i * PI / 180) * 200) + 200,
                (int)(std::cos((i + 1) * PI / 180) * 200) + 200,
                (int)(std::sin((i + 1) * PI / 180) * 200) + 200); 
        }
        SDL_RenderPresent(renderer);
        if (SDL_PollEvent(&winEvent))
        {
            std::cout << winEvent.type << std::endl;
            if (winEvent.type == SDL_QUIT) {
                
            }
            if (winEvent.type == SDL_QUIT)
            {
                break;
            }
        }
        
    }
    
    SDL_DestroyWindow(win);
    SDL_Quit();
    */
    return EXIT_SUCCESS;
}