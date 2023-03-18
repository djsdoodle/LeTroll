#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include "leimage.h"

#ifdef _WIN32
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){
#else
int main(int argc, char* argv[]){
#endif
    SDL_Window *window;
    SDL_Surface surface;
    SDL_Event event;
    bool quit = false;
    
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Le Mogus Show", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 700, 700, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    SDL_Surface *letroll;
    letroll = SDL_LoadBMP_RW(SDL_RWFromConstMem(letroll_bmp, sizeof(letroll_bmp)), 1);
    
    SDL_SetWindowIcon(window, letroll);

    while (!quit){
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT)
            quit = true;

        SDL_BlitScaled(letroll, NULL, SDL_GetWindowSurface(window), NULL);
        SDL_UpdateWindowSurface(window);
    }


    SDL_FreeSurface(letroll);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}