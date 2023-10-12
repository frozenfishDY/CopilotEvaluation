/**https://leetcode.com/problems/left-and-right-sum-differences/ */
//Given a 0-indexed integer array nums, find a 0-indexed integer array answer where:
//    answer.length == nums.length.
//    answer[i] = |leftSum[i] - rightSum[i]|.
//Where:
//    leftSum[i] is the sum of elements to the left of the index i in the array nums. If there is no such element, leftSum[i] = 0.
//    rightSum[i] is the sum of elements to the right of the index i in the array nums. If there is no such element, rightSum[i] = 0.
//Return the array answer.
// 
//Example 1:
//Input: nums = [10,4,8,3]
//Output: [15,1,11,22]
//Explanation: The array leftSum is [0,10,14,22] and the array rightSum is [15,11,3,0].
//The array answer is [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22].
//Example 2:
//Input: nums = [1]
//Output: [0]
//Explanation: The array leftSum is [0] and the array rightSum is [0].
//The array answer is [|0 - 0|] = [0].
// 
//Constraints:
//	1 <= nums.length <= 1000
//	1 <= nums[i] <= 105
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* leftRightDifference(int* nums, int numsSize, int* returnSize){
int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int n = 0;
    int *a = (int*)malloc(sizeof(int) * numsSize);
    memset(a, 0, sizeof(int) * numsSize);
    int *b = (int*)malloc(sizeof(int) * numsSize);
    memset(b, 0, sizeof(int) * numsSize);
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < i; j++) {
            a[i] += nums[j];
        }
    }
    for (i = 0; i < numsSize; i++) {
        for (j = i + 1; j < numsSize; j++) {
            b[i] += nums[j];
        }
    }
    for (i = 0; i < numsSize; i++) {
        a[i] = abs(a[i] - b[i]);
    }
    *returnSize = numsSize;
    return a;
}