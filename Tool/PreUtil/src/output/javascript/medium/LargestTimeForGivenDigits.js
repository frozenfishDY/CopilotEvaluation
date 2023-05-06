/**https://leetcode.com/problems/largest-time-for-given-digits/ */
//Given an array arr of 4 digits, find the latest 24-hour time that can be made using each digit exactly once.
//24-hour times are formatted as "HH:MM", where HH is between 00 and 23, and MM is between 00 and 59. The earliest 24-hour time is 00:00, and the latest is 23:59.
//Return the latest 24-hour time in "HH:MM" format. If no valid time can be made, return an empty string.


/**
 * @param {number[]} arr
 * @return {string}
 */
var largestTimeFromDigits = function(arr) {
    let result = "";
    let max = -1;
    for(let i = 0; i < 4; i++){
        for(let j = 0; j < 4; j++){
            if(j == i) continue;
            for(let k = 0; k < 4; k++){
                if(k == i || k == j) continue;
                let l = 6 - i - j - k;
                let hour = arr[i] * 10 + arr[j];
                let minute = arr[k] * 10 + arr[l];
                if(hour < 24 && minute < 60){
                    let time = hour * 60 + minute;
                    if(time > max){
                        max = time;
                        result = arr[i] + "" + arr[j] + ":" + arr[k] + "" + arr[l];
                    }
                }
            }
        }
    }
    return result;
    
};

    