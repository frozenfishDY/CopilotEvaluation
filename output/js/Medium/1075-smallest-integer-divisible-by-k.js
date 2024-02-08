/**https://leetcode.com/problems/smallest-integer-divisible-by-k/ */
//Given a positive integer k, you need to find the length of the smallest positive integer n such that n is divisible by k, and n only contains the digit 1.
//Return the length of n. If there is no such n, return -1.
//Note: n may not fit in a 64-bit signed integer.


/**
 * @param {number} k
 * @return {number}
 */
var smallestRepunitDivByK = function(k) {
    let n = 1;
    let count = 1;
    while(n % k != 0){
        n = n % k;
        n = n * 10 + 1;
        count++;
    }
    return count;
    
};

    