/**https://leetcode.com/problems/spiral-matrix-iii/ */
//You start at the cell (rStart, cStart) of an rows x cols grid facing east. The northwest corner is at the first row and column in the grid, and the southeast corner is at the last row and column.
//You will walk in a clockwise spiral shape to visit every position in this grid. Whenever you move outside the grid's boundary, we continue our walk outside the grid (but may return to the grid boundary later.). Eventually, we reach all rows * cols spaces of the grid.
//Return an array of coordinates representing the positions of the grid in the order you visited them.


/**
 * @param {number} rows
 * @param {number} cols
 * @param {number} rStart
 * @param {number} cStart
 * @return {number[][]}
 */
var spiralMatrixIII = function(rows, cols, rStart, cStart) {
    let result = [];
    let r = rStart;
    let c = cStart;
    let count = 0;
    let direction = 0;
    let step = 1;
    while(count < rows * cols){
        if(r >= 0 && r < rows && c >= 0 && c < cols){
            result.push([r, c]);
            count++;
        }
        if(direction == 0){
            c++;
            if(c == cStart + step){
                direction = 1;
            }
        }else if(direction == 1){
            r++;
            if(r == rStart + step){
                direction = 2;
            }
        }else if(direction == 2){
            c--;
            if(c == cStart - step){
                direction = 3;
            }
        }else if(direction == 3){
            r--;
            if(r == rStart - step){
                direction = 0;
                step++;
            }
        }
    }
    return result;
    
};

    