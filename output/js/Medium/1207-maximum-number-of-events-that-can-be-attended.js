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
/**
 * @param {number[][]} events
 * @return {number}
 */
var maxEvents = function(events) {  
    events.sort((a,b) => a[1] - b[1]);
    let max = 0;
    let day = 0;
    let i = 0;
    while (events.length > 0) {
        if (events[i][0] <= day) {
            day++;
            events.splice(i, 1);
            i = 0;
        } else {
            if (i === events.length - 1) {
                day++;
                events.splice(i, 1);
                i = 0;
            } else {
                i++;
            }
        }
    }
    return day;
};