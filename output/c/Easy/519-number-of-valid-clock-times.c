/**https://leetcode.com/problems/number-of-valid-clock-times/ */
//You are given a string of length 5 called time, representing the current time on a digital clock in the format "hh:mm". The earliest possible time is "00:00" and the latest possible time is "23:59".
//In the string time, the digits represented by the ? symbol are unknown, and must be replaced with a digit from 0 to 9.
//Return an integer answer, the number of valid clock times that can be created by replacing every ? with a digit from 0 to 9.
// 
//Example 1:
//Input: time = "?5:00"
//Output: 2
//Explanation: We can replace the ? with either a 0 or 1, producing "05:00" or "15:00". Note that we cannot replace it with a 2, since the time "25:00" is invalid. In total, we have two choices.
//Example 2:
//Input: time = "0?:0?"
//Output: 100
//Explanation: Each ? can be replaced by any digit from 0 to 9, so we have 100 total choices.
//Example 3:
//Input: time = "??:??"
//Output: 1440
//Explanation: There are 24 possible choices for the hours, and 60 possible choices for the minutes. In total, we have 24 * 60 = 1440 choices.
// 
//Constraints:
//	time is a valid string of length 5 in the format "hh:mm".
//	"00" <= hh <= "23"
//	"00" <= mm <= "59"
//	Some of the digits might be replaced with '?' and need to be replaced with digits from 0 to 9.
int countTime(char * time){
int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int n = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    int x = 0;
    int y = 0;
    int z = 0;
    int res = 0;
    if (time[0] == '?') {
        a = 0;
        b = 9;
    } else {
        a = time[0] - '0';
        b = time[0] - '0';
    }
    if (time[1] == '?') {
        c = 0;
        d = 9;
    } else {
        c = time[1] - '0';
        d = time[1] - '0';
    }
    if (time[3] == '?') {
        e = 0;
    } else {
        e = time[3] - '0';
    }
    if (time[4] == '?') {
        x = 0;
        y = 9;
        z = 9;
    } else {
        x = time[3] - '0';
        y = time[3] - '0';
        z = time[4] - '0';
    }
    for (i = a; i <= b; i++) {
        for (j = c; j <= d; j++) {
            for (k = e; k <= 5; k++) {
                for (l = x; l <= y; l++) {
                    for (m = z; m <= 9; m++) {
                        if (i == 2 && j > 3) {
                            break;
                        }
                        res++;
                    }
                }
            }
        }
    }
    return res;
}