/**https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities/ */
//There are n cities numbered from 1 to n. You are given an array edges of size n-1, where edges[i] = [ui, vi] represents a bidirectional edge between cities ui and vi. There exists a unique path between each pair of cities. In other words, the cities form a tree.
//A subtree is a subset of cities where every city is reachable from every other city in the subset, where the path between each pair passes through only the cities from the subset. Two subtrees are different if there is a city in one subtree that is not present in the other.
//For each d from 1 to n-1, find the number of subtrees in which the maximum distance between any two cities in the subtree is equal to d.
//Return an array of size n-1 where the dth element (1-indexed) is the number of subtrees in which the maximum distance between any two cities is equal to d.
//Notice that the distance between the two cities is the number of edges in the path between them.


/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number[]}
 */
var countSubgraphsForEachDiameter = function(n, edges) {
    let g = new Array(n);
    for(let i = 0; i < n; i++){
        g[i] = new Array();
    }
    for(let [u, v] of edges){
        u--;
        v--;
        g[u].push(v);
        g[v].push(u);
    }
    let res = new Array(n-1).fill(0);
    for(let i = 1; i < (1 << n); i++){
        let cnt = 0;
        for(let j = 0; j < n; j++){
            if((i & (1 << j)) != 0){
                cnt++;
            }
        }
        if(cnt <= 1){
            continue;
        }
        let flag = true;
        let maxDis = 0;
        for(let j = 0; j < n; j++){
            if((i & (1 << j)) != 0){
                let dis = bfs(g, i, j);
                if(dis == -1){
                    flag = false;
                    break;
                }
                maxDis = Math.max(maxDis, dis);
            }
        }
        if(flag){
            res[maxDis-1]++;
        }
    }
    return res;
    
    
};

    