/**https://leetcode.com/problems/number-of-music-playlists/ */
//Your music player contains n different songs. You want to listen to goal songs (not necessarily different) during your trip. To avoid boredom, you will create a playlist so that:
//Every song is played at least once.
//A song can only be played again only if k other songs have been played.
//Given n, goal, and k, return the number of possible playlists that you can create. Since the answer can be very large, return it modulo 10^9 + 7.


/**
 * @param {number} n
 * @param {number} goal
 * @param {number} k
 * @return {number}
 */
var numMusicPlaylists = function(n, goal, k) {
    let dp = [];
    for(let i = 0; i <= goal; i++){
        dp.push([]);
        for(let j = 0; j <= n; j++){
            dp[i].push(0);
        }
    }
    dp[0][0] = 1;
    for(let i = 1; i <= goal; i++){
        for(let j = 1; j <= n; j++){
            dp[i][j] = dp[i - 1][j - 1] * (n - j + 1);
            if(j > k){
                dp[i][j] += dp[i - 1][j] * (j - k);
            }
            dp[i][j] %= 1000000007;
        }
    }
    return dp[goal][n];
    
};

    