/**https://leetcode.com/problems/maximum-number-of-ways-to-partition-an-array/ */
//You are given a 0-indexed integer array nums of length n. The number of ways to partition nums is the number of pivot indices that satisfy both conditions:
//1 <= pivot < n
//nums[0] + nums[1] + ... + nums[pivot - 1] == nums[pivot] + nums[pivot + 1] + ... + nums[n - 1]
//You are also given an integer k. You can choose to change the value of one element of nums to k, or to leave the array unchanged.
//Return the maximum possible number of ways to partition nums to satisfy both conditions after changing at most one element.


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var waysToPartition = function(nums, k) {
    let result = 0;
    let map = new Map();
    for (let i = 0; i < nums.length; i++) {
        let num = nums[i];
        if (!map.has(num)) {
            map.set(num, []);
        }
        map.get(num).push(i);
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

    