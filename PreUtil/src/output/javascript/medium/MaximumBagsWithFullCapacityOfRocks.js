/**https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/ */
//You have n bags numbered from 0 to n - 1. You are given two 0-indexed integer arrays capacity and rocks. The ith bag can hold a maximum of capacity[i] rocks and currently contains rocks[i] rocks. You are also given an integer additionalRocks, the number of additional rocks you can place in any of the bags.
//Return the maximum number of bags that could have full capacity after placing the additional rocks in some bags.


/**
 * @param {number[]} capacity
 * @param {number[]} rocks
 * @param {number} additionalRocks
 * @return {number}
 */
var maximumBags = function(capacity, rocks, additionalRocks) {
    let n = capacity.length;
    let minHeap = new MinHeap();
    for (let i = 0; i < n; i++) {
        minHeap.add(capacity[i] - rocks[i]);
    }
    while (additionalRocks > 0) {
        let min = minHeap.poll();
        if (min === 0) {
            break;
        }
        min--;
        additionalRocks--;
        minHeap.add(min);
    }
    let count = 0;
    while (minHeap.size() > 0) {
        let min = minHeap.poll();
        if (min === 0) {
            count++;
        }
    }
    return count;
    
    
};

    