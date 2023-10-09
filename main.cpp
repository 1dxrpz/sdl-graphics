#define SDL_MAIN_HANDLED
#define PI 3.14159265359
#include <iostream>
//#include <SDL2/SDL.h>
#include "src/lib/matrix.h"


const int WIDTH = 800, HEIGHT = 600;


//WinMain

int main(int argc, char *argv[])
{
    srand((unsigned) time(NULL));

    matrix4* mat1 = new matrix4({
        {1, 5, 1, -4},
        {-3, 13, 7, 6},
        {-1, -23, 2, 45},
        {1, 2, 3, 4}
    });
    matrix4* mat2 = new matrix4({
        {1, 0, 0, 1},
        {0, 1, 0, 2},
        {0, 0, 1, 3},
        {0, 0, 0, 1}
    });

    mat2->translate(1, 0, 0)->display();
    // std::cout << std::endl;
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