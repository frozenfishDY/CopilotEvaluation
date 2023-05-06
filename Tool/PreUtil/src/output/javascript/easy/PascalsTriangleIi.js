/**https://leetcode.com/problems/pascals-triangle-ii/ */
//Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
//In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


/**
 * @param {number} rowIndex
 * @return {number[]}
 */
var getRow = function(rowIndex) {
    let result = [];
    for(let i = 0; i <= rowIndex; i++){
        let row = [];
        for(let j = 0; j <= i; j++){
            if(j == 0 || j == i){
                row.push(1);
            }
            else{
                row.push(result[j - 1] + result[j]);
            }
        }
        result = row;
    }
    return result;
    
};

    