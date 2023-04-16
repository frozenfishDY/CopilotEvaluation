/**https://leetcode.com/problems/split-message-based-on-limit/ */
//You are given a string, message, and a positive integer, limit.
//You must split message into one or more parts based on limit. Each resulting part should have the suffix "<a/b>", where "b" is to be replaced with the total number of parts and "a" is to be replaced with the index of the part, starting from 1 and going up to b. Additionally, the length of each resulting part (including its suffix) should be equal to limit, except for the last part whose length can be at most limit.
//The resulting parts should be formed such that when their suffixes are removed and they are all concatenated in order, they should be equal to message. Also, the result should contain as few parts as possible.
//Return the parts message would be split into as an array of strings. If it is impossible to split message as required, return an empty array.


class SplitMessageBasedOnLimit {
    public String[] splitMessage(String message, int limit) {
        int n = message.length();
        int[] dp = new int[n];
        int[] prev = new int[n];
        Arrays.fill(dp, Integer.MAX_VALUE);
        for (int i = 0; i < n; i++) {
            if (i < limit) {
                dp[i] = 1;
                prev[i] = -1;
            }
            for (int j = i - limit; j >= 0; j--) {
                if (dp[j] == Integer.MAX_VALUE) {
                    continue;
                }
                if (isPalindrome(message, j + 1, i)) {
                    if (dp[i] > dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
        }
        if (dp[n - 1] == Integer.MAX_VALUE) {
            return new String[0];
        }
        String[] res = new String[dp[n - 1]];
        int idx = n - 1;
        for (int i = dp[n - 1] - 1; i >= 0; i--) {
            res[i] = message.substring(prev[idx] + 1, idx + 1) + "<" + (i + 1) + "/" + dp[n - 1] + ">";
            idx = prev[idx];
        }
        return res;
        
    }
}
     
    