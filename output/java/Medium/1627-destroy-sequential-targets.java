/**https://leetcode.com/problems/destroy-sequential-targets/ */
//You are given a 0-indexed array nums consisting of positive integers, representing targets on a number line. You are also given an integer space.
//You have a machine which can destroy targets. Seeding the machine with some nums[i] allows it to destroy all targets with values that can be represented as nums[i] + c * space, where c is any non-negative integer. You want to destroy the maximum number of targets in nums.
//Return the minimum value of nums[i] you can seed the machine with to destroy the maximum number of targets.


class DestroySequentialTargets {
    public int destroyTargets(int[] nums, int space) {
        int max = 0;
        for(int i = 0; i < nums.length; i++){
            int count = 0;
            for(int j = 0; j < nums.length; j++){
                if(nums[j] % space == nums[i] % space){
                    count++;
                }
            }
            max = Math.max(max, count);
        }
        return max;
        
    }
}
     
    