/**https://leetcode.com/problems/132-pattern/ */
//Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].
//Return true if there is a 132 pattern in nums, otherwise, return false.


/**
 * @param {number[]} nums
 * @return {boolean}
 */
var find132pattern = function(nums) {
    let n = nums.length;
    let min = new Array(n).fill(0);
    min[0] = nums[0];
    for(let i = 1; i < n; i++){
        min[i] = Math.min(min[i - 1], nums[i]);
    }
    let stack = [];
    for(let i = n - 1; i >= 0; i--){
        if(nums[i] > min[i]){
            while(stack.length != 0 && stack[stack.length - 1] <= min[i]){
                stack.pop();
            }
            if(stack.length != 0 && stack[stack.length - 1] < nums[i]){
                return true;
            }
            stack.push(nums[i]);
        }
    }
    return false;
    
};

    