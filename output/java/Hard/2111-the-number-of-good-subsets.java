/**https://leetcode.com/problems/the-number-of-good-subsets/ */
//You are given an integer array nums. We call a subset of nums good if its product can be represented as a product of one or more distinct prime numbers.
//For example, if nums = [1, 2, 3, 4]:
//[2, 3], [1, 2, 3], and [1, 3] are good subsets with products 6 = 2*3, 6 = 2*3, and 3 = 3 respectively.
//[1, 4] and [4] are not good subsets with products 4 = 2*2 and 4 = 2*2 respectively.
//Return the number of different good subsets in nums modulo 109 + 7.
//A subset of nums is any array that can be obtained by deleting some (possibly none or all) elements from nums. Two subsets are different if and only if the chosen indices to delete are different.


class TheNumberOfGoodSubsets {
    public int numberOfGoodSubsets(int[] nums) {
        int mod = 1000000007;
        int n = nums.length;
        int[] primes = new int[]{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
        int[] dp = new int[1 << primes.length];
        dp[0] = 1;
        int[] count = new int[primes.length];
        for(int i = 0; i < n; i++){
            int num = nums[i];
            for(int j = 0; j < primes.length; j++){
                if(num % primes[j] == 0){
                    count[j]++;
                }
            }
        }
        for(int i = 0; i < primes.length; i++){
            if(count[i] == 0){
                continue;
            }
            int mask = 1 << i;
            for(int j = 0; j < (1 << primes.length); j++){
                if((j & mask) == 0){
                    dp[j | mask] = (dp[j | mask] + dp[j]) % mod;
                }
            }
        }
        int res = 0;
        for(int i = 0; i < (1 << primes.length); i++){
            int countOnes = 0;
            for(int j = 0; j < primes.length; j++){
                if((i & (1 << j)) != 0){
                    countOnes++;
                }
            }
            int sign = countOnes % 2 == 0 ? 1 : -1;
            res = (res + sign * dp[i]) % mod;
        }
        return (res + mod) % mod;


        
    }
}
     
    