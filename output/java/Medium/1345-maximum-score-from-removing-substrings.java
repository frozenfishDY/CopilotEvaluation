/**https://leetcode.com/problems/maximum-score-from-removing-substrings/ */
//You are given a string s and two integers x and y. You can perform two types of operations any number of times.
//Remove substring "ab" and gain x points.
//For example, when removing "ab" from "cabxbae" it becomes "cxbae".
//Remove substring "ba" and gain y points.
//For example, when removing "ba" from "cabxbae" it becomes "cabxe".
//Return the maximum points you can gain after applying the above operations on s.


class MaximumScoreFromRemovingSubstrings {
    public int maximumGain(String s, int x, int y) {
        int res = 0;
        int n = s.length();
        int[] pre = new int[n + 1];
        for(int i = 1; i <= n; i++){
            pre[i] = pre[i - 1] + (s.charAt(i - 1) == 'a' ? x : y);
        }
        int[] dp = new int[n + 1];
        int[] last = new int[2];
        Arrays.fill(last, -1);
        for(int i = 1; i <= n; i++){
            dp[i] = dp[i - 1];
            if(last[s.charAt(i - 1) - 'a'] != -1){
                dp[i] = Math.max(dp[i], dp[last[s.charAt(i - 1) - 'a']] + pre[i] - pre[last[s.charAt(i - 1) - 'a'] + 1]);
            }
            last[s.charAt(i - 1) - 'a'] = i - 1;
            res = Math.max(res, dp[i]);
        }
        return res;
        
    }
}
     
    