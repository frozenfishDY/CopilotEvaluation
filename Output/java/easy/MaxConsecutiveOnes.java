/**https://leetcode.com/problems/max-consecutive-ones/ */
//Given a binary array nums, return the maximum number of consecutive 1's in the array.


class MaxConsecutiveOnes {
    public int findMaxConsecutiveOnes(int[] nums) {
        int max = 0;
        int count = 0;
        for(int i = 0; i < nums.length; i++){
            if(nums[i] == 1){
                count++;
            }else{
                max = Math.max(max, count);
                count = 0;
            }
        }
        return Math.max(max, count);
        
    }
}

    