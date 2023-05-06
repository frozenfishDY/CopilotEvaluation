/**https://leetcode.com/problems/stickers-to-spell-word/ */
//We are given n different types of stickers. Each sticker has a lowercase English word on it.
//You would like to spell out the given string target by cutting individual letters from your collection of stickers and rearranging them. You can use each sticker more than once if you want, and you have infinite quantities of each sticker.
//Return the minimum number of stickers that you need to spell out target. If the task is impossible, return -1.
//Note: In all test cases, all words were chosen randomly from the 1000 most common US English words, and target was chosen as a concatenation of two random words.


class StickersToSpellWord {
    public int minStickers(String[] stickers, String target) {
        int n = stickers.length;
        int[][] map = new int[n][26];
        for (int i = 0; i < n; i++) {
            for (char c : stickers[i].toCharArray()) {
                map[i][c - 'a']++;
            }
        }
        int[] dp = new int[1 << target.length()];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;
        for (int state = 0; state < (1 << target.length()); state++) {
            if (dp[state] == Integer.MAX_VALUE) {
                continue;
            }
            for (int i = 0; i < n; i++) {
                int[] temp = Arrays.copyOf(map[i], 26);
                int now = state;
                for (int j = 0; j < target.length(); j++) {
                    if (((now >> j) & 1) == 1) {
                        continue;
                    }
                    if (temp[target.charAt(j) - 'a'] > 0) {
                        temp[target.charAt(j) - 'a']--;
                        now |= 1 << j;
                    }
                }
                dp[now] = Math.min(dp[now], dp[state] + 1);
            }
        }
        return dp[(1 << target.length()) - 1] == Integer.MAX_VALUE ? -1 : dp[(1 << target.length()) - 1];
        
    }
}
     
    