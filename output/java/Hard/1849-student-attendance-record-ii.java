/**https://leetcode.com/problems/student-attendance-record-ii/ */
//An attendance record for a student can be represented as a string where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:
//'A': Absent.
//'L': Late.
//'P': Present.
//Any student is eligible for an attendance award if they meet both of the following criteria:
//The student was absent ('A') for strictly fewer than 2 days total.
//The student was never late ('L') for 3 or more consecutive days.
//Given an integer n, return the number of possible attendance records of length n that make a student eligible for an attendance award. The answer may be very large, so return it modulo 109 + 7.


class StudentAttendanceRecordIi {
    public int checkRecord(int n) {
        int mod = 1000000007;
        long[] dp = new long[n + 1];
        dp[0] = 1;
        dp[1] = 2;
        dp[2] = 4;
        for (int i = 3; i <= n; i++) {
            dp[i] = ((dp[i - 1] + dp[i - 2]) % mod + dp[i - 3]) % mod;
        }
        long ans = dp[n];
        for (int i = 0; i < n; i++) {
            ans = (ans + dp[i] * dp[n - i - 1]) % mod;
        }
        return (int) ans;
        


    }
}
     
    