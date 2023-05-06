/**https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/ */
//A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:
//It is ().
//It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
//It can be written as (A), where A is a valid parentheses string.
//You are given an m x n matrix of parentheses grid. A valid parentheses string path in the grid is a path satisfying all of the following conditions:
//The path starts from the upper left cell (0, 0).
//The path ends at the bottom-right cell (m - 1, n - 1).
//The path only ever moves down or right.
//The resulting parentheses string formed by the path is valid.
//Return true if there exists a valid parentheses string path in the grid. Otherwise, return false.


/**
 * @param {character[][]} grid
 * @return {boolean}
 */
var hasValidPath = function(grid) {
    let m = grid.length;
    let n = grid[0].length;
    let visited = new Array(m);
    for(let i = 0; i < m; i++){
        visited[i] = new Array(n).fill(false);
    }
    let queue = [];
    queue.push([0, 0]);
    visited[0][0] = true;
    while(queue.length > 0){
        let [x, y] = queue.shift();
        if(x == m - 1 && y == n - 1){
            return true;
        }
        if(grid[x][y] == '/'){
            if(y + 1 < n && !visited[x][y + 1] && (grid[x][y + 1] == '/' || grid[x][y + 1] == '1' || grid[x][y + 1] == '4' || grid[x][y + 1] == '6')){
                queue.push([x, y + 1]);
                visited[x][y + 1] = true;
            }
            if(x + 1 < m && !visited[x + 1][y] && (grid[x + 1][y] == '/' || grid[x + 1][y] == '2' || grid[x + 1][y] == '3' || grid[x + 1][y] == '5')){
                queue.push([x + 1, y]);
                visited[x + 1][y] = true;
            }
        }
        else if(grid[x][y] == '\\'){
            if(y - 1 >= 0 && !visited[x][y - 1] && (grid[x][y - 1] == '\\' || grid[x][y - 1] == '1' || grid[x][y - 1] == '3' || grid[x][y - 1] == '5')){
                queue.push([x, y - 1]);
                visited[x][y - 1] = true;
            }
            if(x + 1 < m && !visited[x + 1][y] && (grid[x + 1][y] == '\\' || grid[x + 1][y] == '2' || grid[x + 1][y] == '4' || grid[x + 1][y] == '6')){
                queue.push([x + 1, y]);
                visited[x + 1][y] = true;
            }
        }
        else if(grid[x][y] == '1'){
            if(y + 1 < n && !visited[x][y + 1] && (grid[x][y + 1] == '/' || grid[x][y + 1] == '1' || grid[x][y + 1] == '4' || grid[x][y + 1] == '6')){
                queue.push([x, y + 1]);
                visited[x][y + 1] = true;
            }
            if(y - 1 >= 0 && !visited[x][y - 1] && (grid[x][y - 1] == '\\' || grid[x][y - 1] == '1' || grid[x][y - 1] == '3' || grid[x][y - 1] == '5')){
                queue.push([x, y - 1]);
                visited[x][y - 1] = true;
            }
        }
    
};

    