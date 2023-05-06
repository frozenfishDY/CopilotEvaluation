/**https://leetcode.com/problems/count-primes/ */
//Given an integer n, return the number of prime numbers that are strictly less than n.


int countPrimes(int n){
    int* result = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        result[i] = 1;
    }
    for(int i = 2; i * i < n; i++){
        if(result[i] == 1){
            for(int j = i * i; j < n; j += i){
                result[j] = 0;
            }
        }
    }
    int count = 0;
    for(int i = 2; i < n; i++){
        if(result[i] == 1){
            count++;
        }
    }
    return count;

}

    