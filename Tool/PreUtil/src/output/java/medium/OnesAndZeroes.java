/**https://leetcode.com/problems/ones-and-zeroes/ */
//You are given an array of binary strings strs and two integers m and n.
//Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
//A set x is a subset of a set y if all elements of x are also elements of y.


class OnesAndZeroes {
    public int findMaxForm(String[] strs, int m, int n) {
        int[][] dp = new int[m + 1][n + 1];
        for(String str : strs){
            int[] cnt = count(str);
            for(int i = m; i >= cnt[0]; i--){
                for(int j = n; j >= cnt[1]; j--){
                    dp[i][j] = Math.max(dp[i][j], dp[i - cnt[0]][j - cnt[1]] + 1);
                }
            }
        }
        return dp[m][n];
        
        
    }
}

    