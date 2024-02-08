/**https://leetcode.com/problems/minimum-cost-to-connect-two-groups-of-points/ */
//You are given two groups of points where the first group has size1 points, the second group has size2 points, and size1 >= size2.
//The cost of the connection between any two points are given in an size1 x size2 matrix where cost[i][j] is the cost of connecting point i of the first group and point j of the second group. The groups are connected if each point in both groups is connected to one or more points in the opposite group. In other words, each point in the first group must be connected to at least one point in the second group, and each point in the second group must be connected to at least one point in the first group.
//Return the minimum cost it takes to connect the two groups.


class MinimumCostToConnectTwoGroupsOfPoints {
    public int connectTwoGroups(List<List<Integer>> cost) {
        int m = cost.size();
        int n = cost.get(0).size();
        int[][] dp = new int[m + 1][1 << n];
        for(int i = 0; i <= m; i++){
            Arrays.fill(dp[i], Integer.MAX_VALUE / 2);
        }
        dp[0][0] = 0;
        for(int i = 1; i <= m; i++){
            for(int j = 0; j < (1 << n); j++){
                for(int k = 0; k < n; k++){
                    if((j & (1 << k)) == 0){
                        dp[i][j | (1 << k)] = Math.min(dp[i][j | (1 << k)], dp[i - 1][j] + cost.get(i - 1).get(k));
                    }
                }
                dp[i][j] = Math.min(dp[i][j], dp[i - 1][j]);
            }
        }
        return dp[m][(1 << n) - 1];
        
    }
}
     
    