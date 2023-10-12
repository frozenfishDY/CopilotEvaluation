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
/**
 * @param {string} date
 * @return {string}
 */
var reformatDate = function(date) {    
    let month = new Map();
    month.set("Jan", "01");
    month.set("Feb", "02");
    month.set("Mar", "03");
    month.set("Apr", "04");
    month.set("May", "05");
    month.set("Jun", "06");
    month.set("Jul", "07");
    month.set("Aug", "08");
    month.set("Sep", "09");
    month.set("Oct", "10");
    month.set("Nov", "11");
    month.set("Dec", "12");
    let arr = date.split(" ");
    let day = arr[0].substr(0, arr[0].length - 2).padStart(2, "0");
    let res = arr[2] + "-" + month.get(arr[1]) + "-" + day;
    return res;
};