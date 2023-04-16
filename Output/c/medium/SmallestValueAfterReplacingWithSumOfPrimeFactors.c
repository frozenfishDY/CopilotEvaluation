/**https://leetcode.com/problems/smallest-value-after-replacing-with-sum-of-prime-factors/ */
//You are given a positive integer n.
//Continuously replace n with the sum of its prime factors.
//Note that if a prime factor divides n multiple times, it should be included in the sum as many times as it divides n.
//Return the smallest value n will take on.


int smallestValue(int n){
    int* prime = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        prime[i] = 1;
    }
    for(int i = 2; i < n; i++){
        if(prime[i] == 1){
            for(int j = i * 2; j < n; j += i){
                prime[j] = 0;
            }
        }
    }
    int* sum = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        sum[i] = 0;
    }
    for(int i = 2; i < n; i++){
        if(prime[i] == 1){
            for(int j = i; j < n; j += i){
                sum[j] += i;
            }
        }
    }
    return sum[n - 1];

}

    