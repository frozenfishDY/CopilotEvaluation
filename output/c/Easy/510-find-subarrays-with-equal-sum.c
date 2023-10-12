/**https://leetcode.com/problems/find-subarrays-with-equal-sum/ */
//Given a 0-indexed integer array nums, determine whether there exist two subarrays of length 2 with equal sum. Note that the two subarrays must begin at different indices.
//Return true if these subarrays exist, and false otherwise.
//A subarray is a contiguous non-empty sequence of elements within an array.
// 
//Example 1:
//Input: nums = [4,2,4]
//Output: true
//Explanation: The subarrays with elements [4,2] and [2,4] have the same sum of 6.
//Example 2:
//Input: nums = [1,2,3,4,5]
//Output: false
//Explanation: No two subarrays of size 2 have the same sum.
//Example 3:
//Input: nums = [0,0,0]
//Output: true
//Explanation: The subarrays [nums[0],nums[1]] and [nums[1],nums[2]] have the same sum of 0. 
//Note that even though the subarrays have the same content, the two subarrays are considered different because they are in different positions in the original array.
// 
//Constraints:
//	2 <= nums.length <= 1000
//	-109 <= nums[i] <= 109
bool findSubarrays(int* nums, int numsSize){
int i = 0, j = 0, k = 0;
    int *sum = (int*)calloc(numsSize + 1, sizeof(int));
    for (; i < numsSize; i++) {
        sum[i + 1] = sum[i] + nums[i];
    }
    for (i = 0; i < numsSize - 1; i++) {
        for (j = i + 2; j < numsSize; j++) {
            if (sum[i + 1] == sum[j + 1] - sum[j]) {
                return true;
            }
        }
    }
    return false;
}