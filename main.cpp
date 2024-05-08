#include <SDL2/SDL.h>
#include <random>

int main( int argc, char * argv[] )
{
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    SDL_CreateWindowAndRenderer(50 *20, 40 * 20, 0,
                                &window, &renderer);
    SDL_RenderSetScale(renderer, 20, 20);
    SDL_Event e;

    int x = 25;
    int y = 20;

    std::random_device dev;
    std::uniform_int_distribution<uint8_t> nd(0, 4);
    bool running = true;

    while(running)
    {
        while(SDL_PollEvent(&e))
        {
            if(e.type == SDL_QUIT){ running = false; }
        }
        uint8_t dir = nd(dev);

        switch(dir)
        {
            case 0:
                x -= 1;
                y -=1;
                break;
            case 1:
                x += 1;
                y -=1;
                break;
            case 2:
                x += 1;
                y +=1;
                break;
            case 3:
                x -= 1;
                y +=1;
                break;
        }
        SDL_SetRenderDrawColor(renderer,
                               60 * dir % 85,
                               60 * dir % 50,
                               60 * dir % 220,
                               255);
        SDL_RenderDrawPoint(renderer, x, y);
        SDL_RenderPresent(renderer);

        if(x > 50 || x < 0 || y > 50 || y < 0)
        {
            x = 25;
            y = 25;
        }

        SDL_Delay(50);
    }
    return 0;
}
