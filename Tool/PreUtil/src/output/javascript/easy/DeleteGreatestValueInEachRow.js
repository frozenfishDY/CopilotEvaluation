/**https://leetcode.com/problems/delete-greatest-value-in-each-row/ */
//You are given an m x n matrix grid consisting of positive integers.
//Perform the following operation until grid becomes empty:
//Delete the element with the greatest value from each row. If multiple such elements exist, delete any of them.
//Add the maximum of deleted elements to the answer.
//Note that the number of columns decreases by one after each operation.
//Return the answer after performing the operations described above.


/**
 * @param {number[][]} grid
 * @return {number}
 */
var deleteGreatestValue = function(grid) {
    let sum = 0;
    while(grid.length > 0){
        let max = 0;
        let index = 0;
        for(let i = 0; i < grid.length; i++){
            if(grid[i][0] > max){
                max = grid[i][0];
                index = i;
            }
        }
        sum += max;
        grid.splice(index, 1);
        for(let i = 0; i < grid.length; i++){
            grid[i].splice(0, 1);
        }
    }
    return sum;
    
};

    