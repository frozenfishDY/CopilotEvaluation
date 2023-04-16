/**https://leetcode.com/problems/count-ways-to-build-rooms-in-an-ant-colony/ */
//You are an ant tasked with adding n new rooms numbered 0 to n-1 to your colony. You are given the expansion plan as a 0-indexed integer array of length n, prevRoom, where prevRoom[i] indicates that you must build room prevRoom[i] before building room i, and these two rooms must be connected directly. Room 0 is already built, so prevRoom[0] = -1. The expansion plan is given such that once all the rooms are built, every room will be reachable from room 0.
//You can only build one room at a time, and you can travel freely between rooms you have already built only if they are connected. You can choose to build any room as long as its previous room is already built.
//Return the number of different orders you can build all the rooms in. Since the answer may be large, return it modulo 10^9 + 7.


/**
 * @param {number[]} prevRoom
 * @return {number}
 */
var waysToBuildRooms = function(prevRoom) {
    let mod = 1000000007;
    let n = prevRoom.length;
    let dp = new Array(n + 1).fill(0);
    let child = new Array(n + 1).fill(0);
    let count = new Array(n + 1).fill(0);
    let sum = new Array(n + 1).fill(0);
    for(let i = 1; i < n; i++){
        child[prevRoom[i]]++;
    }
    for(let i = n - 1; i >= 0; i--){
        count[i] = count[i + 1] + child[i];
    }
    dp[0] = 1;
    for(let i = 1; i < n; i++){
        let c = 1;
        for(let j = 0; j < child[i]; j++){
            c = c * (count[i + 1] - j) % mod;
        }
        dp[i] = dp[prevRoom[i]] * c % mod;
        sum[i] = (sum[i - 1] + dp[i]) % mod;
    }
    return sum[n - 1];
    
};

    