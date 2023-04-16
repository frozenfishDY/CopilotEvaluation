/**https://leetcode.com/problems/number-of-ways-to-separate-numbers/ */
//You wrote down many positive integers in a string called num. However, you realized that you forgot to add commas to seperate the different numbers. You remember that the list of integers was non-decreasing and that no integer had leading zeros.
//Return the number of possible lists of integers that you could have written down to get the string num. Since the answer may be large, return it modulo 109 + 7.


class NumberOfWaysToSeparateNumbers {
    public int numberOfCombinations(String num) {
        int mod = 1000000007;
        int n = num.length();
        long[] dp = new long[n + 1];
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
            if(num.charAt(i - 1) != '0'){
                dp[i] = dp[i - 1];
            }
            if(i >= 2 && num.charAt(i - 2) != '0'){
                long val = Long.parseLong(num.substring(i - 2, i));
                if(val <= 26){
                    dp[i] = (dp[i] + dp[i - 2]) % mod;
                }
            }
        }
        return (int)dp[n];
        
    }
}
     
    