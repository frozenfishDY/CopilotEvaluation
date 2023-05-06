/**https://leetcode.com/problems/word-search/ */
//Given an m x n grid of characters board and a string word, return true if word exists in the grid.
//The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.


bool exist(char** board, int boardSize, int* boardColSize, char * word){
    int i = 0;int j = 0;int k = 0;int l = 0;int m = 0;int n = 0;int o = 0;int p = 0;int q = 0;int r = 0;int s = 0;int t = 0;int u = 0;int v = 0;int w = 0;int x = 0;int y = 0;int z = 0;int a = 0;int b = 0;int c = 0;int d = 0;int e = 0;int f = 0;int g = 0;int h = 0;int arr[boardSize][*boardColSize];
    for(i = 0; i < boardSize; i++){
        for(j = 0; j < *boardColSize; j++){
            arr[i][j] = 0;
        }
    }
    for(k = 0; k < boardSize; k++){
        for(l = 0; l < *boardColSize; l++){
            if(board[k][l] == word[0]){
                arr[k][l] = 1;
                if(word[1] == '\0'){
                    return true;
                }
                for(m = 0; m < boardSize; m++){
                    for(n = 0; n < *boardColSize; n++){
                        if(arr[m][n] == 1){
                            if(m - 1 >= 0 && arr[m - 1][n] == 0 && board[m - 1][n] == word[1]){
                                arr[m - 1][n] = 1;
                                if(word[2] == '\0'){
                                    return true;
                                }
                                for(o = 0; o < boardSize; o++){
                                    for(p = 0; p < *boardColSize; p++){
                                        if(arr[o][p] == 1){
                                            if(o - 1 >= 0 && arr[o - 1][p] == 0 && board[o - 1][p] == word[2]){
                                                arr[o - 1][p] = 1;
                                                if(word[3] == '\0'){
                                                    return true;
                                                }
                                                for(q = 0; q < boardSize; q++){
                                                    for(r = 0; r < *boardColSize; r++){
                                                        if(arr[q][r] == 1){
                                                            if(q - 1 >= 0 && arr[q - 1][r] == 0 && board[q - 1][r] == word[3]){
                                                                arr[q - 1][r] = 1;
                                                                //...
                                                                if(word[4] == '\0'){
                                                                    return true;
                                                                }
                                                                for(s = 0; s < boardSize; s++){
                                                                    for(t = 0; t < *boardColSize; t++){
                                                                        if(arr[s][t] == 1){
                                                                            if(s - 1 >= 0 && arr[s - 1][t] == 0 && board[s - 1][t] == word[4]){
                                                                                arr[s - 1][t] = 1;
                                                                                if(word[5] == '\0'){
                                                                                    return true;
                                                                                }
                                                                                for(u = 0; u < boardSize; u++){
                                                                                    for(v = 0; v < *boardColSize; v++){
                                                                                        if(arr[u][v] == 1){
                                                                                            if(u - 1 >= 0 && arr[u - 1][v] == 0 && board[u - 1][v] == word[5]){
                                                                                                arr[u - 1][v] = 1;
                                                                                                if(word[6] == '\0'){
                                                                                                    return true;
                                                                                                }
                                                                                                for(w = 0; w < boardSize; w++){
                                                                                                    for(x = 0; x < *boardColSize; x++){
                                                                                                        if(arr[w][x] == 1){
                                                                                                            if(w - 1 >= 0 && arr[w - 1][x] == 0 && board[w - 1][x] == word[6]){
                                                                                                                arr[w - 1][x] = 1;
                                                                                                                if(word[7] == '\0'){
                                                                                                                    return true;
                                                                                                                }
                                                                                                                for(y = 0; y < boardSize; y++){
                                                                                                                    for(z = 0; z < *boardColSize; z++){
                                                                                                                        if(arr[y][z] == 1){
                                                                                                                            if(y - 1 >= 0 && arr[y - 1][z] == 0 && board[y -

}

    