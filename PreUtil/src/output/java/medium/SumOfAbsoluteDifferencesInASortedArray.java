/**https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/ */
//You are given an integer array nums sorted in non-decreasing order.
//Build and return an integer array result with the same length as nums such that result[i] is equal to the summation of absolute differences between nums[i] and all the other elements in the array.
//In other words, result[i] is equal to sum(|nums[i]-nums[j]|) where 0 <= j < nums.length and j != i (0-indexed).


class SumOfAbsoluteDifferencesInASortedArray {
    public int[] getSumAbsoluteDifferences(int[] nums) {
        int n = nums.length;
        int[] left = new int[n];
        int[] right = new int[n];
        int count = 0;
        for(int i = 0; i < n; i++){
            if(i == 0 || nums[i] != nums[i - 1]){
                count++;
            }else{
                count = 1;
            }
            left[i] = count;
        }
        count = 0;
        for(int i = n - 1; i >= 0; i--){
            if(i == n - 1 || nums[i] != nums[i + 1]){
                count++;
            }else{
                count = 1;
            }
            right[i] = count;
        }
        int[] res = new int[n];
        for(int i = 0; i < n; i++){
            res[i] = nums[i] * (i + 1 - left[i]) + (nums[i] * right[i] - nums[i] * (i + 1));
        }
        return res;
        
    }
}
     
    