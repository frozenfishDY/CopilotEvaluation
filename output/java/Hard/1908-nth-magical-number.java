/**https://leetcode.com/problems/nth-magical-number/ */
//A positive integer is magical if it is divisible by either a or b.
//Given the three integers n, a, and b, return the nth magical number. Since the answer may be very large, return it modulo 10^9 + 7.


class NthMagicalNumber {
    public int nthMagicalNumber(int n, int a, int b) {
        int mod = 1000000007;
        long lcm = (long) a * b / gcd(a, b);
        long lo = 0, hi = (long) 1e15;
        while (lo < hi) {
            long mid = lo + hi >> 1;
            if (mid / a + mid / b - mid / lcm < n) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return (int) (lo % mod);
        
        
    }
}
     
    