/**https://leetcode.com/problems/consecutive-numbers-sum/ */
//Given an integer n, return the number of ways you can write n as the sum of consecutive positive integers.


class ConsecutiveNumbersSum {
    public int consecutiveNumbersSum(int n) {
        int res = 0;
        for (int i = 1; i * (i + 1) / 2 <= n; i++) {
            if ((n - i * (i + 1) / 2) % i == 0) {
                res++;
            }
        }
        return res;
        
    }
}
     
    