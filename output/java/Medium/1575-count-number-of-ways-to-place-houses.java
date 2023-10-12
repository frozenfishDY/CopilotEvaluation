/**https://leetcode.com/problems/count-number-of-ways-to-place-houses/ */
//There is a street with n * 2 plots, where there are n plots on each side of the street. The plots on each side are numbered from 1 to n. On each plot, a house can be placed.
//Return the number of ways houses can be placed such that no two houses are adjacent to each other on the same side of the street. Since the answer may be very large, return it modulo 109 + 7.
//Note that if a house is placed on the ith plot on one side of the street, a house can also be placed on the ith plot on the other side of the street.
// 
//Example 1:
//Input: n = 1
//Output: 4
//Explanation: 
//Possible arrangements:
//1. All plots are empty.
//2. A house is placed on one side of the street.
//3. A house is placed on the other side of the street.
//4. Two houses are placed, one on each side of the street.
//Example 2:
//Input: n = 2
//Output: 9
//Explanation: The 9 possible arrangements are shown in the diagram above.
// 
//Constraints:
//	1 <= n <= 104
class Solution {
    public int countHousePlacements(int n) {
        long[] dp = new long[2];
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            long[] temp = new long[2];
            temp[0] = (dp[0] * 2 + dp[1]) % 1000000007;
            temp[1] = (dp[0] + dp[1] * 2) % 1000000007;
            dp = temp;
        }
        return (int) ((dp[0] + dp[1]) % 1000000007);
    }
}