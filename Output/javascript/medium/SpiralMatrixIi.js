/**https://leetcode.com/problems/spiral-matrix-ii/ */
//Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.


/**
 * @param {number} n
 * @return {number[][]}
 */
var generateMatrix = function(n) {
    let result = [];
    for(let i = 0; i < n; i++){
        result.push(new Array(n));
    }
    let top = 0;
    let bottom = n - 1;
    let left = 0;
    let right = n - 1;
    let num = 1;
    while(top <= bottom && left <= right){
        for(let i = left; i <= right; i++){
            result[top][i] = num;
            num++;
        }
        top++;
        for(let i = top; i <= bottom; i++){
            result[i][right] = num;
            num++;
        }
        right--;
        if(top <= bottom){
            for(let i = right; i >= left; i--){
                result[bottom][i] = num;
                num++;
            }
            bottom--;
        }
        if(left <= right){
            for(let i = bottom; i >= top; i--){
                result[i][left] = num;
                num++;
            }
            left++;
        }
    }
    return result;
    
};

    