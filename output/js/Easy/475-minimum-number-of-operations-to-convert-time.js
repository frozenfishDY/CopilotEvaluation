/**https://leetcode.com/problems/minimum-number-of-operations-to-convert-time/ */
//You are given two strings current and correct representing two 24-hour times.
//24-hour times are formatted as "HH:MM", where HH is between 00 and 23, and MM is between 00 and 59. The earliest 24-hour time is 00:00, and the latest is 23:59.
//In one operation you can increase the time current by 1, 5, 15, or 60 minutes. You can perform this operation any number of times.
//Return the minimum number of operations needed to convert current to correct.
// 
//Example 1:
//Input: current = "02:30", correct = "04:35"
//Output: 3
//Explanation:
//We can convert current to correct in 3 operations as follows:
//- Add 60 minutes to current. current becomes "03:30".
//- Add 60 minutes to current. current becomes "04:30".
//- Add 5 minutes to current. current becomes "04:35".
//It can be proven that it is not possible to convert current to correct in fewer than 3 operations.
//Example 2:
//Input: current = "11:00", correct = "11:01"
//Output: 1
//Explanation: We only have to add one minute to current, so the minimum number of operations needed is 1.
// 
//Constraints:
//	current and correct are in the format "HH:MM"
//	current <= correct
/**
 * @param {string} current
 * @param {string} correct
 * @return {number}
 */
var convertTime = function(current, correct) {
    let currentArr = current.split(':');
    let correctArr = correct.split(':');
    let currentMinutes = parseInt(currentArr[0]) * 60 + parseInt(currentArr[1]);
    let correctMinutes = parseInt(correctArr[0]) * 60 + parseInt(correctArr[1]);
    let result = 0;
    while (currentMinutes !== correctMinutes) {
        if (currentMinutes < correctMinutes) {
            if (currentMinutes + 60 <= correctMinutes) {
                result++;
                currentMinutes += 60;
            } else if (currentMinutes + 15 <= correctMinutes) {
                result++;
                currentMinutes += 15;
            } else if (currentMinutes + 5 <= correctMinutes) {
                result++;
                currentMinutes += 5;
            } else {
                result++;
                currentMinutes++;
            }
        } else {
            if (currentMinutes - 60 >= correctMinutes) {
                result++;
                currentMinutes -= 60;
            } else if (currentMinutes - 15 >= correctMinutes) {
                result++;
                currentMinutes -= 15;
            } else if (currentMinutes - 5 >= correctMinutes) {
                result++;
                currentMinutes -= 5;
            } else {
                result++;
                currentMinutes--;
            }
        }
    }
    return result;
};