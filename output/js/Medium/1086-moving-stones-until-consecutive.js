/**https://leetcode.com/problems/moving-stones-until-consecutive/ */
//There are three stones in different positions on the X-axis. You are given three integers a, b, and c, the positions of the stones.
//In one move, you pick up a stone at an endpoint (i.e., either the lowest or highest position stone), and move it to an unoccupied position between those endpoints. Formally, let's say the stones are currently at positions x, y, and z with x < y < z. You pick up the stone at either position x or position z, and move that stone to an integer position k, with x < k < z and k != y.
//The game ends when you cannot make any more moves (i.e., the stones are in three consecutive positions).
//Return an integer array answer of length 2 where:
//answer[0] is the minimum number of moves you can play, and
//answer[1] is the maximum number of moves you can play.


/**
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @return {number[]}
 */
var numMovesStones = function(a, b, c) {
    let arr = [a, b, c].sort((a, b) => a - b);
    let min = 0;
    if(arr[2] - arr[1] > 1){
        min++;
    }
    if(arr[1] - arr[0] > 1){
        min++;
    }
    if(min == 2){
        if(arr[2] - arr[1] == 2 || arr[1] - arr[0] == 2){
            min = 1;
        }
    }
    let max = arr[2] - arr[0] - 2;
    return [min, max];
    
};

    