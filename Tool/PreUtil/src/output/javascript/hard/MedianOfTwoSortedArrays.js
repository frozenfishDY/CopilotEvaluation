/**https://leetcode.com/problems/median-of-two-sorted-arrays/ */
//Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
//The overall run time complexity should be O(log (m+n)).


/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    let arr = [...nums1, ...nums2];
    arr.sort((a,b) => a - b);
    let len = arr.length;
    if(len % 2 == 0){
        return (arr[len/2] + arr[len/2 - 1])/2;
    }else{
        return arr[Math.floor(len/2)];
    }
    
};

    