/**https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/ */
//You are given an array of events where events[i] = [startDayi, endDayi, valuei]. The ith event starts at startDayi and ends at endDayi, and if you attend this event, you will receive a value of valuei. You are also given an integer k which represents the maximum number of events you can attend.
//You can only attend one event at a time. If you choose to attend an event, you must attend the entire event. Note that the end day is inclusive: that is, you cannot attend two events where one of them starts and the other ends on the same day.
//Return the maximum sum of values that you can receive by attending events.


class MaximumNumberOfEventsThatCanBeAttendedIi {
    public int maxValue(int[][] events, int k) {
        int n = events.length;
        Arrays.sort(events, (a, b) -> a[1] - b[1]);
        int[] dp = new int[n + 1];
        for(int i = 1; i <= n; i++){
            int[] event = events[i - 1];
            int start = event[0];
            int end = event[1];
            int value = event[2];
            int idx = binarySearch(events, start);
            dp[i] = Math.max(dp[i - 1], value + dp[idx]);
        }
        return dp[n];
        
        
    }
}
     
    