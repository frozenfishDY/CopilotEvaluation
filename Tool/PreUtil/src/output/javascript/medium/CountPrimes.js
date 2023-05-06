/**https://leetcode.com/problems/count-primes/ */
//Given an integer n, return the number of prime numbers that are strictly less than n.


/**
 * @param {number} n
 * @return {number}
 */
var countPrimes = function(n) {
    let count = 0;
    let isPrime = new Array(n).fill(true);
    for(let i = 2; i < n; i++){
        if(isPrime[i]){
            count++;
            for(let j = 2; i * j < n; j++){
                isPrime[i * j] = false;
            }
        }
    }
    return count;
    
};

    