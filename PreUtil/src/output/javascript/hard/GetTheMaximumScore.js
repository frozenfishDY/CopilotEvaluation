/**https://leetcode.com/problems/get-the-maximum-score/ */
//You are given two sorted arrays of distinct integers nums1 and nums2.
//A valid path is defined as follows:
//Choose array nums1 or nums2 to traverse (from index-0).
//Traverse the current array from left to right.
//If you are reading any value that is present in nums1 and nums2 you are allowed to change your path to the other array. (Only one repeated value is considered in the valid path).
//The score is defined as the sum of uniques values in a valid path.
//Return the maximum score you can obtain of all possible valid paths. Since the answer may be too large, return it modulo 10^9 + 7.


/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var maxSum = function(nums1, nums2) {
    let i = 0;
    let j = 0;
    let sum1 = 0;
    let sum2 = 0;
    let res = 0;
    while(i < nums1.length && j < nums2.length){
        if(nums1[i] == nums2[j]){
            res += Math.max(sum1, sum2) + nums1[i];
            sum1 = 0;
            sum2 = 0;
            i++;
            j++;
        }
        else if(nums1[i] < nums2[j]){
            sum1 += nums1[i];
            i++;
        }
        else{
            sum2 += nums2[j];
            j++;
        }
    }
    while(i < nums1.length){
        sum1 += nums1[i];
        i++;
    }
    while(j < nums2.length){
        sum2 += nums2[j];
        j++;
    }
    res += Math.max(sum1, sum2);
    return res % (10 ** 9 + 7);
    
    
};

    