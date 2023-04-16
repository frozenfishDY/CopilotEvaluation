/**https://leetcode.com/problems/flip-string-to-monotone-increasing/ */
//A binary string is monotone increasing if it consists of some number of 0's (possibly none), followed by some number of 1's (also possibly none).
//You are given a binary string s. You can flip s[i] changing it from 0 to 1 or from 1 to 0.
//Return the minimum number of flips to make s monotone increasing.


class FlipStringToMonotoneIncreasing {
    public int minFlipsMonoIncr(String s) {
        int n = s.length();
        int[] dp = new int[n];
        dp[0] = s.charAt(0) == '0' ? 0 : 1;
        for(int i = 1; i < n; i++){
            if(s.charAt(i) == '0'){
                dp[i] = dp[i - 1];
            }else{
                dp[i] = dp[i - 1] + 1;
            }
        }
        int res = dp[n - 1];
        for(int i = 0; i < n; i++){
            int cnt = 0;
            if(i > 0){
                cnt += dp[i - 1];
            }
            if(i < n - 1){
                cnt += (n - 1 - i) - (dp[n - 1] - dp[i]);
            }
            res = Math.min(res, cnt);
        }
        return res;
        
        
    }
}

    