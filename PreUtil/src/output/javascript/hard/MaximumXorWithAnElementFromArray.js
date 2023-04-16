/**https://leetcode.com/problems/maximum-xor-with-an-element-from-array/ */
//You are given an array nums consisting of non-negative integers. You are also given a queries array, where queries[i] = [xi, mi].
//The answer to the ith query is the maximum bitwise XOR value of xi and any element of nums that does not exceed mi. In other words, the answer is max(nums[j] XOR xi) for all j such that nums[j] <= mi. If all elements in nums are larger than mi, then the answer is -1.
//Return an integer array answer where answer.length == queries.length and answer[i] is the answer to the ith query.


/**
 * @param {number[]} nums
 * @param {number[][]} queries
 * @return {number[]}
 */
var maximizeXor = function(nums, queries) {
    let n = nums.length;
    let m = queries.length;
    let res = new Array(m).fill(-1);
    let q = new Array(m);
    for(let i = 0; i < m; i++){
        q[i] = [queries[i][0], queries[i][1], i];
    }
    q.sort((a, b) => a[1] - b[1]);
    nums.sort((a, b) => a - b);
    let trie = new Trie();
    let j = 0;
    for(let i = 0; i < m; i++){
        while(j < n && nums[j] <= q[i][1]){
            trie.insert(nums[j]);
            j++;
        }
        if(j > 0){
            res[q[i][2]] = trie.query(q[i][0]);
        }
    }
    return res;
    
    
};

    