/**https://leetcode.com/problems/smallest-good-base/ */
//Given an integer n represented as a string, return the smallest good base of n.
//We call k >= 2 a good base of n, if all digits of n base k are 1's.


class SmallestGoodBase {
    public String smallestGoodBase(String n) {
        long num = Long.parseLong(n);
        int mMax = (int) (Math.log(num + 1) / Math.log(2));
        for (int m = mMax; m > 1; m--) {
            int k = (int) Math.pow(num, 1.0 / m);
            long mul = 1, sum = 1;
            for (int i = 0; i < m; i++) {
                mul *= k;
                sum += mul;
            }
            if (sum == num) {
                return Integer.toString(k);
            }
        }
        return Long.toString(num - 1);
        
    }
}
     
    