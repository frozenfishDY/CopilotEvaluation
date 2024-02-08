/**https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/ */
//Given an integer k, return the minimum number of Fibonacci numbers whose sum is equal to k. The same Fibonacci number can be used multiple times.
//The Fibonacci numbers are defined as:
//F1 = 1
//F2 = 1
//Fn = Fn-1 + Fn-2 for n > 2.
//It is guaranteed that for the given constraints we can always find such Fibonacci numbers that sum up to k.


/**
 * @param {number} k
 * @return {number}
 */
var findMinFibonacciNumbers = function(k) {
    let fib = [1, 1];
    let i = 2;
    while (fib[i - 1] + fib[i - 2] <= k) {
        fib.push(fib[i - 1] + fib[i - 2]);
        i++;
    }
    let count = 0;
    while (k > 0) {
        let j = fib.length - 1;
        while (j >= 0 && fib[j] > k) {
            j--;
        }
        k -= fib[j];
        count++;
    }
    return count;
    
};

    