#include "visuals.h"
#include "logic.h"



int get_sector(int w, int h, int x, int y){
        int y_stride = h / 3;
        int x_stride = w / 3;
        int i = 0, j = 0;
        for (int k = 0; k < 3; k++){
            if ( y / y_stride == k){i = k;}
        }
        for (int k = 0; k < 3; k++){
            if ( x / x_stride == k){j = k;}
        }
        return (i * 3 + j);

}

int computer_turn(){
    /* basic version
    just guesses random spots until it finds one that is available. Not the best way to do it
    but this was quick to implement.
    */
    int loop = 1;
    while (loop){
        int guess = rand() % 9;
        if ( check_by_index(guess) == 0){
            loop = 0;
            return guess;
        }
    }
    return 0;
}


int main(){
    create(600,600);
    create_board();
    int player_turn = 1;
    int exit = 0;
    SDL_Event event;
    int win = 0;
    while (!exit){
        if (player_turn){ /* player's turn */
            while (SDL_PollEvent(&event)){
                if (event.type == SDL_QUIT){
                    exit = 1;
                }
                else if (event.type == SDL_MOUSEBUTTONDOWN) {
                    if (event.button.button == SDL_BUTTON_LEFT){
                        int m_x = event.button.x;
                        int m_y = event.button.y;
                        printf("(x,y) = (%d,%d)\n",m_x,m_y);
                        int s = get_sector(600,600,m_x,m_y);
                        printf("sector: %d\n", s);
                        if (check_by_index(s) == 0){
                            insert_move(s,1);
                            draw(600,600,s,player_turn);
                            player_turn = 0;
                            win = check_win();
                        }
                        else{
                            printf("%s\n","Whoops! That Spot is already taken");
                        }

                    }
                }
            }
        }
        else { /* computer's turn */
            int c_move = computer_turn();
            if (check_by_index(c_move) == 0){
                insert_move(c_move,2);
                draw(600,600,c_move,player_turn);
                printf("computer move: sector: %d\n",c_move);
                win = check_win();
                player_turn = 1;
            }

        }
        //int win = check_win();
        if (win == 1){ /* Player Wins */
            printf("%s\n","Player Wins!!!");
            exit = 1;
            break;
        }
        else if (win == 2){ /* Computer Wins */
            printf("%s\n","Computer Wins!!!");
            exit = 1;
            break;
        }
    }



    clean_logic();
    clean_up();



    return 0;

}
