#https://leetcode.com/problems/student-attendance-record-ii/
#An attendance record for a student can be represented as a string where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:
#'A': Absent.
#'L': Late.
#'P': Present.
#Any student is eligible for an attendance award if they meet both of the following criteria:
#The student was absent ('A') for strictly fewer than 2 days total.
#The student was never late ('L') for 3 or more consecutive days.
#Given an integer n, return the number of possible attendance records of length n that make a student eligible for an attendance award. The answer may be very large, so return it modulo 109 + 7.


class Solution(object):
    def checkRecord(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n==1:
            return 3
        if n==2:
            return 8
        dp=[0 for i in range(n+1)]
        dp[0]=1
        dp[1]=3
        dp[2]=8
        dp[3]=19
        for i in range(4,n+1):
            dp[i]=(2*dp[i-1]+dp[i-2]+dp[i-3])%1000000007
        return dp[n]
        
        
    