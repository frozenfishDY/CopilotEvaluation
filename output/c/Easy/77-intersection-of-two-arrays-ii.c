/**https://leetcode.com/problems/intersection-of-two-arrays-ii/ */
//Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.
// 
//Example 1:
//Input: nums1 = [1,2,2,1], nums2 = [2,2]
//Output: [2,2]
//Example 2:
//Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//Output: [4,9]
//Explanation: [9,4] is also accepted.
// 
//Constraints:
//	1 <= nums1.length, nums2.length <= 1000
//	0 <= nums1[i], nums2[i] <= 1000
// 
//Follow up:
//	What if the given array is already sorted? How would you optimize your algorithm?
//	What if nums1's size is small compared to nums2's size? Which algorithm is better?
//	What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
  int *array = (int *)malloc(nums1Size * sizeof(int));
  *returnSize = 0;
  if(nums1Size == 0 || nums2Size == 0) {
    return array;
  }
  int *hash = (int *)malloc(1000 * sizeof(int));
  memset(hash, 0, 1000 * sizeof(int));
  for(int i = 0; i < nums1Size; i++) {
    hash[nums1[i]]++;
  }
  for(int i = 0; i < nums2Size; i++) {
    if(hash[nums2[i]] > 0) {
      hash[nums2[i]]--;
      array[*returnSize] = nums2[i];
      (*returnSize)++;
    }
  }
  return array;
   

}