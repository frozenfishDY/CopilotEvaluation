/**https://leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location/ */
//A storekeeper is a game in which the player pushes boxes around in a warehouse trying to get them to target locations.
//The game is represented by an m x n grid of characters grid where each element is a wall, floor, or box.
//Your task is to move the box 'B' to the target position 'T' under the following rules:
//The character 'S' represents the player. The player can move up, down, left, right in grid if it is a floor (empty cell).
//The character '.' represents the floor which means a free cell to walk.
//The character '#' represents the wall which means an obstacle (impossible to walk there).
//There is only one box 'B' and one target cell 'T' in the grid.
//The box can be moved to an adjacent free cell by standing next to the box and then moving in the direction of the box. This is a push.
//The player cannot walk through the box.
//Return the minimum number of pushes to move the box to the target. If there is no way to reach the target, return -1.


/**
 * @param {character[][]} grid
 * @return {number}
 */
var minPushBox = function(grid) {
    let n = grid.length;
    let m = grid[0].length;
    let box = null;
    let target = null;
    let player = null;
    for(let i = 0; i < n; i++){
        for(let j = 0; j < m; j++){
            if(grid[i][j] == 'B'){
                box = [i, j];
            }
            if(grid[i][j] == 'T'){
                target = [i, j];
            }
            if(grid[i][j] == 'S'){
                player = [i, j];
            }
        }
    }
    let visited = new Set();
    let queue = [[player[0], player[1], box[0], box[1], 0]];
    while(queue.length > 0){
        let [r, c, br, bc, moves] = queue.shift();
        if(br == target[0] && bc == target[1]){
            return moves;
        }
        if(visited.has(getKey(r, c, br, bc))){
            continue;
        }
        visited.add(getKey(r, c, br, bc));
        for(let [dr, dc] of [[0, 1], [0, -1], [1, 0], [-1, 0]]){
            let nr = r + dr;
            let nc = c + dc;
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '#'){
                if(nr == br && nc == bc){
                    let nbr = br + dr;
                    let nbc = bc + dc;
                    if(nbr >= 0 && nbr < n && nbc >= 0 && nbc < m && grid[nbr][nbc] != '#'){
                        queue.push([nr, nc, nbr, nbc, moves + 1]);
                    }
                }
                else{
                    queue.push([nr, nc, br, bc, moves]);
                }
            }
        }
    }
    return -1;
    
};

    