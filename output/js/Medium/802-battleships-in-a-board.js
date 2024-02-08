/**https://leetcode.com/problems/battleships-in-a-board/ */
//Given an m x n matrix board where each cell is a battleship 'X' or empty '.', return the number of the battleships on board.
//Battleships can only be placed horizontally or vertically on board. In other words, they can only be made of the shape 1 x k (1 row, k columns) or k x 1 (k rows, 1 column), where k can be of any size. At least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships).
// 
//Example 1:
//Input: board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
//Output: 2
//Example 2:
//Input: board = [["."]]
//Output: 0
// 
//Constraints:
//	m == board.length
//	n == board[i].length
//	1 <= m, n <= 200
//	board[i][j] is either '.' or 'X'.
// 
//Follow up: Could you do it in one-pass, using only O(1) extra memory and without modifying the values board?
/**
 * @param {character[][]} board
 * @return {number}
 */
var countBattleships = function(board) {
    let count = 0;
    for (let i = 0; i < board.length; i++) {
        let row = board[i];
        for (let j = 0; j < row.length; j++) {
            let cell = row[j];
            if (cell === 'X') {
                if (i === 0 && j === 0) {
                    count++;
                } else if (i === 0) {
                    if (row[j - 1] !== 'X') {
                        count++;
                    }
                } else if (j === 0) {
                    if (board[i - 1][j] !== 'X') {
                        count++;
                    }
                } else {
                    if (row[j - 1] !== 'X' && board[i - 1][j] !== 'X') {
                        count++;
                    }
                }
            }
        }
    }
    return count;
};