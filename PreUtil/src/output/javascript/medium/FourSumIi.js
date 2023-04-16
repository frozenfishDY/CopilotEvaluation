/**https://leetcode.com/problems/4sum-ii/ */
//Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:
//0 <= i, j, k, l < n
//nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0


/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @param {number[]} nums3
 * @param {number[]} nums4
 * @return {number}
 */
var fourSumCount = function(nums1, nums2, nums3, nums4) {
    let n = nums1.length;
    let map = new Map();
    let result = 0;
    for(let i = 0; i < n; i++){
        for(let j = 0; j < n; j++){
            let sum = nums1[i] + nums2[j];
            map.set(sum, map.has(sum) ? map.get(sum) + 1 : 1);
        }
    }
    for(let i = 0; i < n; i++){
        for(let j = 0; j < n; j++){
            let sum = -(nums3[i] + nums4[j]);
            result += map.has(sum) ? map.get(sum) : 0;
        }
    }
    return result;
    
};

    