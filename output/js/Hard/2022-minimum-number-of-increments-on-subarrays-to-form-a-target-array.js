/**https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/ */
//You are given an integer array target. You have an integer array initial of the same size as target with all elements initially zeros.
//In one operation you can choose any subarray from initial and increment each value by one.
//Return the minimum number of operations to form a target array from initial.
//The test cases are generated so that the answer fits in a 32-bit integer.


/**
 * @param {number[]} target
 * @return {number}
 */
var minNumberOperations = function(target) {
    let res = 0;
    let prev = 0;
    for(let i = 0; i < target.length; i++){
        if(target[i] > prev){
            res += target[i] - prev;
        }
        prev = target[i];
    }
    return res;
    
};

    