#include "visuals.h"

void create(int w, int h){
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(
        "Tic-Tac-Toe",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        w,h, SDL_WINDOW_SHOWN );
    if (window == NULL){
        fprintf(stderr, "An error occurred: %s\n", COLOR_ERRO "NULL WINDOW" COLOR_NORM);
        exit(EXIT_FAILURE);
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == NULL){
        fprintf(stderr, "An error occurred: %s\n", COLOR_ERRO "NULL RENDERER" COLOR_NORM);
        exit(EXIT_FAILURE);
    }
    refresh();
}

void create_board_lines(){
    int w = 200; /* ill make it not hard coded later... */
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    for (int i = 1; i < 3; i++){
        SDL_RenderDrawLine(renderer,0, w*i, 600, w*i );
        SDL_RenderDrawLine(renderer, w*i, 0, w*i, 600);
    }
}



void draw (int w, int h, int sector, int player_turn){
    int x_stride = w/3;
    int y_stride = w/3; /* if you change the w or h to something not div by 3, you may get problems */
    int i = sector / 3;
    int w2 = x_stride/2;
    if (player_turn){
        draw_x((x_stride * (sector % 3) + w2), (y_stride * (i+1) - w2 ), w2);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        //SDL_RenderPresent(renderer);
    }
    else{
        draw_c((x_stride * (sector % 3) + w2), (y_stride * (i+1) - w2 ));
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderPresent(renderer);
    }

}

void draw_x(int x, int y, int w){
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderDrawLine(renderer, x-w, y-w, x+w, y+w);
    SDL_RenderDrawLine(renderer, x+w, y-w, x-w, y+w);


}

void draw_c(int x, int y){
    //SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    const int r = 90;
    const int points = 650; // Number of points used to approximate the circle

    // Calculate the angle between each point on the circumference
    const double angleIncrement = (2 * M_PI) / points;

    // Draw the polygon approximation of the circle
    for (int i = 0; i < points; ++i) {
        double angle = i * angleIncrement;
        double c = cos(angle); double s = sin(angle);
        int px = x + (int)(r * c);
        int py = y + (int)(r * s);
        SDL_RenderDrawPoint(renderer, px, py);
    }
    //SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}


/*void draw_c(int x, int y, int w){
    int r = 100;
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    int a = r;
    int b = 0;
    int error = 1 - a;
    while ( a >= b)
    {
        SDL_RenderDrawPoint(renderer, x + a, y + b);
        SDL_RenderDrawPoint(renderer, x + b, y + a);
        SDL_RenderDrawPoint(renderer, x - b, y + a);
        SDL_RenderDrawPoint(renderer, x - a, y + b);
        SDL_RenderDrawPoint(renderer, x - a, y - b);
        SDL_RenderDrawPoint(renderer, x - b, y - a);
        SDL_RenderDrawPoint(renderer, x + b, y - a);
        SDL_RenderDrawPoint(renderer, x + a, y - b);

        b++;

        if (error < 0)
        {
            error += 2 * y + 1;
        }
        else
        {
            a--;
            error += 2 * (y - x + 1);
        }
    }


}*/


void refresh(){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    create_board_lines();
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderPresent(renderer);
}


int check_window(){
    if (window == NULL){return 0;}
    else {return 1;}
}
int check_renderer(){
    if (renderer == NULL){return 0;}
    else {return 1;}
}

void clean_up(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
