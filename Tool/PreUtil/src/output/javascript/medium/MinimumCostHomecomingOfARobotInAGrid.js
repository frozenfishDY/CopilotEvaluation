/**https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/ */
//There is an m x n grid, where (0, 0) is the top-left cell and (m - 1, n - 1) is the bottom-right cell. You are given an integer array startPos where startPos = [startrow, startcol] indicates that initially, a robot is at the cell (startrow, startcol). You are also given an integer array homePos where homePos = [homerow, homecol] indicates that its home is at the cell (homerow, homecol).
//The robot needs to go to its home. It can move one cell in four directions: left, right, up, or down, and it can not move outside the boundary. Every move incurs some cost. You are further given two 0-indexed integer arrays: rowCosts of length m and colCosts of length n.
//If the robot moves up or down into a cell whose row is r, then this move costs rowCosts[r].
//If the robot moves left or right into a cell whose column is c, then this move costs colCosts[c].
//Return the minimum total cost for this robot to return home.


/**
 * @param {number[]} startPos
 * @param {number[]} homePos
 * @param {number[]} rowCosts
 * @param {number[]} colCosts
 * @return {number}
 */
var minCost = function(startPos, homePos, rowCosts, colCosts) {
    let m = rowCosts.length;
    let n = colCosts.length;
    let x = startPos[0];
    let y = startPos[1];
    let total = 0;
    let max = 0;
    let set = new Set(rowCosts);
    for (let i = 0; i < m; i++) {
        let diff = Math.abs(rowCosts[i] - colCosts[i]);
        total = (total + diff) % 1000000007;
        if (diff > max) {
            for (let num of set) {
                let newDiff = Math.abs(num - colCosts[i]);
                max = Math.max(max, diff - newDiff);
            }
        }
    }
    return (total - max) % 1000000007;
    
};

    