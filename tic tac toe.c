#include <stdio.h>

// Function to print the game board
void print_board(char board[3][3]) {
    printf("\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Function to check if a player has won
int check_win(char board[3][3], char player) {
    int i, j;
    // Check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }
    // Check columns
    for (j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;
        }
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    return 0;
}

// Function to get user input
void get_input(int *row, int *col) {
    printf("Enter row (1-3): ");
    scanf("%d", row);
    printf("Enter column (1-3): ");
    scanf("%d", col);
    // Convert input to array indices
    (*row)--;
    (*col)--;
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char player1 = 'X';
    char player2 = 'O';
    int current_player = 1;
    int row, col;
    int moves_left = 9;
    int game_over = 0;
    while (!game_over && moves_left > 0) {
        printf("Player %d's turn:\n", current_player);
        print_board(board);
        get_input(&row, &col);
        if (board[row][col] == ' ') {
            if (current_player == 1) {
                board[row][col] = player1;
            } else {
                board[row][col] = player2;
            }
            if (check_win(board, board[row][col])) {
                printf("Player %d wins!\n", current_player);
                game_over = 1;
            }
            current_player = (current_player == 1) ? 2 : 1;
            moves_left--;
        } else {
            printf("That spot is already taken.\n");
        }
    }
    if (!game_over) {
        printf("It's a tie!\n");
    }
    print_board(board);
    return 0;
}
