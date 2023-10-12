/**https://leetcode.com/problems/rotating-the-box/ */
//You are given an m x n matrix of characters box representing a side-view of a box. Each cell of the box is one of the following:_x000D_
//_x000D_
//_x000D_
//	A stone '#'_x000D_
//	A stationary obstacle '*'_x000D_
//	Empty '.'_x000D_
//_x000D_
//_x000D_
//The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions._x000D_
//_x000D_
//It is guaranteed that each stone in box rests on an obstacle, another stone, or the bottom of the box._x000D_
//_x000D_
//Return an n x m matrix representing the box after the rotation described above._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//_x000D_
//_x000D_
//Input: box = [["#",".","#"]]_x000D_
//Output: [["."],_x000D_
//         ["#"],_x000D_
//         ["#"]]_x000D_
//_x000D_
//_x000D_
//Example 2:_x000D_
//_x000D_
//_x000D_
//_x000D_
//_x000D_
//Input: box = [["#",".","*","."],_x000D_
//              ["#","#","*","."]]_x000D_
//Output: [["#","."],_x000D_
//         ["#","#"],_x000D_
//         ["*","*"],_x000D_
//         [".","."]]_x000D_
//_x000D_
//_x000D_
//Example 3:_x000D_
//_x000D_
//_x000D_
//_x000D_
//_x000D_
//Input: box = [["#","#","*",".","*","."],_x000D_
//              ["#","#","#","*",".","."],_x000D_
//              ["#","#","#",".","#","."]]_x000D_
//Output: [[".","#","#"],_x000D_
//         [".","#","#"],_x000D_
//         ["#","#","*"],_x000D_
//         ["#","*","."],_x000D_
//         ["#",".","*"],_x000D_
//         ["#",".","."]]_x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	m == box.length_x000D_
//	n == box[i].length_x000D_
//	1 <= m, n <= 500_x000D_
//	box[i][j] is either '#', '*', or '.'._x000D_
/**
 * @param {character[][]} box
 * @return {character[][]}
 */
var rotateTheBox = function(box) {
    let m = box.length;
    let n = box[0].length;
    let res = new Array(n).fill(0).map(() => new Array(m).fill('.'));
    for (let i = 0; i < m; i++) {
        let start = 0;
        let end = 0;
        for (let j = 0; j < n; j++) {
            if (box[i][j] === '*') {
                start = j + 1;
                end = j + 1;
            } else if (box[i][j] === '#') {
                end = j + 1;
            }
        }
        for (let j = start; j < end; j++) {
            res[j][m - i - 1] = '#';
        }
    }
    return res;
};