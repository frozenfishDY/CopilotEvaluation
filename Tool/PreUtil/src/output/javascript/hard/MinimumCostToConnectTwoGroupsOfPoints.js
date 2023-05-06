/**https://leetcode.com/problems/minimum-cost-to-connect-two-groups-of-points/ */
//You are given two groups of points where the first group has size1 points, the second group has size2 points, and size1 >= size2.
//The cost of the connection between any two points are given in an size1 x size2 matrix where cost[i][j] is the cost of connecting point i of the first group and point j of the second group. The groups are connected if each point in both groups is connected to one or more points in the opposite group. In other words, each point in the first group must be connected to at least one point in the second group, and each point in the second group must be connected to at least one point in the first group.
//Return the minimum cost it takes to connect the two groups.


/**
 * @param {number[][]} cost
 * @return {number}
 */
var connectTwoGroups = function(cost) {
    let m = cost.length;
    let n = cost[0].length;
    let dp = new Array(1 << n).fill(Infinity);
    dp[0] = 0;
    for(let i = 0; i < m; i++){
        let next = new Array(1 << n).fill(Infinity);
        for(let j = 0; j < (1 << n); j++){
            for(let k = 0; k < n; k++){
                if((j & (1 << k)) == 0){
                    next[j | (1 << k)] = Math.min(next[j | (1 << k)], dp[j] + cost[i][k]);
                }
            }
        }
        dp = next;
    }
    let res = dp[(1 << n) - 1];
    for(let i = 0; i < n; i++){
        let min = Infinity;
        for(let j = 0; j < m; j++){
            min = Math.min(min, cost[j][i]);
        }
        res += min;
    }
    return res;
    
};

    