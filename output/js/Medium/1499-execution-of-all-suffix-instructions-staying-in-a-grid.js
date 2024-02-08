/**https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid/ */
//There is an n x n grid, with the top-left cell at (0, 0) and the bottom-right cell at (n - 1, n - 1). You are given the integer n and an integer array startPos where startPos = [startrow, startcol] indicates that a robot is initially at cell (startrow, startcol).
//You are also given a 0-indexed string s of length m where s[i] is the ith instruction for the robot: 'L' (move left), 'R' (move right), 'U' (move up), and 'D' (move down).
//The robot can begin executing from any ith instruction in s. It executes the instructions one by one towards the end of s but it stops if either of these conditions is met:
//The next instruction will move the robot off the grid.
//There are no more instructions left to execute.
//Return an array answer of length m where answer[i] is the number of instructions the robot can execute if the robot begins executing from the ith instruction in s.


/**
 * @param {number} n
 * @param {number[]} startPos
 * @param {string} s
 * @return {number[]}
 */
var executeInstructions = function(n, startPos, s) {
    let x = startPos[0];
    let y = startPos[1];
    let result = [];
    let count = 0;
    for (let i = 0; i < s.length; i++) {
        if (s[i] === 'L') {
            y--;
        } else if (s[i] === 'R') {
            y++;
        } else if (s[i] === 'U') {
            x--;
        } else {
            x++;
        }
        if (x < 0 || x >= n || y < 0 || y >= n) {
            result.push(count);
        } else {
            count++;
        }
    }
    for (let i = 0; i < result.length; i++) {
        result[i] = count;
    }
    return result;
    
};

    