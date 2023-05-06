/**https://leetcode.com/problems/time-to-cross-a-bridge/ */
//There are k workers who want to move n boxes from an old warehouse to a new one. You are given the two integers n and k, and a 2D integer array time of size k x 4 where time[i] = [leftToRighti, pickOldi, rightToLefti, putNewi].
//The warehouses are separated by a river and connected by a bridge. The old warehouse is on the right bank of the river, and the new warehouse is on the left bank of the river. Initially, all k workers are waiting on the left side of the bridge. To move the boxes, the ith worker (0-indexed) can :
//Cross the bridge from the left bank (new warehouse) to the right bank (old warehouse) in leftToRighti minutes.
//Pick a box from the old warehouse and return to the bridge in pickOldi minutes. Different workers can pick up their boxes simultaneously.
//Cross the bridge from the right bank (old warehouse) to the left bank (new warehouse) in rightToLefti minutes.
//Put the box in the new warehouse and return to the bridge in putNewi minutes. Different workers can put their boxes simultaneously.
//A worker i is less efficient than a worker j if either condition is met:
//leftToRighti + rightToLefti > leftToRightj + rightToLeftj
//leftToRighti + rightToLefti == leftToRightj + rightToLeftj and i > j
//The following rules regulate the movement of the workers through the bridge :
//If a worker x reaches the bridge while another worker y is crossing the bridge, x waits at their side of the bridge.
//If the bridge is free, the worker waiting on the right side of the bridge gets to cross the bridge. If more than one worker is waiting on the right side, the one with the lowest efficiency crosses first.
//If the bridge is free and no worker is waiting on the right side, and at least one box remains at the old warehouse, the worker on the left side of the river gets to cross the bridge. If more than one worker is waiting on the left side, the one with the lowest efficiency crosses first.
//Return the instance of time at which the last worker reaches the left bank of the river after all n boxes have been put in the new warehouse.


class TimeToCrossABridge {
    public int findCrossingTime(int n, int k, int[][] time) {
        int[][] dp = new int[n + 1][k + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = Integer.MAX_VALUE;
            }
        }
        dp[0][0] = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                if (dp[i][j] == Integer.MAX_VALUE) {
                    continue;
                }
                for (int l = 0; l <= k; l++) {
                    if (l == j) {
                        continue;
                    }
                    int next = dp[i][j] + time[j][0] + time[j][1] + time[l][2] + time[l][3];
                    if (i + 1 <= n) {
                        next = Math.max(next, time[l][0] + time[l][1]);
                    }
                    dp[i + 1][l] = Math.min(dp[i + 1][l], next);
                }
            }
        }
        int min = Integer.MAX_VALUE;
        for (int i = 0; i <= k; i++) {
            min = Math.min(min, dp[n][i]);
        }
        return min;
        
    }
}
     
    