/**https://leetcode.com/problems/angle-between-hands-of-a-clock/ */
//Given two numbers, hour and minutes, return the smaller angle (in degrees) formed between the hour and the minute hand.
//Answers within 10-5 of the actual value will be accepted as correct.
// 
//Example 1:
//Input: hour = 12, minutes = 30
//Output: 165
//Example 2:
//Input: hour = 3, minutes = 30
//Output: 75
//Example 3:
//Input: hour = 3, minutes = 15
//Output: 7.5
// 
//Constraints:
//	1 <= hour <= 12
//	0 <= minutes <= 59
double angleClock(int hour, int minutes){
double res = 0;
    if (hour == 12) {
        hour = 0;
    }
    res = fabs(hour * 30 + minutes * 0.5 - minutes * 6);
    return fmin(res, 360 - res);
}