/**https://leetcode.com/problems/longest-path-with-different-adjacent-characters/ */
//You are given a tree (i.e. a connected, undirected graph that has no cycles) rooted at node 0 consisting of n nodes numbered from 0 to n - 1. The tree is represented by a 0-indexed array parent of size n, where parent[i] is the parent of node i. Since node 0 is the root, parent[0] == -1.
//You are also given a string s of length n, where s[i] is the character assigned to node i.
//Return the length of the longest path in the tree such that no pair of adjacent nodes on the path have the same character assigned to them.


/**
 * @param {number[]} parent
 * @param {string} s
 * @return {number}
 */
var longestPath = function(parent, s) {
    let n = parent.length;
    let graph = new Array(n);
    for(let i = 0; i < n; i++){
        graph[i] = [];
    }
    for(let i = 1; i < n; i++){
        graph[parent[i]].push(i);
    }
    let ans = 0;
    let dp = new Array(n);
    for(let i = 0; i < n; i++){
        dp[i] = new Array(26).fill(0);
    }
    for(let i = n - 1; i >= 0; i--){
        let ch = s.charCodeAt(i) - 97;
        dp[i][ch] = 1;
        for(let j = 0; j < graph[i].length; j++){
            let child = graph[i][j];
            for(let k = 0; k < 26; k++){
                if(k == ch){
                    continue;
                }
                dp[i][ch] = Math.max(dp[i][ch], 1 + dp[child][k]);
            }
        }
        ans = Math.max(ans, dp[i][ch]);
    }
    return ans;
    
};

    