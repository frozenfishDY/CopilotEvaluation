/**https://leetcode.com/problems/maximum-gap/ */
//Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.
//You must write an algorithm that runs in linear time and uses linear extra space.


/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumGap = function(nums) {
    let n = nums.length;
    if(n < 2){
        return 0;
    }
    let min = Number.MAX_SAFE_INTEGER;
    let max = Number.MIN_SAFE_INTEGER;
    for(let i = 0; i < n; i++){
        min = Math.min(min, nums[i]);
        max = Math.max(max, nums[i]);
    }
    let bucketSize = Math.max(1, Math.floor((max - min) / (n - 1)));
    let bucketCount = Math.floor((max - min) / bucketSize) + 1;
    let buckets = new Array(bucketCount);
    for(let i = 0; i < bucketCount; i++){
        buckets[i] = new Bucket();
    }
    for(let i = 0; i < n; i++){
        let index = Math.floor((nums[i] - min) / bucketSize);
        buckets[index].min = Math.min(buckets[index].min, nums[i]);
        buckets[index].max = Math.max(buckets[index].max, nums[i]);
    }
    let result = 0;
    let prev = buckets[0].max;
    for(let i = 1; i < bucketCount; i++){
        if(buckets[i].min === Number.MAX_SAFE_INTEGER && buckets[i].max === Number.MIN_SAFE_INTEGER){
            continue;
        }
        result = Math.max(result, buckets[i].min - prev);
        prev = buckets[i].max;
    }
    return result;
    
    
};

    