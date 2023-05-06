/**https://leetcode.com/problems/regions-cut-by-slashes/ */
//An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '', or blank space ' '. These characters divide the square into contiguous regions.
//Given the grid grid represented as a string array, return the number of regions.
//Note that backslash characters are escaped, so a '' is represented as '\'.


/**
 * @param {string[]} grid
 * @return {number}
 */
var regionsBySlashes = function(grid) {
    let n = grid.length;
    let uf = new UnionFind(4 * n * n);
    for(let i = 0; i < n; i++){
        for(let j = 0; j < n; j++){
            let index = 4 * (i * n + j);
            if(grid[i][j] == ' '){
                uf.union(index, index + 1);
                uf.union(index, index + 2);
                uf.union(index, index + 3);
            }else if(grid[i][j] == '/'){
                uf.union(index, index + 1);
                uf.union(index + 2, index + 3);
            }else{
                uf.union(index, index + 2);
                uf.union(index + 1, index + 3);
            }
            if(i < n - 1){
                uf.union(index + 3, index + 4 * n);
            }
            if(j < n - 1){
                uf.union(index + 2, index + 4 + 1);
            }
        }
    }
    return uf.getCount();
    
    
    
};

    