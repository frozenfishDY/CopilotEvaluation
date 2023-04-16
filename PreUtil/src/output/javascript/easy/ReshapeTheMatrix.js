/**https://leetcode.com/problems/reshape-the-matrix/ */
//In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into a new one with a different size r x c keeping its original data.
//You are given an m x n matrix mat and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.
//The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.
//If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.


/**
 * @param {number[][]} mat
 * @param {number} r
 * @param {number} c
 * @return {number[][]}
 */
var matrixReshape = function(mat, r, c) {
    let m = mat.length;
    let n = mat[0].length;
    if(m*n != r*c){
        return mat;
    }
    let ans = [];
    let temp = [];
    for(let i = 0; i < m; i++){
        for(let j = 0; j < n; j++){
            temp.push(mat[i][j]);
            if(temp.length == c){
                ans.push(temp);
                temp = [];
            }
        }
    }
    return ans;
    
};

    