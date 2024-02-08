/**https://leetcode.com/problems/smallest-value-after-replacing-with-sum-of-prime-factors/ */
//You are given a positive integer n.
//Continuously replace n with the sum of its prime factors.
//Note that if a prime factor divides n multiple times, it should be included in the sum as many times as it divides n.
//Return the smallest value n will take on.


class SmallestValueAfterReplacingWithSumOfPrimeFactors {
    public int smallestValue(int n) {
        int res = 0;
        for(int i = 2; i * i <= n; i++){
            while(n % i == 0){
                res += i;
                n /= i;
            }
        }
        if(n > 1){
            res += n;
        }
        return res;
        
        
    }
}

    