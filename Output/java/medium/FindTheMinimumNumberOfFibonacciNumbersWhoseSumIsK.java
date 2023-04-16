/**https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/ */
//Given an integer k, return the minimum number of Fibonacci numbers whose sum is equal to k. The same Fibonacci number can be used multiple times.
//The Fibonacci numbers are defined as:
//F1 = 1
//F2 = 1
//Fn = Fn-1 + Fn-2 for n > 2.
//It is guaranteed that for the given constraints we can always find such Fibonacci numbers that sum up to k.


class FindTheMinimumNumberOfFibonacciNumbersWhoseSumIsK {
    public int findMinFibonacciNumbers(int k) {
        int count = 0;
        int[] fib = new int[50];
        fib[0] = 1;
        fib[1] = 1;
        for(int i = 2; i < 50; i++){
            fib[i] = fib[i - 1] + fib[i - 2];
        }
        for(int i = 49; i >= 0; i--){
            if(k >= fib[i]){
                k -= fib[i];
                count++;
            }
        }
        return count;
        
        
    }
}

    