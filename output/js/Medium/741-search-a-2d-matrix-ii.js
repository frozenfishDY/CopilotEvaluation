/**https://leetcode.com/problems/search-a-2d-matrix-ii/ */
//Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
//Integers in each row are sorted in ascending from left to right.
//Integers in each column are sorted in ascending from top to bottom.


/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
    let m = matrix.length;
    let n = matrix[0].length;
    let row = 0;
    let col = n - 1;
    while(row < m && col >= 0){
        if(matrix[row][col] == target){
            return true;
        }else if(matrix[row][col] < target){
            row++;
        }else{
            col--;
        }
    }
    return false;
    
};

    