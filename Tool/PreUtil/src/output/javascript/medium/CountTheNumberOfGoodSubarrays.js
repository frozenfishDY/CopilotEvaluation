/**https://leetcode.com/problems/count-the-number-of-good-subarrays/ */
//Given an integer array nums and an integer k, return the number of good subarrays of nums.
//A subarray arr is good if it there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].
//A subarray is a contiguous non-empty sequence of elements within an array.


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var countGood = function(nums, k) {
    let n = nums.length;
    let count = 0;
    for(let i = 0; i < n; i++){
        let map = new Map();
        let odd = 0;
        for(let j = i; j < n; j++){
            if(map.has(nums[j])){
                map.set(nums[j], map.get(nums[j]) + 1);
            }else{
                map.set(nums[j], 1);
            }
            if(map.get(nums[j]) % 2 == 1){
                odd++;
            }else{
                odd--;
            }
            if(odd >= k){
                count++;
            }
        }
    }
    return count;
    
};

    