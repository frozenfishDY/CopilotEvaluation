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
class Solution {
    public String reformatDate(String date) {
        String[] dateArray = date.split(" ");
        String day = dateArray[0];
        String month = dateArray[1];
        String year = dateArray[2];
        String res = year + "-";
        switch(month){
            case "Jan":
                res += "01-";
                break;
            case "Feb":
                res += "02-";
                break;
            case "Mar":
                res += "03-";
                break;
            case "Apr":
                res += "04-";
                break;
            case "May":
                res += "05-";
                break;
            case "Jun":
                res += "06-";
                break;
            case "Jul":
                res += "07-";
                break;
            case "Aug":
                res += "08-";
                break;
            case "Sep":
                res += "09-";
                break;
            case "Oct":
                res += "10-";
                break;
            case "Nov":
                res += "11-";
                break;
            case "Dec":
                res += "12-";
                break;
        }
        if(day.length() == 3){
            res += "0";
        }
        res += day.substring(0, day.length() - 2);
        return res;
    }
}