/**https://leetcode.com/problems/minimum-cost-of-a-path-with-special-roads/ */
//You are given an array start where start = [startX, startY] represents your initial position (startX, startY) in a 2D space. You are also given the array target where target = [targetX, targetY] represents your target position (targetX, targetY).
//The cost of going from a position (x1, y1) to any other position in the space (x2, y2) is |x2 - x1| + |y2 - y1|.
//There are also some special roads. You are given a 2D array specialRoads where specialRoads[i] = [x1i, y1i, x2i, y2i, costi] indicates that the ith special road can take you from (x1i, y1i) to (x2i, y2i) with a cost equal to costi. You can use each special road any number of times.
//Return the minimum cost required to go from (startX, startY) to (targetX, targetY).
// 
//Example 1:
//Input: start = [1,1], target = [4,5], specialRoads = [[1,2,3,3,2],[3,4,4,5,1]]
//Output: 5
//Explanation: The optimal path from (1,1) to (4,5) is the following:
//- (1,1) -> (1,2). This move has a cost of |1 - 1| + |2 - 1| = 1.
//- (1,2) -> (3,3). This move uses the first special edge, the cost is 2.
//- (3,3) -> (3,4). This move has a cost of |3 - 3| + |4 - 3| = 1.
//- (3,4) -> (4,5). This move uses the second special edge, the cost is 1.
//So the total cost is 1 + 2 + 1 + 1 = 5.
//It can be shown that we cannot achieve a smaller total cost than 5.
//Example 2:
//Input: start = [3,2], target = [5,7], specialRoads = [[3,2,3,4,4],[3,3,5,5,5],[3,4,5,6,6]]
//Output: 7
//Explanation: It is optimal to not use any special edges and go directly from the starting to the ending position with a cost |5 - 3| + |7 - 2| = 7.
// 
//Constraints:
//	start.length == target.length == 2
//	1 <= startX <= targetX <= 105
//	1 <= startY <= targetY <= 105
//	1 <= specialRoads.length <= 200
//	specialRoads[i].length == 5
//	startX <= x1i, x2i <= targetX
//	startY <= y1i, y2i <= targetY
//	1 <= costi <= 105
class Solution {
    public int minimumCost(int[] start, int[] target, int[][] specialRoads) {
        int n = specialRoads.length;
        int[][] dp = new int[1 << n][n + 2];
        for (int[] row : dp) {
            Arrays.fill(row, Integer.MAX_VALUE / 2);
        }
        int[] costs = new int[n + 2];
        for (int i = 0; i < n; i++) {
            int[] road = specialRoads[i];
            costs[i] = road[4];
            dp[1 << i][i] = Math.abs(start[0] - road[0]) + Math.abs(start[1] - road[1]);
            dp[1 << i][n + 1] = Math.abs(target[0] - road[2]) + Math.abs(target[1] - road[3]);
        }
        costs[n] = Math.abs(start[0] - target[0]) + Math.abs(start[1] - target[1]);
        costs[n + 1] = 0;
        for (int i = 1; i < 1 << n; i++) {
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) > 0) {
                    for (int k = 0; k < n + 2; k++) {
                        dp[i][k] = Math.min(dp[i][k], dp[i ^ (1 << j)][k] + Math.abs(specialRoads[j][2] - specialRoads[j][0]) + Math.abs(specialRoads[j][3] - specialRoads[j][1]));
                        if (k < n) {
                            dp[i][k] = Math.min(dp[i][k], dp[i ^ (1 << j)][k + 1] + costs[j]);
                        }
                    }
                }
            }
        }
        return dp[(1 << n) - 1][0];
    }
}