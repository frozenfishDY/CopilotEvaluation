/**https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/ */
//Given an integer k, return the minimum number of Fibonacci numbers whose sum is equal to k. The same Fibonacci number can be used multiple times.
//The Fibonacci numbers are defined as:
//F1 = 1
//F2 = 1
//Fn = Fn-1 + Fn-2 for n > 2.
//It is guaranteed that for the given constraints we can always find such Fibonacci numbers that sum up to k.


int findMinFibonacciNumbers(int k){
    int i, j, count = 0, *arr;
    arr = (int*)malloc(100 * sizeof(int));
    arr[0] = 1;
    arr[1] = 1;
    for(i = 2; i < 100; i++){
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    for(i = 99; i >= 0; i--){
        if(k >= arr[i]){
            k -= arr[i];
            count++;
        }
    }
    return count;

}

    