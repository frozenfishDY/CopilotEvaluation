/**https://leetcode.com/problems/number-of-beautiful-partitions/ */
//You are given a string s that consists of the digits '1' to '9' and two integers k and minLength.
//A partition of s is called beautiful if:
//s is partitioned into k non-intersecting substrings.
//Each substring has a length of at least minLength.
//Each substring starts with a prime digit and ends with a non-prime digit. Prime digits are '2', '3', '5', and '7', and the rest of the digits are non-prime.
//Return the number of beautiful partitions of s. Since the answer may be very large, return it modulo 109 + 7.
//A substring is a contiguous sequence of characters within a string.


class NumberOfBeautifulPartitions {
    public int beautifulPartitions(String s, int k, int minLength) {
        int n = s.length();
        int[] dp = new int[n];
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (isPrime(s.charAt(i)) && i >= minLength - 1 && !isPrime(s.charAt(i - minLength + 1))) {
                dp[i] = 1;
            }
            if (i >= minLength) {
                dp[i] += dp[i - minLength];
            }
            if (i >= k - 1) {
                res += dp[i - k + 1];
            }
        }
        return res;
        
        
    }
}
     
    