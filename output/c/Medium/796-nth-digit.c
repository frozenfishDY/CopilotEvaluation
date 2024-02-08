/**https://leetcode.com/problems/nth-digit/ */
//Given an integer n, return the nth digit of the infinite integer sequence [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...].


int findNthDigit(int n){
    int digit = 1;
    long long count = 9;
    int start = 1;
    while(n > count){
        n -= count;
        digit++;
        count = 9 * start * digit;
        start *= 10;
    }
    int num = start + (n - 1) / digit;
    int index = (n - 1) % digit;
    return to_string(num)[index] - '0';

}

    