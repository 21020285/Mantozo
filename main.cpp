#include <stdio.h>
#include "CommonFunc.h"
#include "BaseObject.h"
#include <bits/stdc++.h>
BaseObject g_background;
BaseObject g_ground;
bool InitData(){
    bool sucess = true;
    int ret = SDL_Init(SDL_INIT_VIDEO);
    if (ret < 0) return false;
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    g_window = SDL_CreateWindow("Baby! I feel crazy!!",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
    if(g_window == NULL){
      sucess = false;
    }
    else{
      g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
      if(g_screen == NULL){
        sucess = false;
      }
      else{
        SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
        int imgFlags = IMG_INIT_PNG; //wrong here
        if (!(IMG_Init(imgFlags) && imgFlags)) sucess = false; //wrong here
      }
    }
   return sucess;
}

bool LoadBackground(){
    bool ret = g_background.LoadImageFile("photo/background.png", g_screen);
    return ret;
}

void close(){
    g_background.Free();
    SDL_DestroyRenderer(g_screen);
    g_screen = NULL;

    SDL_DestroyWindow(g_window);
    g_window = NULL;

    IMG_Quit();
    SDL_Quit();
}
int main( int argc, char* argv[]){
    if(!(InitData())) return -1;
    if(!(LoadBackground())) return -1;
        bool running = true;
    while(running){
        while(SDL_PollEvent(&g_event)){
         if(g_event.type == SDL_QUIT) running = false;
        }
    SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
    SDL_RenderClear(g_screen);

    g_background.Render(g_screen, NULL);

    SDL_RenderPresent(g_screen);SDL_Delay(5000);
}
    close();
	return 0;
}
