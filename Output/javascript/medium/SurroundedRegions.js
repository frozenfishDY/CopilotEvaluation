/**https://leetcode.com/problems/surrounded-regions/ */
//Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.
//A region is captured by flipping all 'O's into 'X's in that surrounded region.


/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var solve = function(board) {
    if(board.length == 0){
        return;
    }
    let m = board.length;
    let n = board[0].length;
    let queue = [];
    for(let i = 0; i < m; i++){
        if(board[i][0] == 'O'){
            queue.push([i, 0]);
        }
        if(board[i][n - 1] == 'O'){
            queue.push([i, n - 1]);
        }
    }
    for(let i = 0; i < n; i++){
        if(board[0][i] == 'O'){
            queue.push([0, i]);
        }
        if(board[m - 1][i] == 'O'){
            queue.push([m - 1, i]);
        }
    }
    while(queue.length != 0){
        let current = queue.shift();
        let x = current[0];
        let y = current[1];
        if(board[x][y] == 'O'){
            board[x][y] = 'A';
            if(x > 0 && board[x - 1][y] == 'O'){
                queue.push([x - 1, y]);
            }
            if(x < m - 1 && board[x + 1][y] == 'O'){
                queue.push([x + 1, y]);
            }
            if(y > 0 && board[x][y - 1] == 'O'){
                queue.push([x, y - 1]);
            }
            if(y < n - 1 && board[x][y + 1] == 'O'){
                queue.push([x, y + 1]);
            }
        }
    }
    for(let i = 0; i < m; i++){
        for(let j = 0; j < n; j++){
            if(board[i][j] == 'O'){
                board[i][j] = 'X';
            }
            if(board[i][j] == 'A'){
                board[i][j] = 'O';
            }
        }
    }
    
};

    