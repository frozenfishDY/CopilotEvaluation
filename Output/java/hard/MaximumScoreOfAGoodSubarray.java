/**https://leetcode.com/problems/maximum-score-of-a-good-subarray/ */
//You are given an array of integers nums (0-indexed) and an integer k.
//The score of a subarray (i, j) is defined as min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1). A good subarray is a subarray where i <= k <= j.
//Return the maximum possible score of a good subarray.


class MaximumScoreOfAGoodSubarray {
    public int maximumScore(int[] nums, int k) {
        int n = nums.length;
        int res = nums[k];
        int left = k;
        int right = k;
        int min = nums[k];
        while(left > 0 || right < n - 1){
            if(left == 0){
                right++;
            }else if(right == n - 1){
                left--;
            }else if(nums[left - 1] > nums[right + 1]){
                left--;
            }else{
                right++;
            }
            min = Math.min(min, Math.min(nums[left], nums[right]));
            res = Math.max(res, min * (right - left + 1));
        }
        return res;
        
    }
}
     
    