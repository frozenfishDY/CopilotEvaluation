/**https://leetcode.com/problems/rank-transform-of-a-matrix/ */
//Given an m x n matrix, return a new matrix answer where answer[row][col] is the rank of matrix[row][col].
//The rank is an integer that represents how large an element is compared to other elements. It is calculated using the following rules:
//The rank is an integer starting from 1.
//If two elements p and q are in the same row or column, then:
//If p < q then rank(p) < rank(q)
//If p == q then rank(p) == rank(q)
//If p > q then rank(p) > rank(q)
//The rank should be as small as possible.
//The test cases are generated so that answer is unique under the given rules.


/**
 * @param {number[][]} matrix
 * @return {number[][]}
 */
var matrixRankTransform = function(matrix) {
    let m = matrix.length;
    let n = matrix[0].length;
    let res = new Array(m).fill(0).map(() => new Array(n).fill(0));
    let row = new Array(m).fill(0);
    let col = new Array(n).fill(0);
    let map = new Map();
    for(let i = 0; i < m; i++){
        for(let j = 0; j < n; j++){
            let key = matrix[i][j];
            if(!map.has(key)){
                map.set(key, []);
            }
            map.get(key).push([i, j]);
        }
    }
    let keys = Array.from(map.keys()).sort((a, b) => a - b);
    for(let key of keys){
        let arr = map.get(key);
        let rank = 0;
        let uf = new UnionFind(m + n);
        for(let [i, j] of arr){
            uf.union(i, j + m);
            rank = Math.max(rank, Math.max(row[i], col[j]));
        }
        rank++;
        for(let [i, j] of arr){
            res[i][j] = rank;
            row[i] = rank;
            col[j] = rank;
        }
    }
    return res;
    
    
};

    