/**https://leetcode.com/problems/cyclically-rotating-a-grid/ */
//You are given an m x n integer matrix grid​​​, where m and n are both even integers, and an integer k._x000D_
//_x000D_
//The matrix is composed of several layers, which is shown in the below image, where each color is its own layer:_x000D_
//_x000D_
//_x000D_
//_x000D_
//A cyclic rotation of the matrix is done by cyclically rotating each layer in the matrix. To cyclically rotate a layer once, each element in the layer will take the place of the adjacent element in the counter-clockwise direction. An example rotation is shown below:_x000D_
//_x000D_
//Return the matrix after applying k cyclic rotations to it._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//Input: grid = [[40,10],[30,20]], k = 1_x000D_
//Output: [[10,20],[40,30]]_x000D_
//Explanation: The figures above represent the grid at every state._x000D_
//_x000D_
//_x000D_
//Example 2:_x000D_
//  _x000D_
//_x000D_
//_x000D_
//Input: grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], k = 2_x000D_
//Output: [[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]_x000D_
//Explanation: The figures above represent the grid at every state._x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	m == grid.length_x000D_
//	n == grid[i].length_x000D_
//	2 <= m, n <= 50_x000D_
//	Both m and n are even integers._x000D_
//	1 <= grid[i][j] <= 5000_x000D_
//	1 <= k <= 109_x000D_
/**_x000D_
 * @param {number[][]} 
 * @param {number} 
 * @return {number[][]}
 */
var rotateGrid = function(grid, k) {
    let m = grid.length;
    let n = grid[0].length;
    let result = new Array(m).fill(0).map(() => new Array(n).fill(0));
    let min = Math.min(m, n);
    for(let i = 0; i < min / 2; i++){
        let len = (m - i * 2) * 2 + (n - i * 2) * 2 - 4;
        let temp = new Array(len);
        let index = 0;
        for(let j = i; j < m - i - 1; j++){
            temp[index++] = grid[j][i];
        }
        for(let j = i; j < n - i - 1; j++){
            temp[index++] = grid[m - i - 1][j];
        }
        for(let j = m - i - 1; j > i; j--){
            temp[index++] = grid[j][n - i - 1];
        }
        for(let j = n - i - 1; j > i; j--){
            temp[index++] = grid[i][j];
        }
        let offset = k % len;
        index = 0;
        for(let j = i; j < m - i - 1; j++){
            result[j][i] = temp[(index + offset) % len];
            index++;
        }
        for(let j = i; j < n - i - 1; j++){
            result[m - i - 1][j] = temp[(index + offset) % len];
            index++;
        }
        for(let j = m - i - 1; j > i; j--){
            result[j][n - i - 1] = temp[(index + offset) % len];
            index++;
        }
        for(let j = n - i - 1; j > i; j--){
            result[i][j] = temp[(index + offset) % len];
            index++;
        }
    }
    return result;
};