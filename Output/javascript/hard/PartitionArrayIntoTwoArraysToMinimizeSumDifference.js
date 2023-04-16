/**https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/ */
//You are given an integer array nums of 2 * n integers. You need to partition nums into two arrays of length n to minimize the absolute difference of the sums of the arrays. To partition nums, put each element of nums into one of the two arrays.
//Return the minimum possible absolute difference.


/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumDifference = function(nums) {
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

    