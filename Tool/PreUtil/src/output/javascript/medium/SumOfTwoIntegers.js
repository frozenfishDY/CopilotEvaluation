/**https://leetcode.com/problems/sum-of-two-integers/ */
//Given two integers a and b, return the sum of the two integers without using the operators + and -.


/**
 * @param {number} a
 * @param {number} b
 * @return {number}
 */
var getSum = function(a, b) {
    let carry = 0;
    while(b != 0){
        carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
    
};

    