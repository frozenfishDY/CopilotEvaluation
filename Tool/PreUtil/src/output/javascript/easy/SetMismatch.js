/**https://leetcode.com/problems/set-mismatch/ */
//You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.
//You are given an integer array nums representing the data status of this set after the error.
//Find the number that occurs twice and the number that is missing and return them in the form of an array.


/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findErrorNums = function(nums) {
    let set = new Set();
    let sum = 0;
    let duplicate = 0;
    for(let i = 0; i < nums.length; i++){
        let num = nums[i];
        if(set.has(num)){
            duplicate = num;
        }
        set.add(num);
        sum += num;
    }
    let n = nums.length;
    let missing = (n * (n + 1) / 2) - (sum - duplicate);
    return [duplicate, missing];
    
};

    