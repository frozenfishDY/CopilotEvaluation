/**https://leetcode.com/problems/max-consecutive-ones/ */
//Given a binary array nums, return the maximum number of consecutive 1's in the array.


/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxConsecutiveOnes = function(nums) {
    let max = 0;
    let count = 0;
    for(let i = 0; i < nums.length; i++){
        if(nums[i] == 1){
            count++;
        }else{
            if(count > max){
                max = count;
            }
            count = 0;
        }
    }
    if(count > max){
        max = count;
    }
    return max;
    
};

    