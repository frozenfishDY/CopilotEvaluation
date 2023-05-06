/**https://leetcode.com/problems/simplified-fractions/ */
//Given an integer n, return a list of all simplified fractions between 0 and 1 (exclusive) such that the denominator is less-than-or-equal-to n. You can return the answer in any order.


/**
 * @param {number} n
 * @return {string[]}
 */
var simplifiedFractions = function(n) {
    let res = [];
    for (let i = 1; i <= n; i++) {
        for (let j = 1; j < i; j++) {
            if (gcd(i, j) === 1) {
                res.push(j + '/' + i);
            }
        }
    }
    return res;
    
    
};

    