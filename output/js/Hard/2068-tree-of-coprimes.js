/**https://leetcode.com/problems/tree-of-coprimes/ */
//There is a tree (i.e., a connected, undirected graph that has no cycles) consisting of n nodes numbered from 0 to n - 1 and exactly n - 1 edges. Each node has a value associated with it, and the root of the tree is node 0.
//To represent this tree, you are given an integer array nums and a 2D array edges. Each nums[i] represents the ith node's value, and each edges[j] = [uj, vj] represents an edge between nodes uj and vj in the tree.
//Two values x and y are coprime if gcd(x, y) == 1 where gcd(x, y) is the greatest common divisor of x and y.
//An ancestor of a node i is any other node on the shortest path from node i to the root. A node is not considered an ancestor of itself.
//Return an array ans of size n, where ans[i] is the closest ancestor to node i such that nums[i] and nums[ans[i]] are coprime, or -1 if there is no such ancestor.


/**
 * @param {number[]} nums
 * @param {number[][]} edges
 * @return {number[]}
 */
var getCoprimes = function(nums, edges) {
    let n = nums.length;
    let map = new Map();
    for(let i = 0; i < n; i++){
        map.set(i, new Set());
    }
    for(let i = 0; i < n - 1; i++){
        let u = edges[i][0];
        let v = edges[i][1];
        map.get(u).add(v);
        map.get(v).add(u);
    }
    let visited = new Set();
    let ans = new Array(n).fill(-1);
    dfs(0, map, visited, nums, ans);
    return ans;
    
};

    