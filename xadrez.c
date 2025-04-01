#include <stdio.h>

#define SIZE 8

// Função para exibir o tabuleiro
void printBoard(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Movimentação do Bispo (diagonais)
void moveBishop(int board[SIZE][SIZE], int x, int y) {
    for (int i = 1; i < SIZE; i++) {
        if (x + i < SIZE && y + i < SIZE) board[x + i][y + i] = 1;
        if (x - i >= 0 && y - i >= 0) board[x - i][y - i] = 1;
        if (x + i < SIZE && y - i >= 0) board[x + i][y - i] = 1;
        if (x - i >= 0 && y + i < SIZE) board[x - i][y + i] = 1;
    }
}

// Movimentação da Torre (linhas e colunas)
void moveRook(int board[SIZE][SIZE], int x, int y) {
    for (int i = 0; i < SIZE; i++) {
        board[x][i] = 1; // Linha
        board[i][y] = 1; // Coluna
    }
}

// Movimentação da Rainha (combina torre e bispo)
void moveQueen(int board[SIZE][SIZE], int x, int y) {
    moveBishop(board, x, y);
    moveRook(board, x, y);
}

// Movimentação do Cavalo (padrão "L")
void moveKnight(int board[SIZE][SIZE], int x, int y) {
    int moves[8][2] = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };
    
    for (int i = 0; i < 8; i++) {
        int nx = x + moves[i][0];
        int ny = y + moves[i][1];
        if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE) {
            board[nx][ny] = 1;
        }
    }
}

int main() {
    int board[SIZE][SIZE] = {0};
    int x = 3, y = 3; // Posição inicial
    
    printf("Movimentação do Bispo:\n");
    moveBishop(board, x, y);
    printBoard(board);
    
    printf("Movimentação da Torre:\n");
    for (int i = 0; i < SIZE; i++) for (int j = 0; j < SIZE; j++) board[i][j] = 0;
    moveRook(board, x, y);
    printBoard(board);
    
    printf("Movimentação da Rainha:\n");
    for (int i = 0; i < SIZE; i++) for (int j = 0; j < SIZE; j++) board[i][j] = 0;
    moveQueen(board, x, y);
    printBoard(board);
    
    printf("Movimentação do Cavalo:\n");
    for (int i = 0; i < SIZE; i++) for (int j = 0; j < SIZE; j++) board[i][j] = 0;
    moveKnight(board, x, y);
    printBoard(board);
    
    return 0;
}
