/**https://leetcode.com/problems/maximum-score-of-a-node-sequence/ */
//There is an undirected graph with n nodes, numbered from 0 to n - 1.
//You are given a 0-indexed integer array scores of length n where scores[i] denotes the score of node i. You are also given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.
//A node sequence is valid if it meets the following conditions:
//There is an edge connecting every pair of adjacent nodes in the sequence.
//No node appears more than once in the sequence.
//The score of a node sequence is defined as the sum of the scores of the nodes in the sequence.
//Return the maximum score of a valid node sequence with a length of 4. If no such sequence exists, return -1.


/**
 * @param {number[]} scores
 * @param {number[][]} edges
 * @return {number}
 */
var maximumScore = function(scores, edges) {
    let n = scores.length;
    let dp = new Array(n + 1);
    for(let i = 0; i <= n; i++){
        dp[i] = new Array(n + 1);
        for(let j = 0; j <= n; j++){
            dp[i][j] = new Array(n + 1).fill(0);
        }
    }
    let graph = new Array(n);
    for(let i = 0; i < n; i++){
        graph[i] = [];
    }
    for(let i = 0; i < edges.length; i++){
        graph[edges[i][0]].push(edges[i][1]);
        graph[edges[i][1]].push(edges[i][0]);
    }
    let ans = -1;
    for(let i = 0; i < n; i++){
        for(let j = 0; j < graph[i].length; j++){
            for(let k = 0; k < graph[i].length; k++){
                if(j == k){
                    continue;
                }
                let a = graph[i][j];
                let b = graph[i][k];
                for(let l = 0; l < graph[a].length; l++){
                    for(let m = 0; m < graph[b].length; m++){
                        if(l == m){
                            continue;
                        }
                        let c = graph[a][l];
                        let d = graph[b][m];
                        if(c == d){
                            continue;
                        }
                        dp[a][b][c] = Math.max(dp[a][b][c], dp[i][a][b] + scores[i] + scores[a] + scores[b] + scores[c]);
                        ans = Math.max(ans, dp[a][b][c]);
                    }
                }
            }
        }
    }
    return ans;
    
};

    