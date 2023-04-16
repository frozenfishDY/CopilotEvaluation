/**https://leetcode.com/problems/escape-a-large-maze/ */
//There is a 1 million by 1 million grid on an XY-plane, and the coordinates of each grid square are (x, y).
//We start at the source = [sx, sy] square and want to reach the target = [tx, ty] square. There is also an array of blocked squares, where each blocked[i] = [xi, yi] represents a blocked square with coordinates (xi, yi).
//Each move, we can walk one square north, east, south, or west if the square is not in the array of blocked squares. We are also not allowed to walk outside of the grid.
//Return true if and only if it is possible to reach the target square from the source square through a sequence of valid moves.


/**
 * @param {number[][]} blocked
 * @param {number[]} source
 * @param {number[]} target
 * @return {boolean}
 */
var isEscapePossible = function(blocked, source, target) {
    let blockedSet = new Set();
    for(let i = 0; i < blocked.length; i++){
        blockedSet.add(blocked[i][0] + ',' + blocked[i][1]);
    }
    let sourceVisited = new Set();
    let targetVisited = new Set();
    return bfs(source, target, blockedSet, sourceVisited) && bfs(target, source, blockedSet, targetVisited);
    
};

    