/**https://leetcode.com/problems/number-of-common-factors/ */
//Given two positive integers a and b, return the number of common factors of a and b.
//An integer x is a common factor of a and b if x divides both a and b.
// 
//Example 1:
//Input: a = 12, b = 6
//Output: 4
//Explanation: The common factors of 12 and 6 are 1, 2, 3, 6.
//Example 2:
//Input: a = 25, b = 30
//Output: 2
//Explanation: The common factors of 25 and 30 are 1, 5.
// 
//Constraints:
//	1 <= a, b <= 1000
class Solution {
    public int commonFactors(int a, int b) {
        int res = 0;
        int n = gcd(a, b);
        for (int i = 1; i <= Math.sqrt(n); i++) {
            if (n % i == 0) {
                res += 2;
                if (i == n / i) {
                    res--;
                }
            }
        }
        return res;
    }
    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}