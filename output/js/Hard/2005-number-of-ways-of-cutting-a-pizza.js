/**https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/ */
//Given a rectangular pizza represented as a rows x cols matrix containing the following characters: 'A' (an apple) and '.' (empty cell) and given the integer k. You have to cut the pizza into k pieces using k-1 cuts. 
//For each cut you choose the direction: vertical or horizontal, then you choose a cut position at the cell boundary and cut the pizza into two pieces. If you cut the pizza vertically, give the left part of the pizza to a person. If you cut the pizza horizontally, give the upper part of the pizza to a person. Give the last piece of pizza to the last person.
//Return the number of ways of cutting the pizza such that each piece contains at least one apple. Since the answer can be a huge number, return this modulo 10^9 + 7.


/**
 * @param {string[]} pizza
 * @param {number} k
 * @return {number}
 */
var ways = function(pizza, k) {
    let mod = 1000000007;
    let dp = new Array(k + 1);
    for(let i = 0; i < dp.length; i++){
        dp[i] = new Array(pizza.length + 1);
        for(let j = 0; j < dp[i].length; j++){
            dp[i][j] = new Array(pizza[0].length + 1).fill(0);
        }
    }
    let rowSum = new Array(pizza.length + 1);
    for(let i = 0; i < rowSum.length; i++){
        rowSum[i] = new Array(pizza[0].length + 1).fill(0);
    }
    let colSum = new Array(pizza.length + 1);
    for(let i = 0; i < colSum.length; i++){
        colSum[i] = new Array(pizza[0].length + 1).fill(0);
    }
    for(let i = pizza.length - 1; i >= 0; i--){
        for(let j = pizza[0].length - 1; j >= 0; j--){
            rowSum[i][j] = rowSum[i][j + 1];
            colSum[i][j] = colSum[i + 1][j];
            if(pizza[i][j] == 'A'){
                rowSum[i][j]++;
                colSum[i][j]++;
            }
        }
    }
    for(let i = 1; i <= pizza.length; i++){
        for(let j = 1; j <= pizza[0].length; j++){
            if(rowSum[i - 1][j - 1] > 0 || colSum[i - 1][j - 1] > 0){
                dp[1][i][j] = 1;
            }
        }
    }
    for(let i = 2; i <= k; i++){
        for(let j = 1; j <= pizza.length; j++){
            for(let l = 1; l <= pizza[0].length; l++){
                for(let m = j + 1; m <= pizza.length; m++){
                    if(rowSum[m - 1][l - 1] > 0){
                        dp[i][j][l] = (dp[i][j][l] + dp[i - 1][ m][l]) % mod;
                    }
                }
                for(let m = l + 1; m <= pizza[0].length; m++){
                        
    
};

    