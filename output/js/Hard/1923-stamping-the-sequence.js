/**https://leetcode.com/problems/stamping-the-sequence/ */
//You are given two strings stamp and target. Initially, there is a string s of length target.length with all s[i] == '?'.
//In one turn, you can place stamp over s and replace every letter in the s with the corresponding letter from stamp.
//For example, if stamp = "abc" and target = "abcba", then s is "?????" initially. In one turn you can:
//place stamp at index 0 of s to obtain "abc??",
//place stamp at index 1 of s to obtain "?abc?", or
//place stamp at index 2 of s to obtain "??abc".
//Note that stamp must be fully contained in the boundaries of s in order to stamp (i.e., you cannot place stamp at index 3 of s).
//We want to convert s to target using at most 10 * target.length turns.
//Return an array of the index of the left-most letter being stamped at each turn. If we cannot obtain target from s within 10 * target.length turns, return an empty array.


class Solution {
    public int[] movesToStamp(String stamp, String target) {
        int[] dp = new int[target.length()];
        for(int i = 0; i < target.length(); i++){
            dp[i] = -1;
        }
        int[] ans = new int[target.length()];
        int ansIndex = 0;
        int count = 0;
        while(count < target.length()){
            boolean found = false;
            for(int i = 0; i <= target.length() - stamp.length(); i++){
                if(dp[i] == -1 && canStamp(stamp, target, i, dp)){
                    found = true;
                    for(int j = 0; j < stamp.length(); j++){
                        if(dp[i + j] == -1){
                            dp[i + j] = 1;
                            count++;
                        }
                    }
                    ans[ansIndex++] = i;
                }
            }
            if(!found){
                return new int[0];
            }
        }
        int[] ans2 = new int[ansIndex];
        for(int i = 0; i < ansIndex; i++){
            ans2[i] = ans[ansIndex - i - 1];
        }
        return ans2;
        
    }
}

    