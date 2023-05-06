/**https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/ */
//You are given an m x n integer matrix grid and an array queries of size k.
//Find an array answer of size k such that for each integer queres[i] you start in the top left cell of the matrix and repeat the following process:
//    If queries[i] is strictly greater than the value of the current cell that you are in, then you get one point if it is your first time visiting this cell, and you can move to any adjacent cell in all 4 directions: up, down, left, and right.
//    Otherwise, you do not get any points, and you end this process.
//After the process, answer[i] is the maximum number of points you can get. Note that for each query you are allowed to visit the same cell multiple times.
//Return the resulting array answer.


/**
 * @param {number[][]} grid
 * @param {number[]} queries
 * @return {number[]}
 */
var maxPoints = function(grid, queries) {
    let m = grid.length;
    let n = grid[0].length;
    let pre = new Array(m + 1).fill(0).map(() => new Array(n + 1).fill(0));
    for(let i = 1; i <= m; i++){
        for(let j = 1; j <= n; j++){
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + grid[i - 1][j - 1];
        }
    }
    let res = [];
    for(let query of queries){
        let [x, y, z] = query;
        let l = 0;
        let r = Math.min(x, y) + 1;
        while(l < r){
            let mid = Math.floor((l + r) / 2);
            let sum = pre[x + 1][y + 1] - pre[x + 1][y - mid] - pre[x - mid][y + 1] + pre[x - mid][y - mid];
            if(sum <= z){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        res.push(l * l);
    }
    return res;
    
};

    