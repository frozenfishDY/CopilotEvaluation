/**https://leetcode.com/problems/snakes-and-ladders/ */
//You are given an n x n integer matrix board where the cells are labeled from 1 to n2 in a Boustrophedon style starting from the bottom left of the board (i.e. board[n - 1][0]) and alternating direction each row.
//You start on square 1 of the board. In each move, starting from square curr, do the following:
//Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n2)].
//This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 6 destinations, regardless of the size of the board.
//If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.
//The game ends when you reach the square n2.
//A board square on row r and column c has a snake or ladder if board[r][c] != -1. The destination of that snake or ladder is board[r][c]. Squares 1 and n2 do not have a snake or ladder.
//Note that you only take a snake or ladder at most once per move. If the destination to a snake or ladder is the start of another snake or ladder, you do not follow the subsequent snake or ladder.
//For example, suppose the board is [[-1,4],[-1,3]], and on the first move, your destination square is 2. You follow the ladder to square 3, but do not follow the subsequent ladder to 4.
//Return the least number of moves required to reach the square n2. If it is not possible to reach the square, return -1.


/**
 * @param {number[][]} board
 * @return {number}
 */
var snakesAndLadders = function(board) {
    let n = board.length;
    let map = {};
    let result = 0;
    let j = 1;
    for(let i = n - 1; i >= 0; i--){
        if(j % 2 == 0){
            for(let k = n - 1; k >= 0; k--){
                map[j] = board[i][k];
                j++;
            }
        }else{
            for(let k = 0; k < n; k++){
                map[j] = board[i][k];
                j++;
            }
        }
    }
    let queue = [1];
    let visited = {};
    while(queue.length > 0){
        let size = queue.length;
        for(let i = 0; i < size; i++){
            let curr = queue.shift();
            if(curr == n * n){
                return result;
            }
            for(let j = 1; j <= 6; j++){
                let next = curr + j;
                if(next > n * n){
                    break;
                }
                if(map[next] != -1){
                    next = map[next];
                }
                if(visited[next]){
                    continue;
                }
                visited[next] = true;
                queue.push(next);
            }
        }
        result++;
    }
    return -1;
    
};

    