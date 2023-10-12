/**https://leetcode.com/problems/count-ways-to-group-overlapping-ranges/ */
//You are given a 2D integer array ranges where ranges[i] = [starti, endi] denotes that all integers between starti and endi (both inclusive) are contained in the ith range.
//You are to split ranges into two (possibly empty) groups such that:
//	Each range belongs to exactly one group.
//	Any two overlapping ranges must belong to the same group.
//Two ranges are said to be overlapping if there exists at least one integer that is present in both ranges.
//	For example, [1, 3] and [2, 5] are overlapping because 2 and 3 occur in both ranges.
//Return the total number of ways to split ranges into two groups. Since the answer may be very large, return it modulo 109 + 7.
// 
//Example 1:
//Input: ranges = [[6,10],[5,15]]
//Output: 2
//Explanation: 
//The two ranges are overlapping, so they must be in the same group.
//Thus, there are two possible ways:
//- Put both the ranges together in group 1.
//- Put both the ranges together in group 2.
//Example 2:
//Input: ranges = [[1,3],[10,20],[2,5],[4,8]]
//Output: 4
//Explanation: 
//Ranges [1,3], and [2,5] are overlapping. So, they must be in the same group.
//Again, ranges [2,5] and [4,8] are also overlapping. So, they must also be in the same group. 
//Thus, there are four possible ways to group them:
//- All the ranges in group 1.
//- All the ranges in group 2.
//- Ranges [1,3], [2,5], and [4,8] in group 1 and [10,20] in group 2.
//- Ranges [1,3], [2,5], and [4,8] in group 2 and [10,20] in group 1.
// 
//Constraints:
//	1 <= ranges.length <= 105
//	ranges[i].length == 2
//	0 <= starti <= endi <= 109
class Solution {
    public int countWays(int[][] ranges) {
        int n = ranges.length;
        int[][] sortedRanges = new int[n][2];
        for (int i = 0; i < n; i++) {
            sortedRanges[i][0] = ranges[i][0];
            sortedRanges[i][1] = ranges[i][1];
        }
        Arrays.sort(sortedRanges, (a, b) -> (a[0] - b[0]));
        int[] dp = new int[n + 1];
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            int[] range = sortedRanges[i];
            int start = range[0];
            int end = range[1];
            int index = Arrays.binarySearch(sortedRanges, new int[]{end, -1}, (a, b) -> (a[0] - b[0]));
            if (index < 0) {
                index = -(index + 1);
            }
            dp[index] += dp[i];
            dp[index] %= 1000000007;
            dp[i + 1] += dp[i];
            dp[i + 1] %= 1000000007;
        }
        return dp[n];
    }
}