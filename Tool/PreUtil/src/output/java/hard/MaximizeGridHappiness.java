/**https://leetcode.com/problems/maximize-grid-happiness/ */
//You are given four integers, m, n, introvertsCount, and extrovertsCount. You have an m x n grid, and there are two types of people: introverts and extroverts. There are introvertsCount introverts and extrovertsCount extroverts.
//You should decide how many people you want to live in the grid and assign each of them one grid cell. Note that you do not have to have all the people living in the grid.
//The happiness of each person is calculated as follows:
//Introverts start with 120 happiness and lose 30 happiness for each neighbor (introvert or extrovert).
//Extroverts start with 40 happiness and gain 20 happiness for each neighbor (introvert or extrovert).
//Neighbors live in the directly adjacent cells north, east, south, and west of a person's cell.
//The grid happiness is the sum of each person's happiness. Return the maximum possible grid happiness.


class Solution {
    public int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        int[][][] dp = new int[m + 1][n + 1][introvertsCount + 1];
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                Arrays.fill(dp[i][j], Integer.MIN_VALUE / 2);
            }
        }
        dp[0][0][0] = 0;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                for(int k = 0; k <= introvertsCount; k++){
                    int l = i * j - k;
                    if(l > extrovertsCount){
                        continue;
                    }
                    for(int a = 0; a <= k; a++){
                        int b = i * j - a;
                        if(b > l){
                            continue;
                        }
                        int cur = 0;
                        if(a > 0){
                            cur += 120;
                        }
                        if(b > 0){
                            cur += 40;
                        }
                        if(a > 1){
                            cur -= 30 * (a - 1);
                        }
                        if(b > 1){
                            cur += 20 * (b - 1);
                        }
                        if(i > 1){
                            cur -= 30 * (dp[i - 1][j][k - a] / 1000);
                            cur -= 30 * (dp[i - 1][j][k - a] % 1000);
                        }
                        if(j > 1){
                            cur -= 30 * (dp[i][j - 1][k - a] / 1000);
                            cur -= 30 * (dp[i][j - 1][k - a] % 1000);
                        }
                        dp[i][j][k] = Math.max(dp[i][j][k], cur + dp[i - 1][j][k - a] % 1000 + dp[i][j - 1][k - a] % 1000);
                    }
                }
            }
        }
        return dp[m][n][introvertsCount];
        
    }
}