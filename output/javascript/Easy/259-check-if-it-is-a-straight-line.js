/**https://leetcode.com/problems/check-if-it-is-a-straight-line/ */
//You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.
// 
// 
//Example 1:
//Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
//Output: true
//Example 2:
//Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
//Output: false
// 
//Constraints:
//	2 <= coordinates.length <= 1000
//	coordinates[i].length == 2
//	-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
//	coordinates contains no duplicate point.
/**
 * @param {number[][]} coordinates
 * @return {boolean}
 */
var checkStraightLine = function(coordinates) {
    let x0 = coordinates[0][0];
    let y0 = coordinates[0][1];
    let x1 = coordinates[1][0];
    let y1 = coordinates[1][1];
    let dx = x1 - x0;
    let dy = y1 - y0;
    for (let i = 2; i < coordinates.length; i++) {
        let x = coordinates[i][0];
        let y = coordinates[i][1];
        if (dx * (y - y1) !== dy * (x - x1)) {
            return false;
        }
    }
    return true;
};