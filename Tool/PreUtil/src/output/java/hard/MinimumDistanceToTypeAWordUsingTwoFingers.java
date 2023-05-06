/**https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/ */
//You have a keyboard layout as shown above in the X-Y plane, where each English uppercase letter is located at some coordinate.
//For example, the letter 'A' is located at coordinate (0, 0), the letter 'B' is located at coordinate (0, 1), the letter 'P' is located at coordinate (2, 3) and the letter 'Z' is located at coordinate (4, 1).
//Given the string word, return the minimum total distance to type such string using only two fingers.
//The distance between coordinates (x1, y1) and (x2, y2) is |x1 - x2| + |y1 - y2|.
//Note that the initial positions of your two fingers are considered free so do not count towards your total distance, also your two fingers do not have to start at the first letter or the first two letters.


class MinimumDistanceToTypeAWordUsingTwoFingers {
    public int minimumDistance(String word) {
        int n = word.length();
        int[][][] dp = new int[n][27][27];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 27; j++) {
                Arrays.fill(dp[i][j], Integer.MAX_VALUE);
            }
        }
        return dfs(word, 0, 26, 26, dp);
        
        
    }
}
     
    