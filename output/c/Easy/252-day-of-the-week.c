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
char * dayOfTheWeek(int day, int month, int year){
int sum = 0;
    int i;
    char *week[7]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    for(i=1971;i<year;i++){
        if(i%4==0&&i%100!=0||i%400==0){
            sum+=366;
        }else{
            sum+=365;
        }
    }
    int monthDay[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    for(i=0;i<month-1;i++){
        if(i==1&&year%4==0&&year%100!=0||year%400==0){
            sum+=29;
        }else{
            sum+=monthDay[i];
        }
    }
    sum+=day;
    return week[(sum+4)%7];
}