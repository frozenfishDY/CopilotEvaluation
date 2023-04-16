/**https://leetcode.com/problems/pacific-atlantic-water-flow/ */
//There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.
//The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).
//The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.
//Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.


/**
 * @param {number[][]} heights
 * @return {number[][]}
 */
var pacificAtlantic = function(heights) {
    let m = heights.length;
    let n = heights[0].length;
    let pacific = new Array(m).fill(0);
    let atlantic = new Array(m).fill(0);
    for(let i = 0; i < m; i++){
        pacific[i] = new Array(n).fill(0);
        atlantic[i] = new Array(n).fill(0);
    }
    for(let i = 0; i < m; i++){
        dfs(heights, pacific, i, 0, heights[i][0]);
        dfs(heights, atlantic, i, n - 1, heights[i][n - 1]);
    }
    for(let i = 0; i < n; i++){
        dfs(heights, pacific, 0, i, heights[0][i]);
        dfs(heights, atlantic, m - 1, i, heights[m - 1][i]);
    }
    let result = [];
    for(let i = 0; i < m; i++){
        for(let j = 0; j < n; j++){
            if(pacific[i][j] === 1 && atlantic[i][j] === 1){
                result.push([i, j]);
            }
        }
    }
    return result;
    
    
};

    