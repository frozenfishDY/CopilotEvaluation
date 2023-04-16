/**https://leetcode.com/problems/prime-palindrome/ */
//Given an integer n, return the smallest prime palindrome greater than or equal to n.
//An integer is prime if it has exactly two divisors: 1 and itself. Note that 1 is not a prime number.
//For example, 2, 3, 5, 7, 11, and 13 are all primes.
//An integer is a palindrome if it reads the same from left to right as it does from right to left.
//For example, 101 and 12321 are palindromes.
//The test cases are generated so that the answer always exists and is in the range [2, 2 * 108].


int primePalindrome(int n){
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int flag = 0;
    int* prime = (int*)malloc(sizeof(int) * 10000000);
    for(i = 0; i < 10000000; i++){
        prime[i] = 1;
    }
    for(i = 2; i < 10000000; i++){
        if(prime[i] == 1){
            for(j = i * 2; j < 10000000; j += i){
                prime[j] = 0;
            }
        }
    }
    for(i = n; i < 10000000; i++){
        if(prime[i] == 1){
            flag = 1;
            k = i;
            l = 0;
            while(k > 0){
                l = l * 10 + k % 10;
                k = k / 10;
            }
            if(l == i){
                return i;
            }
        }
    }
    return 0;

}

    