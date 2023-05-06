/**https://leetcode.com/problems/smallest-value-after-replacing-with-sum-of-prime-factors/ */
//You are given a positive integer n.
//Continuously replace n with the sum of its prime factors.
//Note that if a prime factor divides n multiple times, it should be included in the sum as many times as it divides n.
//Return the smallest value n will take on.


/**
 * @param {number} n
 * @return {number}
 */
var smallestValue = function(n) {
    let result = 0;
    while(n > 1){
        let min = n;
        for(let i = 2; i * i <= n; i++){
            if(n % i == 0){
                min = Math.min(min, i);
                while(n % i == 0){
                    n /= i;
                }
            }
        }
        if(n > 1){
            min = Math.min(min, n);
        }
        result += min;
        n = min;
    }
    return result;
    
};

    