/**https://leetcode.com/problems/count-artifacts-that-can-be-extracted/ */
//There is an n x n 0-indexed grid with some artifacts buried in it. You are given the integer n and a 0-indexed 2D integer array artifacts describing the positions of the rectangular artifacts where artifacts[i] = [r1i, c1i, r2i, c2i] denotes that the ith artifact is buried in the subgrid where:
//(r1i, c1i) is the coordinate of the top-left cell of the ith artifact and
//(r2i, c2i) is the coordinate of the bottom-right cell of the ith artifact.
//You will excavate some cells of the grid and remove all the mud from them. If the cell has a part of an artifact buried underneath, it will be uncovered. If all the parts of an artifact are uncovered, you can extract it.
//Given a 0-indexed 2D integer array dig where dig[i] = [ri, ci] indicates that you will excavate the cell (ri, ci), return the number of artifacts that you can extract.
//The test cases are generated such that:
//No two artifacts overlap.
//Each artifact only covers at most 4 cells.
//The entries of dig are unique.


/**
 * @param {number} n
 * @param {number[][]} artifacts
 * @param {number[][]} dig
 * @return {number}
 */
var digArtifacts = function(n, artifacts, dig) {
    let result = 0;
    let grid = new Array(n);
    for (let i = 0; i < n; i++) {
        grid[i] = new Array(n);
    }
    for (let i = 0; i < artifacts.length; i++) {
        let artifact = artifacts[i];
        for (let j = artifact[0]; j <= artifact[2]; j++) {
            for (let k = artifact[1]; k <= artifact[3]; k++) {
                grid[j][k] = i;
            }
        }
    }
    for (let i = 0; i < dig.length; i++) {
        let x = dig[i][0];
        let y = dig[i][1];
        if (grid[x][y] !== undefined) {
            let artifact = artifacts[grid[x][y]];
            let count = 0;
            for (let j = artifact[0]; j <= artifact[2]; j++) {
                for (let k = artifact[1]; k <= artifact[3]; k++) {
                    if (grid[j][k] !== undefined) {
                        count++;
                    }
                }
            }
            if (count === (artifact[2] - artifact[0] + 1) * (artifact[3] - artifact[1] + 1)) {
                result++;
            }
        }
    }
    return result;
    
};

    