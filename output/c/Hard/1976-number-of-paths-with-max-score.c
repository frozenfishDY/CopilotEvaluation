/**https://leetcode.com/problems/number-of-paths-with-max-score/ */
//You are given a square board of characters. You can move on the board starting at the bottom right square marked with the character 'S'.
//You need to reach the top left square marked with the character 'E'. The rest of the squares are labeled either with a numeric character 1, 2, ..., 9 or with an obstacle 'X'. In one move you can go up, left or up-left (diagonally) only if there is no obstacle there.
//Return a list of two integers: the first integer is the maximum sum of numeric characters you can collect, and the second is the number of such paths that you can take to get that maximum sum, taken modulo 10^9 + 7.
//In case there is no path, return [0, 0].


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pathsWithMaxScore(char ** board, int boardSize, int* returnSize){
    int* ans = (int*)malloc(sizeof(int)*2);
    *returnSize = 2;
    int i,j;
    int n = boardSize;
    int** dp = (int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++){
        dp[i] = (int*)malloc(sizeof(int)*n);
        for(j=0;j<n;j++){
            dp[i][j] = 0;
        }
    }
    int** dp2 = (int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++){
        dp2[i] = (int*)malloc(sizeof(int)*n);
        for(j=0;j<n;j++){
            dp2[i][j] = 0;
        }
    }
    dp[n-1][n-1] = 0;
    dp2[n-1][n-1] = 1;
    for(i=n-2;i>=0;i--){
        if(board[i][n-1] == 'X'){
            dp[i][n-1] = 0;
            dp2[i][n-1] = 0;
        }
        else{
            dp[i][n-1] = dp[i+1][n-1] + board[i][n-1] - '0';
            dp2[i][n-1] = dp2[i+1][n-1];
        }
    }
    for(i=n-2;i>=0;i--){
        if(board[n-1][i] == 'X'){
            dp[n-1][i] = 0;
            dp2[n-1][i] = 0;
        }
        else{
            dp[n-1][i] = dp[n-1][i+1] + board[n-1][i] - '0';
            dp2[n-1][i] = dp2[n-1][i+1];
        }
    }
    for(i=n-2;i>=0;i--){
        for(j=n-2;j>=0;j--){
            if(board[i][j] == 'X'){
                dp[i][j] = 0;
                dp2[i][j] = 0;
            }
            else{
                int max = 0;
                int count = 0;
                if(dp[i+1][j] > max){
                    max = dp[i+1][j];
                    count = dp2[i+1][j];
                        

}

    