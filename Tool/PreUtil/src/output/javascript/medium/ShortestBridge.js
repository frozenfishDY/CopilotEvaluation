/**https://leetcode.com/problems/shortest-bridge/ */
//You are given an n x n binary matrix grid where 1 represents land and 0 represents water.
//An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.
//You may change 0's to 1's to connect the two islands to form one island.
//Return the smallest number of 0's you must flip to connect the two islands.


/**
 * @param {number[][]} grid
 * @return {number}
 */
var shortestBridge = function(grid) {
    let n = grid.length;
    let m = grid[0].length;
    let visited = new Array(n).fill(0).map(() => new Array(m).fill(0));
    let result = Number.MAX_SAFE_INTEGER;
    let queue = [];
    let found = false;
    for(let i = 0; i < n; i++){
        if(found){
            break;
        }
        for(let j = 0; j < m; j++){
            if(grid[i][j] == 1){
                dfs(grid, visited, i, j, queue);
                found = true;
                break;
            }
        }
    }
    let steps = 0;
    while(queue.length > 0){
        let size = queue.length;
        for(let i = 0; i < size; i++){
            let [x, y] = queue.shift();
            if(x < 0 || x >= n || y < 0 || y >= m || visited[x][y] == 1){
                continue;
            }
            if(grid[x][y] == 1){
                result = Math.min(result, steps);
            }
            visited[x][y] = 1;
            queue.push([x + 1, y]);
            queue.push([x - 1, y]);
            queue.push([x, y + 1]);
            queue.push([x, y - 1]);
        }
        steps++;
    }
    return result;
    
    
    
};

    