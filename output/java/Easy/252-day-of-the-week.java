/**https://leetcode.com/problems/day-of-the-week/ */
//Given a date, return the corresponding day of the week for that date.
//The input is given as three integers representing the day, month and year respectively.
//Return the answer as one of the following values {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}.
// 
//Example 1:
//Input: day = 31, month = 8, year = 2019
//Output: "Saturday"
//Example 2:
//Input: day = 18, month = 7, year = 1999
//Output: "Sunday"
//Example 3:
//Input: day = 15, month = 8, year = 1993
//Output: "Sunday"
// 
//Constraints:
//	The given dates are valid dates between the years 1971 and 2100.
class Solution {
    public String dayOfTheWeek(int day, int month, int year) {
        String[] week = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	    int[] daysOfMonth = {31,28,31,30,31,30,31,31,30,31,30,31};
	    int res = 4;
	    for(int i = 1971; i < year; i++){
	        res += isLeap(i) ? 366 : 365;
	    }
	    for(int i = 0; i < month - 1; i++){
	        res += daysOfMonth[i];
	    }
	    res += day;
	    if(isLeap(year) && month > 2) res++;
	    return week[res % 7];
    }
    public boolean isLeap(int year){
	    if(year % 100 == 0) return year % 400 == 0;
	    return year % 4 == 0;
	}
}