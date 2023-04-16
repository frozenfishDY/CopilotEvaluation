/**https://leetcode.com/problems/consecutive-numbers-sum/ */
//Given an integer n, return the number of ways you can write n as the sum of consecutive positive integers.


/**
 * @param {number} n
 * @return {number}
 */
var consecutiveNumbersSum = function(n) {
    let ans = 0;
    for (let i = 1; i * (i - 1) / 2 < n; i++) {
        if ((n - i * (i - 1) / 2) % i === 0) {
            ans++;
        }
    }
    return ans;
    
};

    