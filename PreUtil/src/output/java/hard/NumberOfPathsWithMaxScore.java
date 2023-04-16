/**https://leetcode.com/problems/number-of-paths-with-max-score/ */
//You are given a square board of characters. You can move on the board starting at the bottom right square marked with the character 'S'.
//You need to reach the top left square marked with the character 'E'. The rest of the squares are labeled either with a numeric character 1, 2, ..., 9 or with an obstacle 'X'. In one move you can go up, left or up-left (diagonally) only if there is no obstacle there.
//Return a list of two integers: the first integer is the maximum sum of numeric characters you can collect, and the second is the number of such paths that you can take to get that maximum sum, taken modulo 10^9 + 7.
//In case there is no path, return [0, 0].


class NumberOfPathsWithMaxScore {
    public int[] pathsWithMaxScore(List<String> board) {
        int n = board.size();
        int[][][] dp = new int[n][n][2];
        dp[n - 1][n - 1][0] = 0;
        dp[n - 1][n - 1][1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (board.get(i).charAt(n - 1) == 'X') {
                break;
            }
            dp[i][n - 1][0] = dp[i + 1][n - 1][0] + board.get(i).charAt(n - 1) - '0';
            dp[i][n - 1][1] = 1;
        }
        for (int j = n - 2; j >= 0; j--) {
            if (board.get(n - 1).charAt(j) == 'X') {
                break;
            }
            dp[n - 1][j][0] = dp[n - 1][j + 1][0] + board.get(n - 1).charAt(j) - '0';
            dp[n - 1][j][1] = 1;
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                if (board.get(i).charAt(j) == 'X') {
                    continue;
                }
                int max = Math.max(dp[i + 1][j][0], Math.max(dp[i][j + 1][0], dp[i + 1][j + 1][0]));
                if (max == dp[i + 1][j][0]) {
                    dp[i][j][1] = (dp[i][j][1] + dp[i + 1][j][1]) % 1000000007;
                }
                if (max == dp[i][j + 1][0]) {
                    dp[i][j][1] = (dp[i][j][1] + dp[i][j + 1][1]) % 1000000007;
                }
                if (max == dp[i + 1][j + 1][0]) {
                    dp[i][j][1] = (dp[i][j][1] + dp[i + 1][j + 1][1]) % 1000000007;
                    
        
    }
}
     
    