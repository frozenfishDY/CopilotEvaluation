/**https://leetcode.com/problems/maximize-number-of-nice-divisors/ */
//You are given a positive integer primeFactors. You are asked to construct a positive integer n that satisfies the following conditions:
//The number of prime factors of n (not necessarily distinct) is at most primeFactors.
//The number of nice divisors of n is maximized. Note that a divisor of n is nice if it is divisible by every prime factor of n. For example, if n = 12, then its prime factors are [2,2,3], then 6 and 12 are nice divisors, while 3 and 4 are not.
//Return the number of nice divisors of n. Since that number can be too large, return it modulo 109 + 7.
//Note that a prime number is a natural number greater than 1 that is not a product of two smaller natural numbers. The prime factors of a number n is a list of prime numbers such that their product equals n.


int maxNiceDivisors(int primeFactors){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*primeFactors);
    for(i=0;i<primeFactors;i++){
        arr[i] = 0;
    }
    arr[0] = 1;
    for(i=1;i<primeFactors;i++){
        for(j=0;j<i;j++){
            arr[i] = (arr[i] + arr[j]*arr[i-j-1]) % 1000000007;
        }
    }
    return arr[primeFactors-1];

}

    