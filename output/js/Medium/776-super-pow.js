/**https://leetcode.com/problems/super-pow/ */
//Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.


/**
 * @param {number} a
 * @param {number[]} b
 * @return {number}
 */
var superPow = function(a, b) {
    let result = 1;
    for(let i = 0; i < b.length; i++){
        result = pow(result, 10) * pow(a, b[i]) % 1337;
    }
    return result;
    
    
};

    