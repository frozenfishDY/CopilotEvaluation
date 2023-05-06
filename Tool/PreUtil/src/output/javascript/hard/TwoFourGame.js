/**https://leetcode.com/problems/24-game/ */
//You are given an integer array cards of length 4. You have four cards, each containing a number in the range [1, 9]. You should arrange the numbers on these cards in a mathematical expression using the operators ['+', '-', '*', '/'] and the parentheses '(' and ')' to get the value 24.
//You are restricted with the following rules:
//The division operator '/' represents real division, not integer division.
//For example, 4 / (1 - 2 / 3) = 4 / (1 / 3) = 12.
//Every operation done is between two numbers. In particular, we cannot use '-' as a unary operator.
//For example, if cards = [1, 1, 1, 1], the expression "-1 - 1 - 1 - 1" is not allowed.
//You cannot concatenate numbers together
//For example, if cards = [1, 2, 1, 2], the expression "12 + 12" is not valid.
//Return true if you can get such expression that evaluates to 24, and false otherwise.


/**
 * @param {number[]} cards
 * @return {boolean}
 */
var judgePoint24 = function(cards) {
    let n = cards.length;
    let dp = [];
    for(let i = 0; i <= n; i++){
        dp.push([]);
        for(let j = 0; j <= n; j++){
            dp[i].push([]);
            for(let k = 0; k <= n; k++){
                dp[i][j].push([]);
                for(let l = 0; l <= n; l++){
                    dp[i][j][k].push(false);
                }
            }
        }
    }
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= n; j++){
            for(let k = 1; k <= n; k++){
                for(let l = 1; l <= n; l++){
                    if(i + j + k + l == n + 1){
                        dp[i][j][k][l] = check(cards[i - 1], cards[j - 1], cards[k - 1], cards[l - 1]);
                    }
                    else{
                        dp[i][j][k][l] = dp[i - 1][j][k][l] || dp[i][j - 1][k][l] || dp[i][j][k - 1][l] || dp[i][j][k][l - 1];
                    }
                }
            }
        }
    }
    return dp[n][n][n][n];
    
    
};

    