/**https://leetcode.com/problems/maximum-height-by-stacking-cuboids/ */
//Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = [widthi, lengthi, heighti] (0-indexed). Choose a subset of cuboids and place them on each other.
//You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj. You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.
//Return the maximum height of the stacked cuboids.


class MaximumHeightByStackingCuboids {
    public int maxHeight(int[][] cuboids) {
        int n = cuboids.length;
        for(int[] cuboid : cuboids){
            Arrays.sort(cuboid);
        }
        Arrays.sort(cuboids, (a, b) -> {
            if(a[0] == b[0]){
                if(a[1] == b[1]){
                    return a[2] - b[2];
                }
                return a[1] - b[1];
            }
            return a[0] - b[0];
        });
        int[] dp = new int[n];
        int res = 0;
        for(int i = 0; i < n; i++){
            dp[i] = cuboids[i][2];
            for(int j = 0; j < i; j++){
                if(cuboids[j][0] <= cuboids[i][0] && cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2]){
                    dp[i] = Math.max(dp[i], dp[j] + cuboids[i][2]);
                }
            }
            res = Math.max(res, dp[i]);
        }
        return res;
        
    }
}
     
    