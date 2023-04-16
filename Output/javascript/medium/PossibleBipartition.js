/**https://leetcode.com/problems/possible-bipartition/ */
//We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.
//Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.


/**
 * @param {number} n
 * @param {number[][]} dislikes
 * @return {boolean}
 */
var possibleBipartition = function(n, dislikes) {
    let graph = new Array(n + 1).fill(0).map(() => []);
    for(let i = 0; i < dislikes.length; i++){
        graph[dislikes[i][0]].push(dislikes[i][1]);
        graph[dislikes[i][1]].push(dislikes[i][0]);
    }
    let colors = new Array(n + 1).fill(0);
    for(let i = 1; i <= n; i++){
        if(colors[i] == 0 && !dfs(i, 1)){
            return false;
        }
    }
    return true;
    
    function dfs(node, color){
        if(colors[node] != 0){
            return colors[node] == color;
        }
        colors[node] = color;
        for(let i = 0; i < graph[node].length; i++){
            if(!dfs(graph[node][i], -color)){
                return false;
            }
        }
        return true;
    }
    
};

    