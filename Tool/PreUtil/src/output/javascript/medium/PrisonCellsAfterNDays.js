/**https://leetcode.com/problems/prison-cells-after-n-days/ */
//There are 8 prison cells in a row and each cell is either occupied or vacant.
//Each day, whether the cell is occupied or vacant changes according to the following rules:
//If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
//Otherwise, it becomes vacant.
//Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.
//You are given an integer array cells where cells[i] == 1 if the ith cell is occupied and cells[i] == 0 if the ith cell is vacant, and you are given an integer n.
//Return the state of the prison after n days (i.e., n such changes described above).


/**
 * @param {number[]} cells
 * @param {number} n
 * @return {number[]}
 */
var prisonAfterNDays = function(cells, n) {
    let result = new Array(8).fill(0);
    let set = new Set();
    let i = 0;
    while(i < n){
        for(let j = 1; j < 7; j++){
            if(cells[j - 1] == cells[j + 1]){
                result[j] = 1;
            }else{
                result[j] = 0;
            }
        }
        let key = result.join("");
        if(set.has(key)){
            let cycle = i - set.get(key);
            let remaining = (n - i) % cycle;
            i = i + remaining;
        }else{
            set.set(key, i);
            i++;
        }
        cells = result.slice();
    }
    return result;
    
};

    