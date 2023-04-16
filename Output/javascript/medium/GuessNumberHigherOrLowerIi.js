/**https://leetcode.com/problems/guess-number-higher-or-lower-ii/ */
//We are playing the Guessing Game. The game will work as follows:
//I pick a number between 1 and n.
//You guess a number.
//If you guess the right number, you win the game.
//If you guess the wrong number, then I will tell you whether the number I picked is higher or lower, and you will continue guessing.
//Every time you guess a wrong number x, you will pay x dollars. If you run out of money, you lose the game.
//Given a particular n, return the minimum amount of money you need to guarantee a win regardless of what number I pick.


/**
 * @param {number} n
 * @return {number}
 */
var getMoneyAmount = function(n) {
    let dp = new Array(n + 1).fill(0).map(() => new Array(n + 1).fill(0));
    for(let i = n - 1; i > 0; i--){
        for(let j = i + 1; j <= n; j++){
            let min = Number.MAX_SAFE_INTEGER;
            for(let k = i; k < j; k++){
                let temp = k + Math.max(dp[i][k - 1], dp[k + 1][j]);
                min = Math.min(min, temp);
            }
            dp[i][j] = min;
        }
    }
    return dp[1][n];
    
};

    