/**https://leetcode.com/problems/ugly-number-iii/ */
//An ugly number is a positive integer that is divisible by a, b, or c.
//Given four integers n, a, b, and c, return the nth ugly number.
// 
//Example 1:
//Input: n = 3, a = 2, b = 3, c = 5
//Output: 4
//Explanation: The ugly numbers are 2, 3, 4, 5, 6, 8, 9, 10... The 3rd is 4.
//Example 2:
//Input: n = 4, a = 2, b = 3, c = 4
//Output: 6
//Explanation: The ugly numbers are 2, 3, 4, 6, 8, 9, 10, 12... The 4th is 6.
//Example 3:
//Input: n = 5, a = 2, b = 11, c = 13
//Output: 10
//Explanation: The ugly numbers are 2, 4, 6, 8, 10, 11, 12, 13... The 5th is 10.
// 
//Constraints:
//	1 <= n, a, b, c <= 109
//	1 <= a * b * c <= 1018
//	It is guaranteed that the result will be in range [1, 2 * 109].
class Solution {
    public int nthUglyNumber(int n, int a, int b, int c) {
        long left = 1, right = (long)2e9;
        while(left < right) {
            long mid = (left+right)/2;
            if(count(mid, a, b, c) >= n) {
                right = mid;
            }
            else {
                left = mid+1;
            }
        }
        return (int)left;
    }
    private long count(long n, long a, long b, long c) {
        return n/a+n/b+n/c-n/lcm(a, b)-n/lcm(b, c)-n/lcm(a, c)+n/lcm(a, lcm(b, c));
    }
    private long lcm(long a, long b) {
        return a*b/gcd(a, b);
    }
    private long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a%b);
    }
}