/**https://leetcode.com/problems/valid-arrangement-of-pairs/ */
//You are given a 0-indexed 2D integer array pairs where pairs[i] = [starti, endi]. An arrangement of pairs is valid if for every index i where 1 <= i < pairs.length, we have endi-1 == starti.
//Return any valid arrangement of pairs.
//Note: The inputs will be generated such that there exists a valid arrangement of pairs.


/**
 * @param {number[][]} pairs
 * @return {number[][]}
 */
var validArrangement = function(pairs) {
    let n = pairs.length;
    let adj = new Array(n);
    for(let i = 0; i < n; i++){
        adj[i] = [];
    }
    for(let i = 0; i < n; i++){
        for(let j = 0; j < n; j++){
            if(pairs[i][1] == pairs[j][0]){
                adj[i].push(j);
            }
        }
    }
    let ans = [];
    let visited = new Set();
    let dfs = (u) => {
        visited.add(u);
        for(let v of adj[u]){
            if(!visited.has(v)){
                ans.push([pairs[u][0], pairs[v][1]]);
                dfs(v);
            }
        }
    }
    dfs(0);
    return ans;
    
};

    