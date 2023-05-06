/**https://leetcode.com/problems/gas-station/ */
//There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].
//You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.
//Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique


class GasStation {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int n = gas.length;
        int[] dp = new int[n + 1];
        for(int i = n - 1; i >= 0; i--){
            dp[i] = dp[i + 1] + gas[i] - cost[i];
        }
        int min = Integer.MAX_VALUE;
        int res = -1;
        for(int i = 0; i < n; i++){
            if(dp[i] < min){
                min = dp[i];
                res = i;
            }
        }
        return res == n ? -1 : res;
        
        
    }
}

    