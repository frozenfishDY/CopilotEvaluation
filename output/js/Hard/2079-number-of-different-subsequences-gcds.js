/**https://leetcode.com/problems/number-of-different-subsequences-gcds/ */
//You are given an array nums that consists of positive integers.
//The GCD of a sequence of numbers is defined as the greatest integer that divides all the numbers in the sequence evenly.
//For example, the GCD of the sequence [4,6,16] is 2.
//A subsequence of an array is a sequence that can be formed by removing some elements (possibly none) of the array.
//For example, [2,5,10] is a subsequence of [1,2,1,2,4,1,5,10].
//Return the number of different GCDs among all non-empty subsequences of nums.


/**
 * @param {number[]} nums
 * @return {number}
 */
var countDifferentSubsequenceGCDs = function(nums) {
    let max = Math.max(...nums);
    let gcd = new Array(max + 1).fill(0);
    for(let i = 0; i < nums.length; i++){
        gcd[nums[i]] = nums[i];
    }
    for(let i = 1; i <= max; i++){
        for(let j = 2 * i; j <= max; j += i){
            gcd[i] = gcd2(gcd[i], gcd[j]);
        }
    }
    let ans = 0;
    for(let i = 1; i <= max; i++){
        if(gcd[i] == i){
            ans++;
        }
    }
    return ans;
    
    
};

    