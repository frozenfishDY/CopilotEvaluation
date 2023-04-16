/**https://leetcode.com/problems/minimum-white-tiles-after-covering-with-carpets/ */
//You are given a 0-indexed binary string floor, which represents the colors of tiles on a floor:
//floor[i] = '0' denotes that the ith tile of the floor is colored black.
//On the other hand, floor[i] = '1' denotes that the ith tile of the floor is colored white.
//You are also given numCarpets and carpetLen. You have numCarpets black carpets, each of length carpetLen tiles. Cover the tiles with the given carpets such that the number of white tiles still visible is minimum. Carpets may overlap one another.
//Return the minimum number of white tiles still visible.


class MinimumWhiteTilesAfterCoveringWithCarpets {
    public int minimumWhiteTiles(String floor, int numCarpets, int carpetLen) {
        int n = floor.length();
        int[] dp = new int[n];
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (floor.charAt(i) == '1') {
                res++;
            }
            if (i >= carpetLen) {
                res -= dp[i - carpetLen];
            }
            dp[i] = res;
        }
        return dp[n - 1];
        
    }
}
     
    