#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

int main(int argc, char *argv[]) {
  SDL_Surface *image;

  if (argc != 2) {
    printf("please enter filename\n");
    return 1;
  }
  SDL_Init(SDL_INIT_EVERYTHING);
  IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_TIF);
  image = IMG_Load(argv[1]);
  if (!image) {
    printf("IMG_Load: %s\n", IMG_GetError());
    return 1;
  }
  SDL_Window *window =
      SDL_CreateWindow("Getting Started", SDL_WINDOWPOS_UNDEFINED,
                       SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);

  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);
  SDL_FreeSurface(image);
  while (1) {
    SDL_Event e;
    if (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) {
        break;
      }
    }

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
  }
  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  IMG_Quit();
  SDL_Quit();

  return 0;
}

