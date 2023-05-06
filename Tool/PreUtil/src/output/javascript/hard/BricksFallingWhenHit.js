/**https://leetcode.com/problems/bricks-falling-when-hit/ */
//You are given an m x n binary grid, where each 1 represents a brick and 0 represents an empty space. A brick is stable if:
//It is directly connected to the top of the grid, or
//At least one other brick in its four adjacent cells is stable.
//You are also given an array hits, which is a sequence of erasures we want to apply. Each time we want to erase the brick at the location hits[i] = (rowi, coli). The brick on that location (if it exists) will disappear. Some other bricks may no longer be stable because of that erasure and will fall. Once a brick falls, it is immediately erased from the grid (i.e., it does not land on other stable bricks).
//Return an array result, where each result[i] is the number of bricks that will fall after the ith erasure is applied.
//Note that an erasure may refer to a location with no brick, and if it does, no bricks drop.


/**
 * @param {number[][]} grid
 * @param {number[][]} hits
 * @return {number[]}
 */
var hitBricks = function(grid, hits) {
    const m = grid.length;
    const n = grid[0].length;
    const uf = new UnionFind(m * n + 1);
    const hitsSet = new Set();
    const result = new Array(hits.length).fill(0);
    const directions = [[0, 1], [0, -1], [1, 0], [-1, 0]];
    let count = 0;
    
    for (let i = 0; i < hits.length; i++) {
        hitsSet.add(hits[i][0] * n + hits[i][1]);
    }
    
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1 && !hitsSet.has(i * n + j)) {
                if (i === 0) {
                    uf.union(i * n + j, m * n);
                }
                if (i > 0 && grid[i - 1][j] === 1) {
                    uf.union(i * n + j, (i - 1) * n + j);
                }
                if (j > 0 && grid[i][j - 1] === 1) {
                    uf.union(i * n + j, i * n + j - 1);
                }
            }
        }
    }
    
    for (let i = hits.length - 1; i >= 0; i--) {
        const x = hits[i][0];
        const y = hits[i][1];
        if (grid[x][y] === 0) {
            continue;
        }
        const prevCount = uf.getSize(m * n);
        if (x === 0) {
            uf.union(x * n + y, m * n);
        }
        for (let j = 0; j < 4; j++) {
            const newX = x + directions[j][0];
            const newY = y + directions[j][1];
            if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] === 1) {
                uf.union(x * n + y, newX * n + newY);
            }
        }
        const currentCount = uf.getSize(m * n);
        result[i] = Math.max( 0, currentCount - prevCount - 1);
        grid[x][y] = 1;
    }
    
    

};

    