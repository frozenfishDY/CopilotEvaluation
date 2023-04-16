/**https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/ */
//You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). You can move up, down, left, or right from and to an empty cell in one step.
//Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.


/**
 * @param {number[][]} grid
 * @param {number} k
 * @return {number}
 */
var shortestPath = function(grid, k) {
    let n = grid.length;
    let m = grid[0].length;
    let visited = new Set();
    let queue = [[0, 0, 0, 0]];
    while(queue.length > 0){
        let [r, c, moves, obstacles] = queue.shift();
        if(r == n - 1 && c == m - 1){
            return moves;
        }
        let key = getKey(r, c, obstacles);
        if(visited.has(key)){
            continue;
        }
        visited.add(key);
        for(let [nr, nc] of [[r + 1, c], [r - 1, c], [r, c + 1], [r, c - 1]]){
            if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                if(grid[nr][nc] == 0){
                    queue.push([nr, nc, moves + 1, obstacles]);
                }
                else if(obstacles < k){
                    queue.push([nr, nc, moves + 1, obstacles + 1]);
                }
            }
        }
    }
    return -1;
    
};

    