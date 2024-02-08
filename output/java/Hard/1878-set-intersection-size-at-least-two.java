/**https://leetcode.com/problems/set-intersection-size-at-least-two/ */
//You are given a 2D integer array intervals where intervals[i] = [starti, endi] represents all the integers from starti to endi inclusively.
//A containing set is an array nums where each interval from intervals has at least two integers in nums.
//For example, if intervals = [[1,3], [3,7], [8,9]], then [1,2,4,7,8,9] and [2,3,4,8,9] are containing sets.
//Return the minimum possible size of a containing set.


class SetIntersectionSizeAtLeastTwo {
    public int intersectionSizeTwo(int[][] intervals) {
        int n = intervals.length;
        Arrays.sort(intervals, (a, b) -> a[1] != b[1] ? a[1] - b[1] : b[0] - a[0]);
        int[] dp = new int[n + 1];
        int[] count = new int[n + 1];
        int[] sum = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            count[nums[i - 1]]++;
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        for (int i = 1; i <= n; i++) {
            dp[i] = i;
            for (int j = 1; j <= k; j++) {
                int l = 0;
                int r = i;
                while (l < r) {
                    int mid = l + r + 1 >> 1;
                    if (count[nums[mid - 1]] == 1) {
                        l = mid;
                    } else {
                        r = mid - 1;
                    }
                }
                dp[i] = Math.min(dp[i], dp[l] + i - l - (sum[i] - sum[l]));
            }
        }
        return dp[n];
        
    }
}
     
    