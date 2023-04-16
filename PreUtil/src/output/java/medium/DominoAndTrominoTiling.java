/**https://leetcode.com/problems/domino-and-tromino-tiling/ */
//You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.
//Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.
//In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.


class DominoAndTrominoTiling {
    public int numTilings(int n) {
        int mod = 1000000007;
        long[] dp = new long[n + 1];
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
            dp[i] = (dp[i - 1] * 2) % mod;
            if(i >= 2){
                dp[i] = (dp[i] + dp[i - 2]) % mod;
            }
            if(i >= 3){
                dp[i] = (dp[i] + dp[i - 3]) % mod;
            }
        }
        return (int)dp[n];
        
    }
}

    