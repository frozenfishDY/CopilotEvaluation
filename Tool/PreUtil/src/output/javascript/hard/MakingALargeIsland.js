/**https://leetcode.com/problems/making-a-large-island/ */
//You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
//Return the size of the largest island in grid after applying this operation.
//An island is a 4-directionally connected group of 1s.


/**
 * @param {number[][]} grid
 * @return {number}
 */
var largestIsland = function(grid) {
    let n = grid.length;
    let m = grid[0].length;
    let visited = [];
    for(let i = 0; i < n; i++){
        visited.push([]);
        for(let j = 0; j < m; j++){
            visited[i].push(false);
        }
    }
    let islandSizes = [];
    let islandCount = 0;
    for(let i = 0; i < n; i++){
        for(let j = 0; j < m; j++){
            if(grid[i][j] === 1 && !visited[i][j]){
                islandCount++;
                let size = dfs(grid, visited, i, j, n, m);
                islandSizes.push(size);
            }
        }
    }
    let max = 0;
    for(let i = 0; i < n; i++){
        for(let j = 0; j < m; j++){
            if(grid[i][j] === 0){
                let size = 1;
                let set = new Set();
                if(i - 1 >= 0 && grid[i - 1][j] === 1){
                    set.add(grid[i - 1][j]);
                }
                if(i + 1 < n && grid[i + 1][j] === 1){
                    set.add(grid[i + 1][j]);
                }
                if(j - 1 >= 0 && grid[i][j - 1] === 1){
                    set.add(grid[i][j - 1]);
                }
                if(j + 1 < m && grid[i][j + 1] === 1){
                    set.add(grid[i][j + 1]);
                }
                for(let num of set){
                    size += islandSizes[num - 1];
                }
                max = Math.max(max, size);
            }
        }
    }
    if(max === 0){
        return n * m;
    }
    return max;
    
    
};

    