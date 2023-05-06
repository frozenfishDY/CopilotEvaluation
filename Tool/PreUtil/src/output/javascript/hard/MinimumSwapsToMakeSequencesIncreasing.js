/**https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/ */
//You are given two integer arrays of the same length nums1 and nums2. In one operation, you are allowed to swap nums1[i] with nums2[i].
//For example, if nums1 = [1,2,3,8], and nums2 = [5,6,7,4], you can swap the element at i = 3 to obtain nums1 = [1,2,3,4] and nums2 = [5,6,7,8].
//Return the minimum number of needed operations to make nums1 and nums2 strictly increasing. The test cases are generated so that the given input always makes it possible.
//An array arr is strictly increasing if and only if arr[0] < arr[1] < arr[2] < ... < arr[arr.length - 1].


/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var minSwap = function(nums1, nums2) {
    let n = nums1.length;
    let dp = [];
    for(let i = 0; i < n; i++){
        dp.push([]);
        for(let j = 0; j < 2; j++){
            dp[i].push(0);
        }
    }
    dp[0][0] = 0;
    dp[0][1] = 1;
    for(let i = 1; i < n; i++){
        if(nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]){
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1] + 1;
        }
        if(nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]){
            dp[i][0] = Math.min(dp[i][0], dp[i - 1][1]);
            dp[i][1] = Math.min(dp[i][1], dp[i - 1][0] + 1);
        }
    }
    return Math.min(dp[n - 1][0], dp[n - 1][1]);
    
};

    