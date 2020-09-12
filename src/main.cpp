#include "Logger.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main()
{
    Logger logger;

    if (SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) != 0)
    {
        logger.printLine("Failed to initialize the SDL2 library");
    }

    SDL_Window *window = SDL_CreateWindow("SDL Demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 450, 0);

    if (!window)
    {
        logger.printLine("Failed to initialise window");
        return -1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer)
    {
        logger.printLine("Error creating renderer");
        return -1;
    }

    SDL_SetRenderDrawColor(renderer, 124, 218, 254, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    SDL_Event event;
    bool running = true;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                running = false;
                break;
            }
        }
    }

    SDL_Quit();
}