/**https://leetcode.com/problems/number-of-music-playlists/ */
//Your music player contains n different songs. You want to listen to goal songs (not necessarily different) during your trip. To avoid boredom, you will create a playlist so that:
//Every song is played at least once.
//A song can only be played again only if k other songs have been played.
//Given n, goal, and k, return the number of possible playlists that you can create. Since the answer can be very large, return it modulo 10^9 + 7.


class NumberOfMusicPlaylists {
    public int numMusicPlaylists(int n, int goal, int k) {
        int mod = 1000000007;
        long[][] dp = new long[goal + 1][n + 1];
        dp[0][0] = 1;
        for (int i = 1; i <= goal; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = dp[i - 1][j - 1] * (n - j + 1) + dp[i - 1][j] * Math.max(j - k, 0);
                dp[i][j] %= mod;
            }
        }
        return (int) dp[goal][n];
        
    }
}
     
    