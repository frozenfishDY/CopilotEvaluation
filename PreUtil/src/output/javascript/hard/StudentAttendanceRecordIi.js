/**https://leetcode.com/problems/student-attendance-record-ii/ */
//An attendance record for a student can be represented as a string where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:
//'A': Absent.
//'L': Late.
//'P': Present.
//Any student is eligible for an attendance award if they meet both of the following criteria:
//The student was absent ('A') for strictly fewer than 2 days total.
//The student was never late ('L') for 3 or more consecutive days.
//Given an integer n, return the number of possible attendance records of length n that make a student eligible for an attendance award. The answer may be very large, so return it modulo 109 + 7.


/**
 * @param {number} n
 * @return {number}
 */
var checkRecord = function(n) {
    let dp = [];
    for(let i = 0; i <= n; i++){
        dp.push([]);
        for(let j = 0; j <= 2; j++){
            dp[i].push([]);
            for(let k = 0; k <= 3; k++){
                dp[i][j].push(0);
            }
        }
    }
    dp[0][0][0] = 1;
    for(let i = 1; i <= n; i++){
        for(let j = 0; j <= 2; j++){
            for(let k = 0; k <= 3; k++){
                dp[i][j][0] += dp[i - 1][j][k];
                if(j < 2){
                    dp[i][j + 1][0] += dp[i - 1][j][k];
                }
                if(k < 3){
                    dp[i][j][k + 1] += dp[i - 1][j][k];
                }
            }
        }
    }
    let ans = 0;
    for(let j = 0; j <= 2; j++){
        for(let k = 0; k <= 3; k++){
            ans += dp[n][j][k];
        }
    }
    return ans % 1000000007;
    
    
};

    