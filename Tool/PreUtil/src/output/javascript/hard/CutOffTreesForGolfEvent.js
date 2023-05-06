/**https://leetcode.com/problems/cut-off-trees-for-golf-event/ */
//You are asked to cut off all the trees in a forest for a golf event. The forest is represented as an m x n matrix. In this matrix:
//0 means the cell cannot be walked through.
//1 represents an empty cell that can be walked through.
//A number greater than 1 represents a tree in a cell that can be walked through, and this number is the tree's height.
//In one step, you can walk in any of the four directions: north, east, south, and west. If you are standing in a cell with a tree, you can choose whether to cut it off.
//You must cut off the trees in order from shortest to tallest. When you cut off a tree, the value at its cell becomes 1 (an empty cell).
//Starting from the point (0, 0), return the minimum steps you need to walk to cut off all the trees. If you cannot cut off all the trees, return -1.
//Note: The input is generated such that no two trees have the same height, and there is at least one tree needs to be cut off.


/**
 * @param {number[][]} forest
 * @return {number}
 */
var cutOffTree = function(forest) {
    let m = forest.length;
    let n = forest[0].length;
    let dp = [];
    for(let i = 0; i <= m; i++){
        dp.push([]);
        for(let j = 0; j <= n; j++){
            dp[i].push(0);
        }
    }
    for(let i = 0; i <= m; i++){
        dp[i][0] = 1;
    }
    for(let i = 1; i <= m; i++){
        for(let j = 1; j <= n; j++){
            if(forest[i - 1][j - 1] > forest[i - 1][j]){
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    let ans = 0;
    for(let i = 1; i <= m; i++){
        ans += dp[m][i];
    }
    return ans;
    
};

    