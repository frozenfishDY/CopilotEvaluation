/**https://leetcode.com/problems/check-if-it-is-a-good-array/ */
//Given an array nums of positive integers. Your task is to select some subset of nums, multiply each element by an integer and add all these numbers. The array is said to be good if you can obtain a sum of 1 from the array by any possible subset and multiplicand.
//Return True if the array is good otherwise return False.


class CheckIfItIsAGoodArray {
    public boolean isGoodArray(int[] nums) {
        int gcd = nums[0];
        for (int i = 1; i < nums.length; i++) {
            gcd = gcd(gcd, nums[i]);
        }
        return gcd == 1;
        
        
    }
}
     
    