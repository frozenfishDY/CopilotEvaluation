/**https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/ */
//You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.
//You can attend an event i at any day d where startTimei <= d <= endTimei. You can only attend one event at any time d.
//Return the maximum number of events you can attend.
// 
//Example 1:
//Input: events = [[1,2],[2,3],[3,4]]
//Output: 3
//Explanation: You can attend all the three events.
//One way to attend them all is as shown.
//Attend the first event on day 1.
//Attend the second event on day 2.
//Attend the third event on day 3.
//Example 2:
//Input: events= [[1,2],[2,3],[3,4],[1,2]]
//Output: 4
// 
//Constraints:
//	1 <= events.length <= 105
//	events[i].length == 2
//	1 <= startDayi <= endDayi <= 105
int maxEvents(int** events, int eventsSize, int* eventsColSize){
int *dp = (int *)malloc(sizeof(int) * (eventsSize + 1));
    memset(dp, 0, sizeof(int) * (eventsSize + 1));
    int res = 0;
    for (int i = 1; i <= eventsSize; ++i) {
        dp[i] = dp[i - 1];
        for (int j = 0; j < eventsSize; ++j) {
            if (events[j][0] > i) {
                continue;
            }
            dp[i] = fmax(dp[i], dp[events[j][0] - 1] + 1);
        }
        res = fmax(res, dp[i]);
    }
    return res;
}