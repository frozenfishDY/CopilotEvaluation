/**https://leetcode.com/problems/number-of-digit-one/ */
//Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.


class NumberOfDigitOne {
    public int countDigitOne(int n) {
        int ans = 0;
        for (long i = 1; i <= n; i *= 10) {
            long div = i * 10;
            ans += (n / div) * i + Math.min(Math.max(n % div - i + 1, 0), i);
        }
        return ans;
        
    }
}
     
    