/**https://leetcode.com/problems/grid-illumination/ */
//There is a 2D grid of size n x n where each cell of this grid has a lamp that is initially turned off.
//You are given a 2D array of lamp positions lamps, where lamps[i] = [rowi, coli] indicates that the lamp at grid[rowi][coli] is turned on. Even if the same lamp is listed more than once, it is turned on.
//When a lamp is turned on, it illuminates its cell and all other cells in the same row, column, or diagonal.
//You are also given another 2D array queries, where queries[j] = [rowj, colj]. For the jth query, determine whether grid[rowj][colj] is illuminated or not. After answering the jth query, turn off the lamp at grid[rowj][colj] and its 8 adjacent lamps if they exist. A lamp is adjacent if its cell shares either a side or corner with grid[rowj][colj].
//Return an array of integers ans, where ans[j] should be 1 if the cell in the jth query was illuminated, or 0 if the lamp was not.


/**
 * @param {number} n
 * @param {number[][]} lamps
 * @param {number[][]} queries
 * @return {number[]}
 */
var gridIllumination = function(n, lamps, queries) {
    let ans = [];
    let row = new Map();
    let col = new Map();
    let diag1 = new Map();
    let diag2 = new Map();
    let lampSet = new Set();
    for(let i = 0; i < lamps.length; i++){
        let x = lamps[i][0];
        let y = lamps[i][1];
        row.set(x, (row.get(x) || 0) + 1);
        col.set(y, (col.get(y) || 0) + 1);
        diag1.set(x + y, (diag1.get(x + y) || 0) + 1);
        diag2.set(x - y, (diag2.get(x - y) || 0) + 1);
        lampSet.add(x + ',' + y);
    }
    for(let i = 0; i < queries.length; i++){
        let x = queries[i][0];
        let y = queries[i][1];
        if(row.get(x) || col.get(y) || diag1.get(x + y) || diag2.get(x - y)){
            ans.push(1);
        }else{
            ans.push(0);
        }
        for(let dx = -1; dx <= 1; dx++){
            for(let dy = -1; dy <= 1; dy++){
                let nx = x + dx;
                let ny = y + dy;
                if(lampSet.has(nx + ',' + ny)){
                    row.set(nx, row.get(nx) - 1);
                    col.set(ny, col.get(ny) - 1);
                    diag1.set(nx + ny, diag1.get(nx + ny) - 1);
                    diag2.set(nx - ny, diag2.get(nx - ny) - 1);
                    lampSet.delete(nx + ',' + ny);
                }
            }
        }
    }
    return ans;
    
};

    