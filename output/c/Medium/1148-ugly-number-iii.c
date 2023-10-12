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
long gcd(long a, long b) {
    return b == 0 ? a : gcd(b, a % b);
}
int nthUglyNumber(int n, int a, int b, int c){
long ab = (long)a * b / gcd(a, b);
    long ac = (long)a * c / gcd(a, c);
    long bc = (long)b * c / gcd(b, c);
    long abc = (long)a * bc / gcd(a, bc);
    long low = 1, high = 2000000000;
    while (low < high) {
        long mid = low + (high - low) / 2;
        long cnt = mid / a + mid / b + mid / c - mid / ab - mid / ac - mid / bc + mid / abc;
        if (cnt < n) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}


