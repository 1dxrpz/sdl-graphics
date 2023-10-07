#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>


const int WIDTH = 800, HEIGHT = 600;



int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    

    SDL_Window *win = SDL_CreateWindow("Hello world", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);

    if (win == NULL)
    {
        std::cout << "Error: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    SDL_Event winEvent;

    while (true)
    {
        if (SDL_PollEvent(&winEvent))
        {
            if (winEvent.type == SDL_QUIT)
            {
                break;
            }
        }
        
    }
    
    SDL_DestroyWindow(win);
    SDL_Quit();

    return EXIT_SUCCESS;
}