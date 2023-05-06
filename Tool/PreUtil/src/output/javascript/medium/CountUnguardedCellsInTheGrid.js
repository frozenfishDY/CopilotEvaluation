/**https://leetcode.com/problems/count-unguarded-cells-in-the-grid/ */
//You are given two integers m and n representing a 0-indexed m x n grid. You are also given two 2D integer arrays guards and walls where guards[i] = [rowi, coli] and walls[j] = [rowj, colj] represent the positions of the ith guard and jth wall respectively.
//A guard can see every cell in the four cardinal directions (north, east, south, or west) starting from their position unless obstructed by a wall or another guard. A cell is guarded if there is at least one guard that can see it.
//Return the number of unoccupied cells that are not guarded.


/**
 * @param {number} m
 * @param {number} n
 * @param {number[][]} guards
 * @param {number[][]} walls
 * @return {number}
 */
var countUnguarded = function(m, n, guards, walls) {
    let result = m * n;
    let seen = new Array(m).fill(0).map(() => new Array(n).fill(false));
    let dirs = [[0, 1], [0, -1], [1, 0], [-1, 0]];
    for (let i = 0; i < guards.length; i++) {
        let guard = guards[i];
        let x = guard[0];
        let y = guard[1];
        seen[x][y] = true;
        for (let j = 0; j < dirs.length; j++) {
            let dir = dirs[j];
            let dx = dir[0];
            let dy = dir[1];
            let nx = x + dx;
            let ny = y + dy;
            while (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                if (seen[nx][ny]) {
                    break;
                }
                seen[nx][ny] = true;
                nx += dx;
                ny += dy;
            }
        }
    }
    for (let i = 0; i < walls.length; i++) {
        let wall = walls[i];
        let x = wall[0];
        let y = wall[1];
        if (seen[x][y]) {
            result--;
            seen[x][y] = false;
        }
    }
    return result;
    
    
};

    