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
int daysBetweenDates(char * date1, char * date2){  
    int days = 0;
    int year1 = 0, month1 = 0, day1 = 0;
    int year2 = 0, month2 = 0, day2 = 0;
    sscanf(date1, "%d-%d-%d", &year1, &month1, &day1);
    sscanf(date2, "%d-%d-%d", &year2, &month2, &day2);
    
    int daysOfMonths[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if((year1 % 4 == 0 && year1 % 100 != 0) || year1 % 400 == 0)
        daysOfMonths[1] = 29;
    int i = 0;
    for(i = 0; i < month1 - 1; i++)
        days += daysOfMonths[i];
    days += day1;
    
    if((year2 % 4 == 0 && year2 % 100 != 0) || year2 % 400 == 0)
        daysOfMonths[1] = 29;
    else
        daysOfMonths[1] = 28;
    for(i = 0; i < month2 - 1; i++)
        days -= daysOfMonths[i];
    days -= day2;
    
    if(year1 == year2)
        return abs(days);
    else{
        int year = 0;
        if(year1 < year2){
            for(year = year1; year < year2; year++){
                if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                    days += 366;
                else
                    days += 365;
            }
        }
        else{
            for(year = year2; year < year1; year++){
                if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                    days -= 366;
                else
                    days -= 365;
            }
        }
    }
    return abs(days);
}