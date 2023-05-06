/**https://leetcode.com/problems/valid-sudoku/ */
//Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
//Each row must contain the digits 1-9 without repetition.
//Each column must contain the digits 1-9 without repetition.
//Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
//Note:
//A Sudoku board (partially filled) could be valid but is not necessarily solvable.
//Only the filled cells need to be validated according to the mentioned rules.
// 


bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int n = 0;
    int o = 0;
    int p = 0;
    int q = 0;
    int r = 0;
    int s = 0;
    int t = 0;
    int u = 0;
    int v = 0;
    int w = 0;
    int x = 0;
    int y = 0;
    int z = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    int f = 0;
    int g = 0;
    int h = 0;
    int arr[9] = {0};
    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            if(board[i][j] != '.'){
                arr[board[i][j] - '1']++;
            }
        }
        for(k = 0; k < 9; k++){
            if(arr[k] > 1){
                return false;
            }
        }
        for(l = 0; l < 9; l++){
            arr[l] = 0;
        }
    }
    for(m = 0; m < 9; m++){
        for(n = 0; n < 9; n++){
            if(board[n][m] != '.'){
                arr[board[n][m] - '1']++;
            }
        }
        for(o = 0; o < 9; o++){
            if(arr[o] > 1){
                return false;
            }
        }
        for(p = 0; p < 9; p++){
            arr[p] = 0;
        }
    }
    for(q = 0; q < 9; q++){
        for(r = 0; r < 9; r++){
            if(board[q][r] != '.'){
                arr[board[q][r] - '1']++;
            }
        }
        for(s = 0; s < 9; s++){
            if(arr[s] > 1){
                return false;

}

    