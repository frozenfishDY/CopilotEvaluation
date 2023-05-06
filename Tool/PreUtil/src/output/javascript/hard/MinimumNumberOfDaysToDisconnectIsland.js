/**https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/ */
//You are given an m x n binary grid grid where 1 represents land and 0 represents water. An island is a maximal 4-directionally (horizontal or vertical) connected group of 1's.
//The grid is said to be connected if we have exactly one island, otherwise is said disconnected.
//In one day, we are allowed to change any single land cell (1) into a water cell (0).
//Return the minimum number of days to disconnect the grid.


/**
 * @param {number[][]} grid
 * @return {number}
 */
var minDays = function(grid) {
    let m = grid.length;
    let n = grid[0].length;
    let pre = new Array(m + 1).fill(0).map(() => new Array(n + 1).fill(0));
    for(let i = 1; i <= m; i++){
        for(let j = 1; j <= n; j++){
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + grid[i - 1][j - 1];
        }
    }
    let res = 0;
    for(let i = 0; i < m; i++){
        for(let j = 0; j < n; j++){
            if(grid[i][j] == 0){
                continue;
            }
            let l = 0;
            let r = Math.min(i, j) + 1;
            while(l < r){
                let mid = Math.floor((l + r) / 2);
                let sum = pre[i + 1][j + 1] - pre[i + 1][j - mid] - pre[i - mid][j + 1] + pre[i - mid][j - mid];
                if(sum == 0){
                    r = mid;
                }else{
                    l = mid + 1;
                }
            }
            res = Math.max(res, l * l);
        }
    }
    return res;
    
    
};

    