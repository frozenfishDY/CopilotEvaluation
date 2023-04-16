/**https://leetcode.com/problems/minimum-increment-to-make-array-unique/ */
//You are given an integer array nums. In one move, you can pick an index i where 0 <= i < nums.length and increment nums[i] by 1.
//Return the minimum number of moves to make every value in nums unique.
//The test cases are generated so that the answer fits in a 32-bit integer.


/**
 * @param {number[]} nums
 * @return {number}
 */
var minIncrementForUnique = function(nums) {
    let result = 0;
    let count = new Array(40000).fill(0);
    for(let i = 0; i < nums.length; i++){
        count[nums[i]]++;
    }
    let taken = 0;
    for(let i = 0; i < 40000; i++){
        if(count[i] >= 2){
            taken += count[i] - 1;
            result -= i * (count[i] - 1);
        }else if(taken > 0 && count[i] == 0){
            taken--;
            result += i;
        }
    }
    return result;
    
};

    