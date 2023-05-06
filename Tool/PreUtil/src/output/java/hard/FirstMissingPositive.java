/**https://leetcode.com/problems/first-missing-positive/ */
//Given an unsorted integer array nums, return the smallest missing positive integer.
//You must implement an algorithm that runs in O(n) time and uses constant extra space.


class FirstMissingPositive {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
        for(int i = 0; i < n; i++){
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]){
                int temp = nums[nums[i] - 1];
                nums[nums[i] - 1] = nums[i];
                nums[i] = temp;
            }
        }
        for(int i = 0; i < n; i++){
            if(nums[i] != i + 1) return i + 1;
        }
        return n + 1;
        
    }
}
     
    