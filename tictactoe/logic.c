#include "logic.h"

void create_board(){
    board = (int *) malloc (9 * sizeof(int));
    for (int i = 0; i < 9; i++){
        *(board + i) = 0;
    }
}

int check_move(int i, int j){
    if ( *(board + i * 3 + j) == 0){return 1;}
    else {return 0;}
}

void insert_move(int i, int k){
    *(board + i) = k;
}

int check_by_index(int sector){
    if (sector < 0 || sector > 8){
        fprintf(stderr, "Warning: %s\n", COLOR_WARN "Bad board index" COLOR_NORM);
        return -1;
    }

    return *(board + sector);
}

int get_index(int i, int j){
    if ( i >= 0 && i < 3 && j >= 0 && j < 3){
        return *(board + i * 3 + j);
    }
    else{
        fprintf(stderr, "Warning: %s\n", COLOR_WARN "Bad board index" COLOR_NORM);
        return -1;
    }
}

int check_win(){
    int slot_num, i=0, j=0;
    int op = 0;
    if ( op == 0 ){ /* position = ( 0, 0 ); */
        /* Horizontal Check */
        if ( *(board + i * 3 + j) == *(board + i * 3 + (j+1)) &&
            *(board + i * 3 + j) == *(board + i * 3 + (j+2))) {return *(board + i * 3 + j);}
        /* Vertical Check */
        if ( *(board + i * 3 + j) == *(board + (i+1) * 3 + j) &&
            *(board + i * 3 + j) == *(board + (i+2) * 3 + j)) {return *(board + i * 3 + j);}
        op++;i++;j++;
    }

    if ( op == 1 ){ /* position = ( 1, 1 )
        /* Horizontal Check */
        if ( *(board + i * 3 + j) == *(board + i * 3 + (j-1)) &&
            *(board + i * 3 + j) == *(board + i * 3 + (j+1))) {return *(board + i * 3 + j);}

        /* Vertical Check */
        if ( *(board + i * 3 + j) == *(board + (i+1) * 3 + j) &&
            *(board + i * 3 + j) == *(board + (i-2) * 3 + j)) {return *(board + i * 3 + j);}

        /* Diag check 1 */
        if ( *(board + i * 3 + j) == *(board + (i+1) * 3 + (j+1)) &&
            *(board + i * 3 + j) == *(board + (i-1) * 3 + (j-1))) {return *(board + i * 3 + j);}

        /* Diag check 2 */
        if ( *(board + i * 3 + j) == *(board + (i-1) * 3 + (j+1)) &&
            *(board + i * 3 + j) == *(board + (i+1) * 3 + (j-1))) {return *(board + i * 3 + j);}
        op++;i++;j++;
    }

    if ( op == 2 ){ /* position = ( 2, 2 ) */
        /* Horizontal Check */
        if ( *(board + i * 3 + j) == *(board + i * 3 + (j-1)) &&
            *(board + i * 3 + j) == *(board + i * 3 + (j-2))) {return *(board + i * 3 + j);}
        /* Vertical Check */
        if ( *(board + i * 3 + j) == *(board + (i-1) * 3 + j) &&
            *(board + i * 3 + j) == *(board + (i-2) * 3 + j)) {return *(board + i * 3 + j);}
    }
    return 0;
}

void clean_logic(){
    free(board);
}
