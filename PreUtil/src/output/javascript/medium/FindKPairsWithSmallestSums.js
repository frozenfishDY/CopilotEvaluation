/**https://leetcode.com/problems/find-k-pairs-with-smallest-sums/ */
//You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
//Define a pair (u, v) which consists of one element from the first array and one element from the second array.
//Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.


/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @param {number} k
 * @return {number[][]}
 */
var kSmallestPairs = function(nums1, nums2, k) {
    let n = nums1.length;
    let m = nums2.length;
    let result = [];
    let minHeap = new MinHeap();
    for(let i = 0; i < n; i++){
        for(let j = 0; j < m; j++){
            minHeap.insert([nums1[i], nums2[j]]);
        }
    }
    while(k > 0 && minHeap.size() > 0){
        result.push(minHeap.remove());
        k--;
    }
    return result;
    
    
    
};

    