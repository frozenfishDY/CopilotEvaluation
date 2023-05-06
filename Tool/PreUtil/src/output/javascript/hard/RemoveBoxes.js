/**https://leetcode.com/problems/remove-boxes/ */
//You are given several boxes with different colors represented by different positive numbers.
//You may experience several rounds to remove boxes until there is no box left. Each time you can choose some continuous boxes with the same color (i.e., composed of k boxes, k >= 1), remove them and get k * k points.
//Return the maximum points you can get.


/**
 * @param {number[]} boxes
 * @return {number}
 */
var removeBoxes = function(boxes) {
    let n = boxes.length;
    let dp = [];
    for(let i = 0; i <= n; i++){
        dp.push([]);
        for(let j = 0; j <= n; j++){
            dp[i].push([]);
            for(let k = 0; k <= n; k++){
                dp[i][j].push(0);
            }
        }
    }
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= n; j++){
            for(let k = 1; k <= n; k++){
                if(i - j >= 0 && boxes[i - 1] == boxes[i - j - 1]){
                    dp[i][j][k] = dp[i - 1][j][k + 1];
                }
                else{
                    dp[i][j][k] = dp[i - 1][j][k] + k * k;
                }
            }
        }
    }
    return dp[n][n][1];
    
};

    