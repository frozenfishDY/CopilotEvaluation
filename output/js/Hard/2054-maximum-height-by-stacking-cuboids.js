/**https://leetcode.com/problems/maximum-height-by-stacking-cuboids/ */
//Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = [widthi, lengthi, heighti] (0-indexed). Choose a subset of cuboids and place them on each other.
//You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj. You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.
//Return the maximum height of the stacked cuboids.


/**
 * @param {number[][]} cuboids
 * @return {number}
 */
var maxHeight = function(cuboids) {
    let n = cuboids.length;
    for(let i = 0; i < n; i++){
        cuboids[i].sort((a, b) => a - b);
    }
    cuboids.sort((a, b) => a[0] - b[0]);
    let dp = new Array(n).fill(0);
    for(let i = 0; i < n; i++){
        dp[i] = cuboids[i][2];
    }
    let res = 0;
    for(let i = 0; i < n; i++){
        for(let j = 0; j < i; j++){
            if(cuboids[i][0] >= cuboids[j][0] && cuboids[i][1] >= cuboids[j][1] && cuboids[i][2] >= cuboids[j][2]){
                dp[i] = Math.max(dp[i], dp[j] + cuboids[i][2]);
            }
        }
        res = Math.max(res, dp[i]);
    }
    return res;
    
};

    