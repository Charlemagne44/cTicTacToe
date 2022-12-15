#include <stdio.h>

void printBoard(char board[][3]) {
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 3; j ++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[][3], int row, int col) {
    // column
    if (board[row][col] == board[row][(col+1)%3] && board[row][col] == board[row][(col+2)%3])
        return 1;
    // row
    if (board[row][col] == board[(row+1)%3][col] && board[row][col] == board[(row+2)%3][col])
        return 1;
    // forward diagonal
    if (board[row][col] == board[(row+1)%3][(col+1)%3] && board[row][col] == board[(row+2)%3][(col+2)%3])
        return 1;
    // reverse diagonal
    if (board[row][col] == board[(row+2)%3][(col+1)%3] && board[row][col] == board[(row+1)%3][(col+2)%3])
        return 1;
    // nothing
    return 0;
}

int main() {
    char board[3][3] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};
    // running loops
    int over = 0;
    char player = 'x';
    while (!over) {
        // print turn
        printf("%c players turn\n", player);

        // print board
        printBoard(board);

        // take input for player active
        int row, col;
        printf("Enter row\n");
        scanf("%d", &row);
        printf("Enter col:\n");
        scanf("%d", &col);
        row = row-1;
        col = col-1;

        // check if move valid
        if (row > 3 || row < 0 || col > 3 || col < 0) {
            printf("invalid move\n");
            continue;
        }
        else if (board[row][col] == '-') {
            board[row][col] = player;
        }
        else {
            printf("invalid move\n");
            continue;
        }

        //check for win from move just made
        if(checkWin(board, row, col)) {
            printf("Player: %c Wins!\n", player);
            over = 1;
        }

        // switch player
        if (player == 'x') {
            player = 'o';
        }
        else {
            player = 'x';
        } 

        printf("\n");
    }
    return 0;
}