/**https://leetcode.com/problems/max-consecutive-ones-iii/ */
//Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var longestOnes = function(nums, k) {
    let ans = 0;
    let count = 0;
    let left = 0;
    for(let i = 0; i < nums.length; i++){
        if(nums[i] == 1){
            count++;
        }
        while(i - left + 1 - count > k){
            if(nums[left] == 1){
                count--;
            }
            left++;
        }
        ans = Math.max(ans, i - left + 1);
    }
    return ans;
    

};

    