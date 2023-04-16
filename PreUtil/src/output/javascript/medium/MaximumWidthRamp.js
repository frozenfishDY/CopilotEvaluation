/**https://leetcode.com/problems/maximum-width-ramp/ */
//A ramp in an integer array nums is a pair (i, j) for which i < j and nums[i] <= nums[j]. The width of such a ramp is j - i.
//Given an integer array nums, return the maximum width of a ramp in nums. If there is no ramp in nums, return 0.


/**
 * @param {number[]} nums
 * @return {number}
 */
var maxWidthRamp = function(nums) {
    let n = nums.length;
    let stack = [];
    for(let i = 0; i < n; i++){
        if(stack.length == 0 || nums[stack[stack.length - 1]] > nums[i]){
            stack.push(i);
        }
    }
    let ans = 0;
    for(let i = n - 1; i >= 0; i--){
        while(stack.length > 0 && nums[stack[stack.length - 1]] <= nums[i]){
            ans = Math.max(ans, i - stack.pop());
        }
    }
    return ans;
    
};

    