/**https://leetcode.com/problems/freedom-trail/ */
//In the video game Fallout 4, the quest "Road to Freedom" requires players to reach a metal dial called the "Freedom Trail Ring" and use the dial to spell a specific keyword to open the door.
//Given a string ring that represents the code engraved on the outer ring and another string key that represents the keyword that needs to be spelled, return the minimum number of steps to spell all the characters in the keyword.
//Initially, the first character of the ring is aligned at the "12:00" direction. You should spell all the characters in key one by one by rotating ring clockwise or anticlockwise to make each character of the string key aligned at the "12:00" direction and then by pressing the center button.
//At the stage of rotating the ring to spell the key character key[i]:
//You can rotate the ring clockwise or anticlockwise by one place, which counts as one step. The final purpose of the rotation is to align one of ring's characters at the "12:00" direction, where this character must equal key[i].
//If the character key[i] has been aligned at the "12:00" direction, press the center button to spell, which also counts as one step. After the pressing, you could begin to spell the next character in the key (next stage). Otherwise, you have finished all the spelling.


class FreedomTrail {
    public int findRotateSteps(String ring, String key) {
        int m = ring.length();
        int n = key.length();
        int[][] dp = new int[n][m];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], Integer.MAX_VALUE);
        }
        for (int j = 0; j < m; j++) {
            if (ring.charAt(j) == key.charAt(0)) {
                dp[0][j] = Math.min(j, m - j) + 1;
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (ring.charAt(j) != key.charAt(i)) {
                    continue;
                }
                for (int k = 0; k < m; k++) {
                    if (dp[i - 1][k] == Integer.MAX_VALUE) {
                        continue;
                    }
                    int diff = Math.abs(j - k);
                    dp[i][j] = Math.min(dp[i][j], dp[i - 1][k] + Math.min(diff, m - diff) + 1);
                }
            }
        }
        int ans = Integer.MAX_VALUE;
        for (int j = 0; j < m; j++) {
            ans = Math.min(ans, dp[n - 1][j]);
        }
        return ans;
        
    }
}
     
    