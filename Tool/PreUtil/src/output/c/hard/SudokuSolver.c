/**https://leetcode.com/problems/sudoku-solver/ */
//Write a program to solve a Sudoku puzzle by filling the empty cells.
//A sudoku solution must satisfy all of the following rules:
//Each of the digits 1-9 must occur exactly once in each row.
//Each of the digits 1-9 must occur exactly once in each column.
//Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
//The '.' character indicates empty cells.


void solveSudoku(char** board, int boardSize, int* boardColSize){
    int i = 0, j = 0;
    int **row = (int **)malloc(9 * sizeof(int *));
    int **col = (int **)malloc(9 * sizeof(int *));
    int **box = (int **)malloc(9 * sizeof(int *));
    for(i = 0; i < 9; i++){
        row[i] = (int *)malloc(9 * sizeof(int));
        col[i] = (int *)malloc(9 * sizeof(int));
        box[i] = (int *)malloc(9 * sizeof(int));
    }
    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            row[i][j] = 0;
            col[i][j] = 0;
            box[i][j] = 0;
        }
    }
    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            if(board[i][j] != '.'){
                row[i][board[i][j] - '1'] = 1;
                col[j][board[i][j] - '1'] = 1;
                box[i / 3 * 3 + j / 3][board[i][j] - '1'] = 1;
            }
        }
    }
    solveSudokuHelper(board, boardSize, boardColSize, row, col, box, 0, 0);

}

    