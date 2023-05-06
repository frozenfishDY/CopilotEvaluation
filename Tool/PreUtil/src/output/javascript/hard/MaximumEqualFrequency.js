/**https://leetcode.com/problems/maximum-equal-frequency/ */
//Given an array nums of positive integers, return the longest possible length of an array prefix of nums, such that it is possible to remove exactly one element from this prefix so that every number that has appeared in it will have the same number of occurrences.
//If after removing one element there are no remaining elements, it's still considered that every appeared number has the same number of ocurrences (0).


/**
 * @param {number[]} nums
 * @return {number}
 */
var maxEqualFreq = function(nums) {
    let freq = new Map();
    let count = new Map();
    let ans = 0;
    for(let i = 0; i < nums.length; i++){
        let num = nums[i];
        let f = freq.get(num) || 0;
        freq.set(num, f + 1);
        let c = count.get(f) || 0;
        count.set(f, c - 1);
        c = count.get(f + 1) || 0;
        count.set(f + 1, c + 1);
        if(count.get(1) == i + 1){
            ans = i + 1;
        }
        else if(count.get(i + 1) == 1){
            ans = i + 1;
        }
        else if(count.get(i) * (i) == i + 1){
            ans = i + 1;
        }
    }
    return ans;
    
};

    