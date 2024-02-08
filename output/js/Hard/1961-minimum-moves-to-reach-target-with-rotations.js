/**https://leetcode.com/problems/minimum-moves-to-reach-target-with-rotations/ */
//In an n*n grid, there is a snake that spans 2 cells and starts moving from the top left corner at (0, 0) and (0, 1). The grid has empty cells represented by zeros and blocked cells represented by ones. The snake wants to reach the lower right corner at (n-1, n-2) and (n-1, n-1).
//In one move the snake can:
//Move one cell to the right if there are no blocked cells there. This move keeps the horizontal/vertical position of the snake as it is.
//Move down one cell if there are no blocked cells there. This move keeps the horizontal/vertical position of the snake as it is.
//Rotate clockwise if it's in a horizontal position and the two cells under it are both empty. In that case the snake moves from (r, c) and (r, c+1) to (r, c) and (r+1, c).
//Rotate counterclockwise if it's in a vertical position and the two cells to its right are both empty. In that case the snake moves from (r, c) and (r+1, c) to (r, c) and (r, c+1).
//Return the minimum number of moves to reach the target.
//If there is no way to reach the target, return -1.


/**
 * @param {number[][]} grid
 * @return {number}
 */
var minimumMoves = function(grid) {
    let n = grid.length;
    let visited = new Set();
    let queue = [[0, 0, 0, 0, 0]];
    while(queue.length > 0){
        let [r, c, d, moves, key] = queue.shift();
        if(r == n - 1 && c == n - 2 && d == 0){
            return moves;
        }
        if(visited.has(key)){
            continue;
        }
        visited.add(key);
        if(d == 0){
            if(c + 1 < n && grid[r][c + 1] == 0){
                queue.push([r, c + 1, d, moves + 1, getKey(r, c + 1, d)]);
            }
            if(r + 1 < n && grid[r + 1][c] == 0 && grid[r + 1][c + 1] == 0){
                queue.push([r, c, 1, moves + 1, getKey(r, c, 1)]);
                queue.push([r + 1, c, 1, moves + 1, getKey(r + 1, c, 1)]);
            }
        }
        else{
            if(r + 1 < n && grid[r + 1][c] == 0){
                queue.push([r + 1, c, d, moves + 1, getKey(r + 1, c, d)]);
            }
            if(c + 1 < n && grid[r][c + 1] == 0 && grid[r + 1][c + 1] == 0){
                queue.push([r, c, 0, moves + 1, getKey(r, c, 0)]);
                queue.push([r, c + 1, 0, moves + 1, getKey(r, c + 1, 0)]);
            }
        }
    }
    return -1;
    
    
};

    