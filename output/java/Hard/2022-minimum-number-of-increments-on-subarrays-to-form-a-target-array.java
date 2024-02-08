/**https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/ */
//You are given an integer array target. You have an integer array initial of the same size as target with all elements initially zeros.
//In one operation you can choose any subarray from initial and increment each value by one.
//Return the minimum number of operations to form a target array from initial.
//The test cases are generated so that the answer fits in a 32-bit integer.


class MinimumNumberOfIncrementsOnSubarraysToFormATargetArray {
    public int minNumberOperations(int[] target) {
        int res = target[0];
        for(int i = 1; i < target.length; i++){
            res += Math.max(0, target[i] - target[i - 1]);
        }
        return res;
        
    }
}
     
    