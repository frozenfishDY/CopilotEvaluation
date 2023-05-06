/**https://leetcode.com/problems/smallest-integer-divisible-by-k/ */
//Given a positive integer k, you need to find the length of the smallest positive integer n such that n is divisible by k, and n only contains the digit 1.
//Return the length of n. If there is no such n, return -1.
//Note: n may not fit in a 64-bit signed integer.


int smallestRepunitDivByK(int k){
    if(k % 2 == 0 || k % 5 == 0){
        return -1;
    }
    int n = 1;
    int count = 1;
    while(n % k != 0){
        n = (n * 10 + 1) % k;
        count++;
    }
    return count;

}

    