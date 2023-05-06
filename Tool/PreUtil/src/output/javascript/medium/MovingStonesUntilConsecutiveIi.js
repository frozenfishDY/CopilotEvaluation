/**https://leetcode.com/problems/moving-stones-until-consecutive-ii/ */
//There are some stones in different positions on the X-axis. You are given an integer array stones, the positions of the stones.
//Call a stone an endpoint stone if it has the smallest or largest position. In one move, you pick up an endpoint stone and move it to an unoccupied position so that it is no longer an endpoint stone.
//In particular, if the stones are at say, stones = [1,2,5], you cannot move the endpoint stone at position 5, since moving it to any position (such as 0, or 3) will still keep that stone as an endpoint stone.
//The game ends when you cannot make any more moves (i.e., the stones are in three consecutive positions).
//Return an integer array answer of length 2 where:
//answer[0] is the minimum number of moves you can play, and
//answer[1] is the maximum number of moves you can play.


/**
 * @param {number[]} stones
 * @return {number[]}
 */
var numMovesStonesII = function(stones) {
    stones.sort((a, b) => a - b);
    let n = stones.length;
    let min = Number.MAX_SAFE_INTEGER;
    let max = stones[n - 1] - stones[0] + 1 - n;
    let i = 0;
    let j = 0;
    while(i < n){
        while(j + 1 < n && stones[j + 1] - stones[i] + 1 <= n){
            j++;
        }
        let cost = n - (j - i + 1);
        if(j - i + 1 == n - 1 && stones[j] - stones[i] + 1 == n - 1){
            cost = 2;
        }
        min = Math.min(min, cost);
        i++;
    }
    return [min, max];
    
};

    