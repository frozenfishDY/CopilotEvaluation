/**https://leetcode.com/problems/fibonacci-number/ */
//The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,
//F(0) = 0, F(1) = 1
//F(n) = F(n - 1) + F(n - 2), for n > 1.
//Given n, calculate F(n).


/**
 * @param {number} n
 * @return {number}
 */
var fib = function(n) {
    let a = 0;
    let b = 1;
    let c = 0;
    for(let i = 0; i < n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return a;
    
};

    