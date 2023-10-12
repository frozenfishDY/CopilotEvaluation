/**https://leetcode.com/problems/two-out-of-three/ */
//Given three integer arrays nums1, nums2, and nums3, return a distinct array containing all the values that are present in at least two out of the three arrays. You may return the values in any order.
// 
//Example 1:
//Input: nums1 = [1,1,3,2], nums2 = [2,3], nums3 = [3]
//Output: [3,2]
//Explanation: The values that are present in at least two arrays are:
//- 3, in all three arrays.
//- 2, in nums1 and nums2.
//Example 2:
//Input: nums1 = [3,1], nums2 = [2,3], nums3 = [1,2]
//Output: [2,3,1]
//Explanation: The values that are present in at least two arrays are:
//- 2, in nums2 and nums3.
//- 3, in nums1 and nums2.
//- 1, in nums1 and nums3.
//Example 3:
//Input: nums1 = [1,2,2], nums2 = [4,3,3], nums3 = [5]
//Output: []
//Explanation: No value is present in at least two arrays.
// 
//Constraints:
//	1 <= nums1.length, nums2.length, nums3.length <= 100
//	1 <= nums1[i], nums2[j], nums3[k] <= 100
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoOutOfThree(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* returnSize){
int* hash = (int*)calloc(101, sizeof(int));
    for (int i = 0; i < nums1Size; i++)
    {
        hash[nums1[i]] |= 1;
    }
    for (int i = 0; i < nums2Size; i++)
    {
        hash[nums2[i]] |= 2;
    }
    for (int i = 0; i < nums3Size; i++)
    {
        hash[nums3[i]] |= 4;
    }
    int* result = (int*)malloc(sizeof(int) * 101);
    *returnSize = 0;
    for (int i = 0; i <= 100; i++)
    {
        if (hash[i] == 1 || hash[i] == 2 || hash[i] == 4 || hash[i] == 3 || hash[i] == 5 || hash[i] == 6)
        {
            result[(*returnSize)++] = i;
        }
    }
    return result;
}