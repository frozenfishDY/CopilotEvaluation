/**https://leetcode.com/problems/sum-of-beauty-in-the-array/ */
//You are given a 0-indexed integer array nums. For each index i (1 <= i <= nums.length - 2) the beauty of nums[i] equals:
//2, if nums[j] < nums[i] < nums[k], for all 0 <= j < i and for all i < k <= nums.length - 1.
//1, if nums[i - 1] < nums[i] < nums[i + 1], and the previous condition is not satisfied.
//0, if none of the previous conditions holds.
//Return the sum of beauty of all nums[i] where 1 <= i <= nums.length - 2.


class SumOfBeautyInTheArray {
    public int sumOfBeauties(int[] nums) {
        int[] left = new int[nums.length];
        int[] right = new int[nums.length];
        int max = nums[0];
        for(int i = 1; i < nums.length - 1; i++){
            left[i] = max;
            max = Math.max(max, nums[i]);
        }
        int min = nums[nums.length - 1];
        for(int i = nums.length - 2; i > 0; i--){
            right[i] = min;
            min = Math.min(min, nums[i]);
        }
        int sum = 0;
        for(int i = 1; i < nums.length - 1; i++){
            if(nums[i] > left[i] && nums[i] < right[i]){
                sum += 2;
            }else if(nums[i] > nums[i - 1] && nums[i] < nums[i + 1]){
                sum += 1;
            }
        }
        return sum;
        
    }
}
     
    