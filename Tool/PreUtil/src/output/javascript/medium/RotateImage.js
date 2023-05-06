/**https://leetcode.com/problems/rotate-image/ */
//You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
//You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.


/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    
    let n = matrix.length;
    for(let i = 0; i < n; i++){
        for(let j = i; j < n; j++){
            swap(matrix, i, j, j, i);
        }
    }
    for(let i = 0; i < n; i++){
        reverse(matrix[i], 0, n - 1);
    }
    
    
    
};

    