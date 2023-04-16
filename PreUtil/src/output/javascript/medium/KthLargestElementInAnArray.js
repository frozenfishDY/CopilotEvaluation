/**https://leetcode.com/problems/kth-largest-element-in-an-array/ */
//Given an integer array nums and an integer k, return the kth largest element in the array.
//Note that it is the kth largest element in the sorted order, not the kth distinct element.
//You must solve it in O(n) time complexity.


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findKthLargest = function(nums, k) {
    let left = 0;
    let right = nums.length - 1;
    while(left <= right){
        let mid = left + Math.floor((right - left) / 2);
        let pivot = nums[mid];
        let i = left;
        let j = right;
        while(i <= j){
            while(nums[i] > pivot){
                i++;
            }
            while(nums[j] < pivot){
                j--;
            }
            if(i <= j){
                let temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j--;
            }
        }
        if(left <= k - 1 && k - 1 <= j){
            right = j;
        }else if(i <= k - 1 && k - 1 <= right){
            left = i;
        }else{
            return nums[k - 1];
        }
    }
    return -1;
    
};

    