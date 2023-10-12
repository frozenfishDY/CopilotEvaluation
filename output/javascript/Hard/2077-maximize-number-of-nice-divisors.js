/**https://leetcode.com/problems/maximize-number-of-nice-divisors/ */
//You are given a positive integer primeFactors. You are asked to construct a positive integer n that satisfies the following conditions:_x000D_
//_x000D_
//_x000D_
//  The number of prime factors of n (not necessarily distinct) is at most primeFactors._x000D_
//  The number of nice divisors of n is maximized. Note that a divisor of n is nice if it is divisible by every prime factor of n. For example, if n = 12, then its prime factors are [2,2,3], then 6 and 12 are nice divisors, while 3 and 4 are not._x000D_
//_x000D_
//_x000D_
//Return the number of nice divisors of n. Since that number can be too large, return it modulo 109 + 7._x000D_
//_x000D_
//Note that a prime number is a natural number greater than 1 that is not a product of two smaller natural numbers. The prime factors of a number n is a list of prime numbers such that their product equals n._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//Input: primeFactors = 5_x000D_
//Output: 6_x000D_
//Explanation: 200 is a valid value of n._x000D_
//It has 5 prime factors: [2,2,2,5,5], and it has 6 nice divisors: [10,20,40,50,100,200]._x000D_
//There is not other value of n that has at most 5 prime factors and more nice divisors._x000D_
//_x000D_
//_x000D_
//Example 2:_x000D_
//_x000D_
//_x000D_
//Input: primeFactors = 8_x000D_
//Output: 18_x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	1 <= primeFactors <= 109_x000D_
/**
 * @param {number} primeFactors
 * @return {number}
 */
var maxNiceDivisors = function(primeFactors) {
    
};