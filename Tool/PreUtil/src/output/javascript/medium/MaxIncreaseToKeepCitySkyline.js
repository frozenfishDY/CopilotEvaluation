/**https://leetcode.com/problems/max-increase-to-keep-city-skyline/ */
//There is a city composed of n x n blocks, where each block contains a single building shaped like a vertical square prism. You are given a 0-indexed n x n integer matrix grid where grid[r][c] represents the height of the building located in the block at row r and column c.
//A city's skyline is the the outer contour formed by all the building when viewing the side of the city from a distance. The skyline from each cardinal direction north, east, south, and west may be different.
//We are allowed to increase the height of any number of buildings by any amount (the amount can be different per building). The height of a 0-height building can also be increased. However, increasing the height of a building should not affect the city's skyline from any cardinal direction.
//Return the maximum total sum that the height of the buildings can be increased by without changing the city's skyline from any cardinal direction.


/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxIncreaseKeepingSkyline = function(grid) {
    let n = grid.length;
    let m = grid[0].length;
    let topBottom = new Array(n).fill(0);
    let leftRight = new Array(m).fill(0);
    for(let i = 0; i < n; i++){
        for(let j = 0; j < m; j++){
            topBottom[i] = Math.max(topBottom[i], grid[i][j]);
            leftRight[j] = Math.max(leftRight[j], grid[i][j]);
        }
    }
    let result = 0;
    for(let i = 0; i < n; i++){
        for(let j = 0; j < m; j++){
            result += Math.min(topBottom[i], leftRight[j]) - grid[i][j];
        }
    }
    return result;
    
};

    