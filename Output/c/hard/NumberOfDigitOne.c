/**https://leetcode.com/problems/number-of-digit-one/ */
//Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.


int countDigitOne(int n){
    int count = 0;
    for(long long i = 1; i <= n; i *= 10){
        long long divider = i * 10;
        count += (n / divider) * i + min(max(n % divider - i + 1, 0LL), i);
    }
    return count;

}

    