/**https://leetcode.com/problems/3sum-closest/ */
//Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
//Return the sum of the three integers.
//You may assume that each input would have exactly one solution.


/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var threeSumClosest = function(nums, target) {
    let result = 0;
    let min = Number.MAX_SAFE_INTEGER;
    nums.sort((a, b) => a - b);
    for(let i = 0; i < nums.length; i++){
        if(i > 0 && nums[i] == nums[i - 1]){
            continue;
        }
        let left = i + 1;
        let right = nums.length - 1;
        while(left < right){
            let sum = nums[i] + nums[left] + nums[right];
            if(sum == target){
                return sum;
            }else if(sum < target){
                if(target - sum < min){
                    min = target - sum;
                    result = sum;
                }
                left++;
            }else{
                if(sum - target < min){
                    min = sum - target;
                    result = sum;
                }
                right--;
            }
        }
    }
    return result;
    
};

    