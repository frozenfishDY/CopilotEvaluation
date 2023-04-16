/**https://leetcode.com/problems/minimum-operations-to-halve-array-sum/ */
//You are given an array nums of positive integers. In one operation, you can choose any number from nums and reduce it to exactly half the number. (Note that you may choose this reduced number in future operations.)
//Return the minimum number of operations to reduce the sum of nums by at least half.


class MinimumOperationsToHalveArraySum {
    public int halveArray(int[] nums) {
        int sum = 0;
        for(int i = 0; i < nums.length; i++){
            sum += nums[i];
        }
        int count = 0;
        while(sum > 0){
            sum /= 2;
            count++;
        }
        return count;
        
    }
}
     
    