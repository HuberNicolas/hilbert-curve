
#include <SDL2/SDL.h>
#include <stdio.h>

SDL_Window *win;
SDL_Renderer *ren;


/*
#include <SDL2/SDL.h>

int main(int arg, char* args[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Quit();
	return 0;
}
*/


void drawsquare(double x, double y, double l) {
	//SDL_SetRenderDrawColor(ren, l*120, x*140, l*4, 255);
	SDL_SetRenderDrawColor(ren, 0, 0, 255-x, 255);
	SDL_Rect rect = { x, y, l, l }; // x, y, width, height
	SDL_RenderFillRect(ren, &rect);
	SDL_RenderDrawRect(ren, &rect);
	SDL_RenderPresent(ren);
}

void TSquareFractal(double x, double y, double length, int i) {
   if(i == 0) return;
    drawsquare(x,y,length);
    SDL_Delay(0);
	TSquareFractal(x-length/4, y-length/4, length/2, i-1);
	TSquareFractal(x-length/4, y+3*length/4, length/2, i-1);
	TSquareFractal(x+3*length/4, y-length/4, length/2, i-1);
	TSquareFractal(x+3*length/4, y+3*length/4, length/2, i-1);

}


	int main(int argc, char *argv[]) {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("SDL could not initialize");
	}


    int iters = 9;
	SDL_CreateWindowAndRenderer(1000, 1000, 0, &win, &ren);
	SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
	SDL_RenderClear(ren);

	SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
	TSquareFractal(300, 300, 400, iters);

	SDL_Event e;
	do { SDL_PollEvent(&e); } while (e.type != SDL_MOUSEBUTTONDOWN);
}

// Linux: gcc task3b.c -o task3b -lm -lSDL2; ./task3b
