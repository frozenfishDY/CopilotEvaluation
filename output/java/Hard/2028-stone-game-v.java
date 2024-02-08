/**https://leetcode.com/problems/stone-game-v/ */
//There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.
//In each round of the game, Alice divides the row into two non-empty rows (i.e. left row and right row), then Bob calculates the value of each row which is the sum of the values of all the stones in this row. Bob throws away the row which has the maximum value, and Alice's score increases by the value of the remaining row. If the value of the two rows are equal, Bob lets Alice decide which row will be thrown away. The next round starts with the remaining row.
//The game ends when there is only one stone remaining. Alice's is initially zero.
//Return the maximum score that Alice can obtain.


class StoneGameV {
    public int stoneGameV(int[] stoneValue) {
        int n = stoneValue.length;
        int[] prefix = new int[n + 1];
        for(int i = 1; i <= n; i++){
            prefix[i] = prefix[i - 1] + stoneValue[i - 1];
        }
        int[][] dp = new int[n][n];
        for(int i = n - 1; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                for(int k = i; k < j; k++){
                    int left = prefix[k + 1] - prefix[i];
                    int right = prefix[j + 1] - prefix[k + 1];
                    if(left < right){
                        dp[i][j] = Math.max(dp[i][j], dp[i][k] + left);
                    }else if(left > right){
                        dp[i][j] = Math.max(dp[i][j], dp[k + 1][j] + right);
                    }else{
                        dp[i][j] = Math.max(dp[i][j], dp[i][k] + left);
                        dp[i][j] = Math.max(dp[i][j], dp[k + 1][j] + right);
                    }
                }
            }
        }
        return dp[0][n - 1];
        
    }
}
     
    