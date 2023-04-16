/**https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/ */
//You are given a positive integer array nums.
//The element sum is the sum of all the elements in nums.
//The digit sum is the sum of all the digits (not necessarily distinct) that appear in nums.
//Return the absolute difference between the element sum and digit sum of nums.
//Note that the absolute difference between two integers x and y is defined as |x - y|.


class DifferenceBetweenElementSumAndDigitSumOfAnArray {
    public int differenceOfSum(int[] nums) {
        int sum = 0;
        for(int i = 0; i < nums.length; i++){
            sum += nums[i];
        }
        int digitSum = 0;
        for(int i = 0; i < nums.length; i++){
            while(nums[i] > 0){
                digitSum += nums[i] % 10;
                nums[i] /= 10;
            }
        }
        return Math.abs(sum - digitSum);
        
        
        
    }
}

    