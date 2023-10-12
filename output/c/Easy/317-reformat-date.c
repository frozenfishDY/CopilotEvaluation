/**https://leetcode.com/problems/reformat-date/ */
//Given a date string in the form Day Month Year, where:
//	Day is in the set {"1st", "2nd", "3rd", "4th", ..., "30th", "31st"}.
//	Month is in the set {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}.
//	Year is in the range [1900, 2100].
//Convert the date string to the format YYYY-MM-DD, where:
//	YYYY denotes the 4 digit year.
//	MM denotes the 2 digit month.
//	DD denotes the 2 digit day.
// 
//Example 1:
//Input: date = "20th Oct 2052"
//Output: "2052-10-20"
//Example 2:
//Input: date = "6th Jun 1933"
//Output: "1933-06-06"
//Example 3:
//Input: date = "26th May 1960"
//Output: "1960-05-26"
// 
//Constraints:
//	The given dates are guaranteed to be valid, so no error handling is necessary.
char * reformatDate(char * date){ 
char *result = (char *)malloc(sizeof(char) * 11);
    int i = 0, j = 0;
    char *month = (char *)malloc(sizeof(char) * 4);
    char *day = (char *)malloc(sizeof(char) * 3);
    char *year = (char *)malloc(sizeof(char) * 5);
    for(i = 0; i < 4; i++)
        year[i] = date[i + 8];
    year[4] = '\0';
    for(i = 0; i < 3; i++)
        month[i] = date[i + 4];
    month[3] = '\0';
    for(i = 0; i < 2; i++)
        day[i] = date[i + 1];
    day[2] = '\0';
    char *months[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    for(i = 0; i < 12; i++){
        if(strcmp(month, months[i]) == 0){
            if(i < 9)
                sprintf(month, "0%d", i + 1);
            else
                sprintf(month, "%d", i + 1);
            break;
        }
    }
    sprintf(result, "%s-%s-%s", year, month, day);
    return result;
}