/**https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/ */
//Given a m x n binary matrix mat. In one step, you can choose one cell and flip it and all the four neighbors of it if they exist (Flip is changing 1 to 0 and 0 to 1). A pair of cells are called neighbors if they share one edge.
//Return the minimum number of steps required to convert mat to a zero matrix or -1 if you cannot.
//A binary matrix is a matrix with all cells equal to 0 or 1 only.
//A zero matrix is a matrix with all cells equal to 0.


/**
 * @param {number[][]} mat
 * @return {number}
 */
var minFlips = function(mat) {
    let n = mat.length;
    let m = mat[0].length;
    let dp = new Array(n);
    for(let i = 0; i < dp.length; i++){
        dp[i] = new Array(m).fill(0);
    }
    let ans = 0;
    for(let i = 0; i < n; i++){
        for(let j = 0; j < m; j++){
            if(mat[i][j] == 1){
                ans++;
            }
        }
    }
    if(ans == 0){
        return 0;
    }
    let q = [];
    q.push(mat);
    let visited = new Set();
    visited.add(JSON.stringify(mat));
    let level = 0;
    while(q.length > 0){
        let size = q.length;
        while(size > 0){
            let curr = q.shift();
            for(let i = 0; i < n; i++){
                for(let j = 0; j < m; j++){
                    let temp = JSON.parse(JSON.stringify(curr));
                    temp[i][j] = 1 - temp[i][j];
                    if(i - 1 >= 0){
                        temp[i - 1][j] = 1 - temp[i - 1][j];
                    }
                    if(i + 1 < n){
                        temp[i + 1][j] = 1 - temp[i + 1][j];
                    }
                    if(j - 1 >= 0){
                        temp[i][j - 1] = 1 - temp[i][j - 1];
                    }
                    if(j + 1 < m){
                        temp[i][j + 1] = 1 - temp[i][j + 1];
                    }
                    if(JSON.stringify(temp) == JSON.stringify(dp)){
                        return level + 1;
                    }
                    if(!visited.has(JSON.stringify(temp))){
                        visited.add(JSON.stringify(temp));
                        q.push(temp);
                    }
                }
            }
            size--;
        }
        level++;
    }
    return -1;
    
};

    