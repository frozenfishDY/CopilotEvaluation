/**https://leetcode.com/problems/sort-the-matrix-diagonally/ */
//A matrix diagonal is a diagonal line of cells starting from some cell in either the topmost row or leftmost column and going in the bottom-right direction until reaching the matrix's end. For example, the matrix diagonal starting from mat[2][0], where mat is a 6 x 3 matrix, includes cells mat[2][0], mat[3][1], and mat[4][2].
//Given an m x n matrix mat of integers, sort each matrix diagonal in ascending order and return the resulting matrix.


/**
 * @param {number[][]} mat
 * @return {number[][]}
 */
var diagonalSort = function(mat) {
    let n = mat.length;
    let m = mat[0].length;
    let result = new Array(n);
    for(let i = 0; i < n; i++){
        result[i] = new Array(m).fill(0);
    }
    for(let i = 0; i < n; i++){
        let x = i;
        let y = 0;
        let temp = [];
        while(x < n && y < m){
            temp.push(mat[x][y]);
            x++;
            y++;
        }
        temp.sort((a, b) => a - b);
        x = i;
        y = 0;
        while(x < n && y < m){
            result[x][y] = temp.shift();
            x++;
            y++;
        }
    }
    for(let i = 1; i < m; i++){
        let x = 0;
        let y = i;
        let temp = [];
        while(x < n && y < m){
            temp.push(mat[x][y]);
            x++;
            y++;
        }
        temp.sort((a, b) => a - b);
        x = 0;
        y = i;
        while(x < n && y < m){
            result[x][y] = temp.shift();
            x++;
            y++;
        }
    }
    return result;
    
};

    