/**https://leetcode.com/problems/number-of-ways-to-reconstruct-a-tree/ */
//You are given an array pairs, where pairs[i] = [xi, yi], and:
//There are no duplicates.
//xi < yi
//Let ways be the number of rooted trees that satisfy the following conditions:
//The tree consists of nodes whose values appeared in pairs.
//A pair [xi, yi] exists in pairs if and only if xi is an ancestor of yi or yi is an ancestor of xi.
//Note: the tree does not have to be a binary tree.
//Two ways are considered to be different if there is at least one node that has different parents in both ways.
//Return:
//0 if ways == 0
//1 if ways == 1
//2 if ways > 1
//A rooted tree is a tree that has a single root node, and all edges are oriented to be outgoing from the root.
//An ancestor of a node is any node on the path from the root to that node (excluding the node itself). The root has no ancestors.


/**
 * @param {number[][]} pairs
 * @return {number}
 */
var checkWays = function(pairs) {
    let n = pairs.length;
    let map = new Map();
    for(let i = 0; i < n; i++){
        let x = pairs[i][0];
        let y = pairs[i][1];
        if(!map.has(x)){
            map.set(x, new Set());
        }
        if(!map.has(y)){
            map.set(y, new Set());
        }
        map.get(x).add(y);
        map.get(y).add(x);
    }
    let visited = new Set();
    let count = 0;
    for(let i = 0; i < n; i++){
        let x = pairs[i][0];
        let y = pairs[i][1];
        if(!visited.has(x)){
            dfs(x, map, visited);
            count++;
        }
        if(!visited.has(y)){
            dfs(y, map, visited);
            count++;
        }
    }
    if(count > 1){
        return 2;
    }
    let root = -1;
    for(let i = 0; i < n; i++){
        let x = pairs[i][0];
        let y = pairs[i][1];
        if(map.get(x).size == 0){
            root = x;
            break;
        }
        if(map.get(y).size == 0){
            root = y;
            break;
        }
    }
    if(root == -1){
        return 0;
    }
    let ans = 1;
    let queue = [root];
    while(queue.length > 0){
        let size = queue.length;
        let set = new Set();
        for(let i = 0; i < size; i++){
            let node = queue.shift();
            for(let child of map.get(node)){
                if(!set.has(child)){
                    set.add(child);
                    queue.push(child);
                }
            }
        }
        ans = (ans * set.size) % 1000000007;
    }
    return ans;
    
    
};

    