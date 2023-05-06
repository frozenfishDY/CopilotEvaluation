/**https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/ */
//On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.
//A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.
//Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.


/**
 * @param {number[][]} stones
 * @return {number}
 */
var removeStones = function(stones) {
    let n = stones.length;
    let result = 0;
    let set = new Set();
    let map = new Map();
    for(let i = 0; i < n; i++){
        let row = stones[i][0];
        let col = stones[i][1];
        if(!map.has(row)){
            map.set(row, new Set());
        }
        if(!map.has(col)){
            map.set(col, new Set());
        }
        map.get(row).add(col);
        map.get(col).add(row);
    }
    for(let i = 0; i < n; i++){
        let row = stones[i][0];
        let col = stones[i][1];
        if(!set.has(row)){
            set.add(row);
            dfs(row, map, set);
            result++;
        }
        if(!set.has(col)){
            set.add(col);
            dfs(col, map, set);
            result++;
        }
    }
    return n - result;
    
    
};

    