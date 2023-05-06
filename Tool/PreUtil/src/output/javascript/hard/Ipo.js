/**https://leetcode.com/problems/ipo/ */
//Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited resources, it can only finish at most k distinct projects before the IPO. Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.
//You are given n projects where the ith project has a pure profit profits[i] and a minimum capital of capital[i] is needed to start it.
//Initially, you have w capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.
//Pick a list of at most k distinct projects from given projects to maximize your final capital, and return the final maximized capital.
//The answer is guaranteed to fit in a 32-bit signed integer.


/**
 * @param {number} k
 * @param {number} w
 * @param {number[]} profits
 * @param {number[]} capital
 * @return {number}
 */
var findMaximizedCapital = function(k, w, profits, capital) {
    let n = profits.length;
    let dp = [];
    for(let i = 0; i <= n; i++){
        dp.push([]);
        for(let j = 0; j <= k; j++){
            dp[i].push([]);
            for(let l = 0; l <= k; l++){
                dp[i][j].push(0);
            }
        }
    }
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= k; j++){
            for(let l = 1; l <= k; l++){
                if(i - j >= 0 && Math.abs(profits[i - 1] - profits[i - j - 1]) <= k){
                    dp[i][j][l] = true;
                }
                else{
                    dp[i][j][l] = dp[i - 1][j][l];
                }
            }
        }
    }
    return dp[n][k][k];
    
};

    