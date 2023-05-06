/**https://leetcode.com/problems/steps-to-make-array-non-decreasing/ */
//You are given a 0-indexed integer array nums. In one step, remove all elements nums[i] where nums[i - 1] > nums[i] for all 0 < i < nums.length.
//Return the number of steps performed until nums becomes a non-decreasing array.


class StepsToMakeArrayNonDecreasing {
    public int totalSteps(int[] nums) {
        int[] count = new int[100000];
        for (int num : nums) {
            count[num]++;
        }
        int result = 0;
        int prev = 0;
        for (int i = 0; i < count.length; i++) {
            if (count[i] > 0) {
                result += Math.max(0, prev - i);
                prev = i + count[i];
            }
        }
        return result;
        
    }
}
     
    