/**https://leetcode.com/problems/latest-time-by-replacing-hidden-digits/ */
//You are given a string time in the form of  hh:mm, where some of the digits in the string are hidden (represented by ?).
//The valid times are those inclusively between 00:00 and 23:59.
//Return the latest valid time you can get from time by replacing the hidden digits.
// 
//Example 1:
//Input: time = "2?:?0"
//Output: "23:50"
//Explanation: The latest hour beginning with the digit '2' is 23 and the latest minute ending with the digit '0' is 50.
//Example 2:
//Input: time = "0?:3?"
//Output: "09:39"
//Example 3:
//Input: time = "1?:22"
//Output: "19:22"
// 
//Constraints:
//	time is in the format hh:mm.
//	It is guaranteed that you can produce a valid time from the given string.
class Solution {
    public String maximumTime(String time) {
        String[] s = time.split(":");
        String hour = s[0];
        String minute = s[1];
        if (hour.charAt(0) == '?') {
            if (hour.charAt(1) == '?') {
                hour = "23";
            } else {
                if (hour.charAt(1) >= '4') {
                    hour = "1" + hour.charAt(1);
                } else {
                    hour = "2" + hour.charAt(1);
                }
            }
        } else {
            if (hour.charAt(1) == '?') {
                if (hour.charAt(0) == '2') {
                    hour = "23";
                } else {
                    hour = hour.charAt(0) + "9";
                }
            }
        }
        if (minute.charAt(0) == '?') {
            if (minute.charAt(1) == '?') {
                minute = "59";
            } else {
                minute = "5" + minute.charAt(1);
            }
        } else {
            if (minute.charAt(1) == '?') {
                minute = minute.charAt(0) + "9";
            }
        }
        return hour + ":" + minute;

    }
}