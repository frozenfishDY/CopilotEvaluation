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
bool haveConflict(char ** event1, int event1Size, char ** event2, int event2Size){
int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int n = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    int x = 0;
    int y = 0;
    int z = 0;
    a = (event1[0][0] - '0') * 10 + event1[0][1] - '0';
    b = (event1[0][3] - '0') * 10 + event1[0][4] - '0';
    c = (event1[1][0] - '0') * 10 + event1[1][1] - '0';
    d = (event1[1][3] - '0') * 10 + event1[1][4] - '0';
    e = (event2[0][0] - '0') * 10 + event2[0][1] - '0';
    x = (event2[0][3] - '0') * 10 + event2[0][4] - '0';
    y = (event2[1][0] - '0') * 10 + event2[1][1] - '0';
    z = (event2[1][3] - '0') * 10 + event2[1][4] - '0';
    if ((a < e && c < e) || (a > y && c > y) || (e < a && y < a) || (e > c && y > c)) {
        return false;
    }
    if ((b < x && d < x) || (b > z && d > z) || (x < b && z < b) || (x > d && z > d)) {
        return false;
    }
    return true;
}