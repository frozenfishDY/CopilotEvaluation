/**https://leetcode.com/problems/minimum-white-tiles-after-covering-with-carpets/ */
//You are given a 0-indexed binary string floor, which represents the colors of tiles on a floor:
//floor[i] = '0' denotes that the ith tile of the floor is colored black.
//On the other hand, floor[i] = '1' denotes that the ith tile of the floor is colored white.
//You are also given numCarpets and carpetLen. You have numCarpets black carpets, each of length carpetLen tiles. Cover the tiles with the given carpets such that the number of white tiles still visible is minimum. Carpets may overlap one another.
//Return the minimum number of white tiles still visible.


/**
 * @param {string} floor
 * @param {number} numCarpets
 * @param {number} carpetLen
 * @return {number}
 */
var minimumWhiteTiles = function(floor, numCarpets, carpetLen) {
    let n = floor.length;
    let dp = new Array(n + 1);
    for(let i = 0; i <= n; i++){
        dp[i] = new Array(numCarpets + 1).fill(0);
    }
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= numCarpets; j++){
            dp[i][j] = dp[i - 1][j];
            if(floor[i - 1] === '1'){
                dp[i][j]++;
            }
            if(i >= carpetLen){
                dp[i][j] = Math.min(dp[i][j], dp[i - carpetLen][j - 1]);
            }
        }
    }
    return dp[n][numCarpets];
    
};

    