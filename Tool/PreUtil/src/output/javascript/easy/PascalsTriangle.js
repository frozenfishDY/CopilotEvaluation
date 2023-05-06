/**https://leetcode.com/problems/pascals-triangle/ */
//Given an integer numRows, return the first numRows of Pascal's triangle.
//In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


/**
 * @param {number} numRows
 * @return {number[][]}
 */
var generate = function(numRows) {
    let result = [];
    for(let i = 0; i < numRows; i++){
        let row = [];
        for(let j = 0; j <= i; j++){
            if(j == 0 || j == i){
                row.push(1);
            }
            else{
                row.push(result[i - 1][j - 1] + result[i - 1][j]);
            }
        }
        result.push(row);
    }
    return result;
    
};

    