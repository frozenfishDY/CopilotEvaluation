/**https://leetcode.com/problems/strange-printer-ii/ */
//There is a strange printer with the following two special requirements:
//On each turn, the printer will print a solid rectangular pattern of a single color on the grid. This will cover up the existing colors in the rectangle.
//Once the printer has used a color for the above operation, the same color cannot be used again.
//You are given a m x n matrix targetGrid, where targetGrid[row][col] is the color in the position (row, col) of the grid.
//Return true if it is possible to print the matrix targetGrid, otherwise, return false.


/**
 * @param {number[][]} targetGrid
 * @return {boolean}
 */
var isPrintable = function(targetGrid) {
    let m = targetGrid.length;
    let n = targetGrid[0].length;
    let pre = new Array(m + 1).fill(0).map(() => new Array(n + 1).fill(0));
    for(let i = 1; i <= m; i++){
        for(let j = 1; j <= n; j++){
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + targetGrid[i - 1][j - 1];
        }
    }
    let res = 0;
    for(let i = 0; i < m; i++){
        for(let j = 0; j < n; j++){
            if(targetGrid[i][j] == 0){
                continue;
            }
            let l = 0;
            let r = Math.min(i, j) + 1;
            while(l < r){
                let mid = Math.floor((l + r) / 2);
                let sum = pre[i + 1][j + 1] - pre[i + 1][j - mid] - pre[i - mid][j + 1] + pre[i - mid][j - mid];
                if(sum == 0){
                    r = mid;
                }else{
                    l = mid + 1;
                }
            }
            res = Math.max(res, l * l);
        }
    }
    return res;
    
};

    