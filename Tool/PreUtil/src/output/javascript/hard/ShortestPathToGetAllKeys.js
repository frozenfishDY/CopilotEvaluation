/**https://leetcode.com/problems/shortest-path-to-get-all-keys/ */
//You are given an m x n grid grid where:
//'.' is an empty cell.
//'#' is a wall.
//'@' is the starting point.
//Lowercase letters represent keys.
//Uppercase letters represent locks.
//You start at the starting point and one move consists of walking one space in one of the four cardinal directions. You cannot walk outside the grid, or walk into a wall.
//If you walk over a key, you can pick it up and you cannot walk over a lock unless you have its corresponding key.
//For some 1 <= k <= 6, there is exactly one lowercase and one uppercase letter of the first k letters of the English alphabet in the grid. This means that there is exactly one key for each lock, and one lock for each key; and also that the letters used to represent the keys and locks were chosen in the same order as the English alphabet.
//Return the lowest number of moves to acquire all keys. If it is impossible, return -1.


/**
 * @param {string[]} grid
 * @return {number}
 */
var shortestPathAllKeys = function(grid) {
    let n = grid.length;
    let m = grid[0].length;
    let start = [];
    let keys = [];
    let locks = [];
    for(let i = 0; i < n; i++){
        for(let j = 0; j < m; j++){
            if(grid[i][j] == '@'){
                start = [i, j];
            }
            if(grid[i][j] >= 'a' && grid[i][j] <= 'f'){
                keys.push([i, j]);
            }
            if(grid[i][j] >= 'A' && grid[i][j] <= 'F'){
                locks.push([i, j]);
            }
        }
    }
    let dp = [];
    for(let i = 0; i < n; i++){
        dp.push([]);
        for(let j = 0; j < m; j++){
            dp[i].push([]);
            for(let k = 0; k < 64; k++){
                dp[i][j].push(-1);
            }
        }
    }
    let queue = [];
    queue.push([start[0], start[1], 0]);
    dp[start[0]][start[1]][0] = 0;
    let dir = [[1, 0], [-1, 0], [0, 1], [0, -1]];
    while(queue.length > 0){
        let cur = queue.shift();
        let x = cur[0];
        let y = cur[1];
        let mask = cur[2];
        for(let i = 0; i < 4; i++){
            let nx = x + dir[i][0];
            let ny = y + dir[i][1];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#'){
                let nmask = mask;
                if(grid[nx][ny] >= 'a' && grid[nx][ny] <= 'f'){
                    nmask |= (1 << (grid[nx][ny].charCodeAt() - 'a'.charCodeAt()));
                }
                if(grid[nx][ny] >= 'A' && grid[nx][ny] <= 'F'){
                    if((nmask & (1 << (grid[nx][ny].charCodeAt() - 'A'.charCodeAt()))) == 0){
                        continue;
                    }
                }
                if(dp[nx][ny][nmask] == -1){
                    dp[nx][ny][nmask] = dp[x][y][mask] + 1;
                    queue.push([nx, ny, nmask]);
                }
            }
        }
    }
    let result = Infinity;
    for(let i = 0; i < 64; i++){
        if(dp[start[0]][start[1]][i] != -1){
            result = Math.min(result, dp[start[0]][start[1]][i]);
        }
    }
    if(result == Infinity){
        return -1;
    }
    return result;
    
    
};

    