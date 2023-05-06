/**https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/ */
//You are given two integer arrays, source and target, both of length n. You are also given an array allowedSwaps where each allowedSwaps[i] = [ai, bi] indicates that you are allowed to swap the elements at index ai and index bi (0-indexed) of array source. Note that you can swap elements at a specific pair of indices multiple times and in any order.
//The Hamming distance of two arrays of the same length, source and target, is the number of positions where the elements are different. Formally, it is the number of indices i for 0 <= i <= n-1 where source[i] != target[i] (0-indexed).
//Return the minimum Hamming distance of source and target after performing any amount of swap operations on array source.


/**
 * @param {number[]} source
 * @param {number[]} target
 * @param {number[][]} allowedSwaps
 * @return {number}
 */
var minimumHammingDistance = function(source, target, allowedSwaps) {
    let n = source.length;
    let uf = new UnionFind(n);
    for (let i = 0; i < allowedSwaps.length; i++) {
        let [a, b] = allowedSwaps[i];
        uf.union(a, b);
    }
    let groups = new Map();
    for (let i = 0; i < n; i++) {
        let parent = uf.find(i);
        if (!groups.has(parent)) {
            groups.set(parent, []);
        }
        groups.get(parent).push(i);
    }
    let result = 0;
    for (let group of groups.values()) {
        let count = new Map();
        for (let i of group) {
            count.set(source[i], (count.get(source[i]) || 0) + 1);
        }
        for (let i of group) {
            if (count.get(target[i])) {
                count.set(target[i], count.get(target[i]) - 1);
            } else {
                result++;
            }
        }
    }
    return result;
    

    
};

    