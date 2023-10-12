/**https://leetcode.com/problems/determine-if-two-events-have-conflict/ */
//You are given two arrays of strings that represent two inclusive events that happened on the same day, event1 and event2, where:
//	event1 = [startTime1, endTime1] and
//	event2 = [startTime2, endTime2].
//Event times are valid 24 hours format in the form of HH:MM.
//A conflict happens when two events have some non-empty intersection (i.e., some moment is common to both events).
//Return true if there is a conflict between two events. Otherwise, return false.
// 
//Example 1:
//Input: event1 = ["01:15","02:00"], event2 = ["02:00","03:00"]
//Output: true
//Explanation: The two events intersect at time 2:00.
//Example 2:
//Input: event1 = ["01:00","02:00"], event2 = ["01:20","03:00"]
//Output: true
//Explanation: The two events intersect starting from 01:20 to 02:00.
//Example 3:
//Input: event1 = ["10:00","11:00"], event2 = ["14:00","15:00"]
//Output: false
//Explanation: The two events do not intersect.
// 
//Constraints:
//	evnet1.length == event2.length == 2.
//	event1[i].length == event2[i].length == 5
//	startTime1 <= endTime1
//	startTime2 <= endTime2
//	All the event times follow the HH:MM format.
class Solution {
    public boolean haveConflict(String[] event1, String[] event2) {
        String[] start1 = event1[0].split(":");
        String[] end1 = event1[1].split(":");
        String[] start2 = event2[0].split(":");
        String[] end2 = event2[1].split(":");
        int start1Hour = Integer.parseInt(start1[0]);
        int start1Min = Integer.parseInt(start1[1]);
        int end1Hour = Integer.parseInt(end1[0]);
        int end1Min = Integer.parseInt(end1[1]);
        int start2Hour = Integer.parseInt(start2[0]);
        int start2Min = Integer.parseInt(start2[1]);
        int end2Hour = Integer.parseInt(end2[0]);
        int end2Min = Integer.parseInt(end2[1]);
        if (start1Hour > end2Hour || start2Hour > end1Hour) {
            return false;
        }
        if (start1Hour == end2Hour && start1Min >= end2Min) {
            return false;
        }
        if (start2Hour == end1Hour && start2Min >= end1Min) {
            return false;
        }
        return true;
    }
}