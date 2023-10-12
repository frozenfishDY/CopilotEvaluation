/**https://leetcode.com/problems/intersection-of-two-arrays/ */
//Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.
// 
//Example 1:
//Input: nums1 = [1,2,2,1], nums2 = [2,2]
//Output: [2]
//Example 2:
//Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//Output: [9,4]
//Explanation: [4,9] is also accepted.
// 
//Constraints:
//	1 <= nums1.length, nums2.length <= 1000
//	0 <= nums1[i], nums2[i] <= 1000
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int *array = (int *)malloc(nums1Size * sizeof(int));
  *returnSize = 0;
  if(nums1Size == 0 || nums2Size == 0) {
    return array;
  }
  int *hash = (int *)malloc(1000 * sizeof(int));
  memset(hash, 0, 1000 * sizeof(int));
  for(int i = 0; i < nums1Size; i++) {
    hash[nums1[i]] = 1;
  }
  for(int i = 0; i < nums2Size; i++) {
    if(hash[nums2[i]] == 1) {
      hash[nums2[i]] = 2;
    }
  }
  for(int i = 0; i < 1000; i++) {
    if(hash[i] == 2) {
      array[*returnSize] = i;
      (*returnSize)++;
    }
  }
  return array;

}