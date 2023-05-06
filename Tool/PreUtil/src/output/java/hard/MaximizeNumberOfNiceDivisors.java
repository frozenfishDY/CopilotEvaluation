/**https://leetcode.com/problems/maximize-number-of-nice-divisors/ */
//You are given a positive integer primeFactors. You are asked to construct a positive integer n that satisfies the following conditions:
//The number of prime factors of n (not necessarily distinct) is at most primeFactors.
//The number of nice divisors of n is maximized. Note that a divisor of n is nice if it is divisible by every prime factor of n. For example, if n = 12, then its prime factors are [2,2,3], then 6 and 12 are nice divisors, while 3 and 4 are not.
//Return the number of nice divisors of n. Since that number can be too large, return it modulo 109 + 7.
//Note that a prime number is a natural number greater than 1 that is not a product of two smaller natural numbers. The prime factors of a number n is a list of prime numbers such that their product equals n.


class MaximizeNumberOfNiceDivisors {
    public int maxNiceDivisors(int primeFactors) {
        if(primeFactors == 1){
            return 1;
        }
        if(primeFactors == 2){
            return 2;
        }
        if(primeFactors == 3){
            return 3;
        }
        int mod = 1000000007;
        int a = primeFactors / 3;
        int b = primeFactors % 3;
        if(b == 0){
            return (int)(pow(3, a, mod) % mod);
        }
        if(b == 1){
            return (int)(pow(3, a - 1, mod) * 4 % mod);
        }
        return (int)(pow(3, a, mod) * 2 % mod);
        
        
    }
}
     
    