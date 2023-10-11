#define SDL_MAIN_HANDLED
#define PI 3.14159265359
#include <iostream>
#include <SDL2/SDL.h>
#include "src/lib/matrix.h"
#include <math.h>

const int WIDTH = 800, HEIGHT = 600;
#include <iomanip>

//WinMain

int main(int argc, char *argv[])
{
    srand((unsigned) time(NULL));

    float x = 90 * PI / 180;
    
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);

    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 32);

    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 2);

    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1); 

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");

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
    
    SDL_Event winEvent;

    int offsetX = WIDTH / 2;
    int offsetY = HEIGHT / 2;
    float offset = 0;

    while (true)
    {
        try
        {
            /* code */
        
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        
        std::vector<vec3*> vertices;
    
        vertices.push_back(new vec3(0, 0, 0));
        vertices.push_back(new vec3(0, 1, 0));
        vertices.push_back(new vec3(0, 1, 1));
        vertices.push_back(new vec3(0, 0, 1));

        vertices.push_back(new vec3(1, 0, 0));
        vertices.push_back(new vec3(1, 1, 0));
        vertices.push_back(new vec3(1, 1, 1));
        vertices.push_back(new vec3(1, 0, 1));

        vertices.push_back(new vec3(0, 1, 0));
        vertices.push_back(new vec3(1, 1, 0));
        vertices.push_back(new vec3(1, 1, 1));
        vertices.push_back(new vec3(0, 1, 1));

        vertices.push_back(new vec3(0, 0, 1));
        vertices.push_back(new vec3(1, 0, 1));
        vertices.push_back(new vec3(1, 1, 1));
        vertices.push_back(new vec3(0, 1, 1));

        vertices.push_back(new vec3(0, 0, 0));
        vertices.push_back(new vec3(0, 0, 1));
        vertices.push_back(new vec3(1, 0, 1));
        vertices.push_back(new vec3(1, 0, 0));
        
        std::vector<vec3*> points;
        offset += 0.02f;
        for (int i = 0; i < vertices.size(); i++)
        {
            vec3* point = vertices[i]
                ->toMatrix()
                ->scale(10, 10, 10)
                ->translate(0, 0, 25)
                ->rotate(offset, offset, offset)
                ->project(1.0f, 90.0f * PI / 180.0f, 1000.0f, 0.01f)
                ->scale(5, 5, 5)
                ->toVec3();
            points.push_back(point);
        }

        for (int i = 0; i < points.size(); i++)
        {
            int nextIndex = i == points.size() - 1 ? 0 : i + 1;
            if (nextIndex % 4 != 0)
            {
            SDL_RenderDrawLineF(renderer,
                points[i]->x + offsetX, points[i]->y + offsetY,
                points[nextIndex]->x + offsetX, points[nextIndex]->y + offsetY);
            }
        }

        SDL_RenderPresent(renderer);
        if (SDL_PollEvent(&winEvent))
        {
            if (winEvent.type == SDL_QUIT)
            {
                break;
            }
        }
        }
        catch(const std::exception& e)
        {
            SDL_Log(e.what());
        }
    }
    
    SDL_DestroyWindow(win);
    SDL_Quit();
    
    return EXIT_SUCCESS;
}