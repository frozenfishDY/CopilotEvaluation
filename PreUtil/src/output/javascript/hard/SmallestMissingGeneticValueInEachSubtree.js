/**https://leetcode.com/problems/smallest-missing-genetic-value-in-each-subtree/ */
//There is a family tree rooted at 0 consisting of n nodes numbered 0 to n - 1. You are given a 0-indexed integer array parents, where parents[i] is the parent for node i. Since node 0 is the root, parents[0] == -1.
//There are 105 genetic values, each represented by an integer in the inclusive range [1, 105]. You are given a 0-indexed integer array nums, where nums[i] is a distinct genetic value for node i.
//Return an array ans of length n where ans[i] is the smallest genetic value that is missing from the subtree rooted at node i.
//The subtree rooted at a node x contains node x and all of its descendant nodes.


/**
 * @param {number[]} parents
 * @param {number[]} nums
 * @return {number[]}
 */
var smallestMissingValueSubtree = function(parents, nums) {
    let result = [];
    let map = new Map();
    for (let i = 0; i < parents.length; i++) {
        let parent = parents[i];
        if (!map.has(parent)) {
            map.set(parent, []);
        }
        map.get(parent).push(i);
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
            let childArray = map.get(node);
            for (let i = 0; i < childArray.length; i++) {
                let child = childArray[i];
                result[child] = result[node];
            }
        }
        stack.push(parent);
    }
    return result;
    
};

    