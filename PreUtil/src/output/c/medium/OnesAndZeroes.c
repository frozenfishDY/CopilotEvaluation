/**https://leetcode.com/problems/ones-and-zeroes/ */
//You are given an array of binary strings strs and two integers m and n.
//Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
//A set x is a subset of a set y if all elements of x are also elements of y.


int findMaxForm(char ** strs, int strsSize, int m, int n){
    int** dp = (int**)malloc(sizeof(int*) * (m + 1));
    for(int i = 0; i <= m; i++){
        dp[i] = (int*)malloc(sizeof(int) * (n + 1));
        for(int j = 0; j <= n; j++){
            dp[i][j] = 0;
        }
    }
    for(int i = 0; i < strsSize; i++){
        int zero = 0;
        int one = 0;
        for(int j = 0; strs[i][j] != '\0'; j++){
            if(strs[i][j] == '0'){
                zero++;
            }else{
                one++;
            }
        }
        for(int j = m; j >= zero; j--){
            for(int k = n; k >= one; k--){
                dp[j][k] = fmax(dp[j][k], dp[j - zero][k - one] + 1);
            }
        }
    }
    return dp[m][n];

}

    