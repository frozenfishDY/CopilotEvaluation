/**https://leetcode.com/problems/number-of-days-between-two-dates/ */
//Write a program to count the number of days between two dates.
//The two dates are given as strings, their format is YYYY-MM-DD as shown in the examples.
// 
//Example 1:
//Input: date1 = "2019-06-29", date2 = "2019-06-30"
//Output: 1
//Example 2:
//Input: date1 = "2020-01-15", date2 = "2019-12-31"
//Output: 15
// 
//Constraints:
//	The given dates are valid dates between the years 1971 and 2100.
class Solution {
    public int daysBetweenDates(String date1, String date2) {
        int[] days = new int[]{31,28,31,30,31,30,31,31,30,31,30,31};
        int[] daysLeap = new int[]{31,29,31,30,31,30,31,31,30,31,30,31};
        int res = 0;
        String[] date1Array = date1.split("-");
        String[] date2Array = date2.split("-");
        int year1 = Integer.valueOf(date1Array[0]);
        int year2 = Integer.valueOf(date2Array[0]);
        int month1 = Integer.valueOf(date1Array[1]);
        int month2 = Integer.valueOf(date2Array[1]);
        int day1 = Integer.valueOf(date1Array[2]);
        int day2 = Integer.valueOf(date2Array[2]);
        for(int i = year1; i < year2; i++){
            if(isLeap(i)){
                res += 366;
            }else{
                res += 365;
            }
        }
        if(isLeap(year1)){
            for(int i = 0; i < month1 - 1; i++){
                res -= daysLeap[i];
            }
            res -= day1;
        }else{
            for(int i = 0; i < month1 - 1; i++){
                res -= days[i];
            }
            res -= day1;
        }
        if(isLeap(year2)){
            for(int i = 0; i < month2 - 1; i++){
                res += daysLeap[i];
            }
            res += day2;
        }else{
            for(int i = 0; i < month2 - 1; i++){
                res += days[i];
            }
            res += day2;
        }
        return Math.abs(res);
    }
    private boolean isLeap(int year){
        if(year % 400 == 0){
            return true;
        }else if(year % 100 == 0){
            return false;
        }else if(year % 4 == 0){
            return true;
        }else{
            return false;
        }
    }
}