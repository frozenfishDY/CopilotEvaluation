/**https://leetcode.com/problems/sum-of-floored-pairs/ */
//Given an integer array nums, return the sum of floor(nums[i] / nums[j]) for all pairs of indices 0 <= i, j < nums.length in the array. Since the answer may be too large, return it modulo 109 + 7.
//The floor() function returns the integer part of the division.


class SumOfFlooredPairs {
    public int sumOfFlooredPairs(int[] nums) {
        int n = nums.length;
        int max = 0;
        for(int num : nums){
            max = Math.max(max, num);
        }
        int[] count = new int[max + 1];
        for(int num : nums){
            count[num]++;
        }
        int[] sum = new int[max + 1];
        for(int i = 1; i <= max; i++){
            sum[i] = sum[i - 1] + count[i];
        }
        int res = 0;
        for(int i = 1; i <= max; i++){
            for(int j = i; j <= max; j += i){
                res = (res + (int)((long)count[i] * (sum[Math.min(max, j + i - 1)] - sum[j - 1]) % 1000000007)) % 1000000007;
            }
        }
        return res;
        
    }
}
     
    