/**https://leetcode.com/problems/gray-code/ */
//An n-bit gray code sequence is a sequence of 2n integers where:
//Every integer is in the inclusive range [0, 2n - 1],
//The first integer is 0,
//An integer appears no more than once in the sequence,
//The binary representation of every pair of adjacent integers differs by exactly one bit, and
//The binary representation of the first and last integers differs by exactly one bit.
//Given an integer n, return any valid n-bit gray code sequence.


/**
 * @param {number} n
 * @return {number[]}
 */
var grayCode = function(n) {
    let result = [0];
    for(let i = 0; i < n; i++){
        let size = result.length;
        for(let j = size - 1; j >= 0; j--){
            result.push(result[j] + Math.pow(2, i));
        }
    }
    return result;
    
};

    