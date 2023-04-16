/**https://leetcode.com/problems/reconstruct-itinerary/ */
//You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.
//All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.
//For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
//You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.


/**
 * @param {string[][]} tickets
 * @return {string[]}
 */
var findItinerary = function(tickets) {
    let n = tickets.length;
    let dp = [];
    for(let i = 0; i <= n; i++){
        dp.push([]);
        for(let j = 0; j <= n; j++){
            dp[i].push([]);
            for(let k = 0; k <= n; k++){
                dp[i][j].push([]);
                for(let l = 0; l <= n; l++){
                    dp[i][j][k].push(0);
                }
            }
        }
    }
    for(let i = 0; i <= n; i++){
        for(let j = 0; j <= n; j++){
            for(let k = 0; k <= n; k++){
                dp[i][j][k][0] = 0;
                dp[i][j][k][1] = -Infinity;
            }
        }
    }
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= n; j++){
            for(let k = 1; k <= n; k++){
                dp[i][j][k][0] = Math.max(dp[i - 1][j][k][0], dp[i - 1][j][k][1] + tickets[i - 1][0]);
                dp[i][j][k][1] = Math.max(dp[i - 1][j][k][1], dp[i - 1][j - 1][k][0] - tickets[i - 1][0]);
            }
        }
    }
    return dp[n][n][n][0];
    
    
};

    