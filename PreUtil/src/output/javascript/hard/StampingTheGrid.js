/**https://leetcode.com/problems/stamping-the-grid/ */
//You are given an m x n binary matrix grid where each cell is either 0 (empty) or 1 (occupied).
//You are then given stamps of size stampHeight x stampWidth. We want to fit the stamps such that they follow the given restrictions and requirements:
//Cover all the empty cells.
//Do not cover any of the occupied cells.
//We can put as many stamps as we want.
//Stamps can overlap with each other.
//Stamps are not allowed to be rotated.
//Stamps must stay completely inside the grid.
//Return true if it is possible to fit the stamps while following the given restrictions and requirements. Otherwise, return false.


/**
 * @param {number[][]} grid
 * @param {number} stampHeight
 * @param {number} stampWidth
 * @return {boolean}
 */
var possibleToStamp = function(grid, stampHeight, stampWidth) {
    let m = grid.length;
    let n = grid[0].length;
    let ans = [];
    let flag = true;
    while(flag){
        flag = false;
        for(let i = 0; i < m; i++){
            for(let j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    let temp = dfs(grid, i, j, stampHeight, stampWidth);
                    if(temp.length > 0){
                        flag = true;
                        ans.push(temp);
                    }
                }
            }
        }
    }
    for(let i = 0; i < m; i++){
        for(let j = 0; j < n; j++){
            if(grid[i][j] == 0){
                return false;
            }
        }
    }
    return ans;
    
    
    
};

    