/**https://leetcode.com/problems/convert-to-base-2/ */
//Given an integer n, return a binary string representing its representation in base -2.
//Note that the returned string should not have leading zeros unless the string is "0".


/**
 * @param {number} n
 * @return {string}
 */
var baseNeg2 = function(n) {
    let result = "";
    while(n != 0){
        result = n % 2 + result;
        n = Math.floor(n / 2);
    }
    return result;
    
};

    