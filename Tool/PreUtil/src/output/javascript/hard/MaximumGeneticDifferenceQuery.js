/**https://leetcode.com/problems/maximum-genetic-difference-query/ */
//There is a rooted tree consisting of n nodes numbered 0 to n - 1. Each node's number denotes its unique genetic value (i.e. the genetic value of node x is x). The genetic difference between two genetic values is defined as the bitwise-XOR of their values. You are given the integer array parents, where parents[i] is the parent for node i. If node x is the root of the tree, then parents[x] == -1.
//You are also given the array queries where queries[i] = [nodei, vali]. For each query i, find the maximum genetic difference between vali and pi, where pi is the genetic value of any node that is on the path between nodei and the root (including nodei and the root). More formally, you want to maximize vali XOR pi.
//Return an array ans where ans[i] is the answer to the ith query.


/**
 * @param {number[]} parents
 * @param {number[][]} queries
 * @return {number[]}
 */
var maxGeneticDifference = function(parents, queries) {
    let result = [];
    let map = new Map();
    for (let i = 0; i < queries.length; i++) {
        let query = queries[i];
        let node = query[0];
        let val = query[1];
        if (!map.has(node)) {
            map.set(node, []);
        }
        map.get(node).push([val, i]);
    }
    let visited = new Set();
    let stack = [];
    stack.push(0);
    while (stack.length > 0) {
        let node = stack.pop();
        if (visited.has(node)) {
            continue;
        }
        visited.add(node);
        let parent = parents[node];
        if (parent != -1) {
            if (!map.has(parent)) {
                map.set(parent, []);
            }
            map.get(parent).push(...map.get(node));
        }
        if (map.has(node)) {
            let queryArray = map.get(node);
            for (let i = 0; i < queryArray.length; i++) {
                let query = queryArray[i];
                let val = query[0];
                let index = query[1];
                result[index] = val ^ node;
            }
        }
        stack.push(parent);
    }
    return result;
    
};

    