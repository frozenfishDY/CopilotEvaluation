/**https://leetcode.com/problems/restore-the-array/ */
//A program was supposed to print an array of integers. The program forgot to print whitespaces and the array is printed as a string of digits s and all we know is that all integers in the array were in the range [1, k] and there are no leading zeros in the array.
//Given the string s and the integer k, return the number of the possible arrays that can be printed as s using the mentioned program. Since the answer may be very large, return it modulo 10^9 + 7.


class RestoreTheArray {
    public int numberOfArrays(String s, int k) {
        int mod = 1000000007;
        int n = s.length();
        long[] dp = new long[n + 1];
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = i - 1; j >= 0; j--){
                if(s.charAt(j) == '0'){
                    break;
                }
                long num = Long.parseLong(s.substring(j, i));
                if(num > k){
                    break;
                }
                dp[i] = (dp[i] + dp[j]) % mod;
            }
        }
        return (int)dp[n];
        
    }
}
     
    