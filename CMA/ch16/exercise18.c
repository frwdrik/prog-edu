typedef enum {PAWN, KNIGTH, BISHOP, ROOK, QUEEN, KING, EMPTY} Piece;
typedef enum {BLACK, WHITE} Color;

typedef struct {Piece piece; Color color;} Square;

Square board[8][8];

Square initialize_board(Square *a);

int main(void)
{
    return 0;
}

Square initialize_board(Square *a)
{
    int i, j;

    for (i = 0; i < 8; i++){ /* Inserts the white pawns */
	a[1][i].piece = PAWN;
	a[1][i].color = WHITE;
    }

    for (i = 0; i < 8; i++){ /* Inserts the black pawns */
	a[6][i].piece = PAWN;
	a[6][i].color = BLACK;
    }	    

    for (i = 0; i < 8; i++)
	a[0][i].color = WHITE;
    
    a[0][0].piece = a[0][7].piece = ROOK;
    a[0][1].piece = a[0][6].piece = KNIGTH;
    a[0][2].piece = a[0][5].piece = BISHOP;
    a[0][3].piece = KING;
    a[0][4].piece = QUEEN;

    
    for (i = 0; i < 8; i++)
	a[0][i].color = WHITE;
    
    a[7][7].piece = a[7][7].piece = ROOK;
    a[7][1].piece = a[7][6].piece = KNIGTH;
    a[7][2].piece = a[7][5].piece = BISHOP;
    a[7][3].piece = KING;
    a[7][4].piece = QUEEN;

    for (i = 2; i <= 5; i++)    /* Initialize the empty tiles */
	for (j = 0; j < 8; j++) {
	    a[i][j].piece = EMPTY;
	    a[i][j].color = BLACK;
	}
}
