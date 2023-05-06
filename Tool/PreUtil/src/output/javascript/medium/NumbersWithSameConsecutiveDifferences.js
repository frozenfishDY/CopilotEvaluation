/**https://leetcode.com/problems/numbers-with-same-consecutive-differences/ */
//Given two integers n and k, return an array of all the integers of length n where the difference between every two consecutive digits is k. You may return the answer in any order.
//Note that the integers should not have leading zeros. Integers as 02 and 043 are not allowed.


/**
 * @param {number} n
 * @param {number} k
 * @return {number[]}
 */
var numsSameConsecDiff = function(n, k) {
    let ans = [];
    let dfs = (num, len) => {
        if(len == n){
            ans.push(num);
            return;
        }
        let lastDigit = num % 10;
        if(lastDigit + k <= 9){
            dfs(num * 10 + lastDigit + k, len + 1);
        }
        if(k != 0 && lastDigit - k >= 0){
            dfs(num * 10 + lastDigit - k, len + 1);
        }
    }
    for(let i = 1; i <= 9; i++){
        dfs(i, 1);
    }
    if(n == 1){
        ans.push(0);
    }
    return ans;
    
};

    