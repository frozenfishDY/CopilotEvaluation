/**https://leetcode.com/problems/least-operators-to-express-number/ */
//Given a single positive integer x, we will write an expression of the form x (op1) x (op2) x (op3) x ... where each operator op1, op2, etc. is either addition, subtraction, multiplication, or division (+, -, *, or /). For example, with x = 3, we might write 3 * 3 / 3 + 3 - 3 which is a value of 3.
//When writing such an expression, we adhere to the following conventions:
//The division operator (/) returns rational numbers.
//There are no parentheses placed anywhere.
//We use the usual order of operations: multiplication and division happen before addition and subtraction.
//It is not allowed to use the unary negation operator (-). For example, "x - x" is a valid expression as it only uses subtraction, but "-x + x" is not because it uses negation.
//We would like to write an expression with the least number of operators such that the expression equals the given target. Return the least number of operators used.


/**
 * @param {number} x
 * @param {number} target
 * @return {number}
 */
var leastOpsExpressTarget = function(x, target) {
    let dp = [];
    for(let i = 0; i <= x; i++){
        dp.push([]);
        for(let j = 0; j <= target; j++){
            dp[i].push(0);
        }
    }
    for(let i = 0; i <= x; i++){
        dp[i][0] = 1;
    }
    for(let i = 1; i <= x; i++){
        for(let j = 1; j <= target; j++){
            if(i > j){
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    let ans = [];
    for(let i = 1; i <= target; i++){
        ans.push(dp[x][i] - dp[x][i - 1]);
    }
    return ans;
    
};

    