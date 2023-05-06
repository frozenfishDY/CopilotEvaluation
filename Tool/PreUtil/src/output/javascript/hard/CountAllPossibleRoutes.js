/**https://leetcode.com/problems/count-all-possible-routes/ */
//You are given an array of distinct positive integers locations where locations[i] represents the position of city i. You are also given integers start, finish and fuel representing the starting city, ending city, and the initial amount of fuel you have, respectively.
//At each step, if you are at city i, you can pick any city j such that j != i and 0 <= j < locations.length and move to city j. Moving from city i to city j reduces the amount of fuel you have by |locations[i] - locations[j]|. Please notice that |x| denotes the absolute value of x.
//Notice that fuel cannot become negative at any point in time, and that you are allowed to visit any city more than once (including start and finish).
//Return the count of all possible routes from start to finish. Since the answer may be too large, return it modulo 10^9 + 7.


/**
 * @param {number[]} locations
 * @param {number} start
 * @param {number} finish
 * @param {number} fuel
 * @return {number}
 */
var countRoutes = function(locations, start, finish, fuel) {
    let mod = 1000000007;
    let n = locations.length;
    let dp = new Array(n).fill(0).map(() => new Array(fuel + 1).fill(0));
    dp[start][0] = 1;
    let res = 0;
    for(let i = 0; i <= fuel; i++){
        for(let j = 0; j < n; j++){
            if(dp[j][i] == 0){
                continue;
            }
            for(let k = 0; k < n; k++){
                if(k == j){
                    continue;
                }
                let cost = Math.abs(locations[j] - locations[k]);
                if(i + cost <= fuel){
                    dp[k][i + cost] = (dp[k][i + cost] + dp[j][i]) % mod;
                }
            }
        }
    }
    for(let i = 0; i <= fuel; i++){
        res = (res + dp[finish][i]) % mod;
    }
    return res;
    
};

    