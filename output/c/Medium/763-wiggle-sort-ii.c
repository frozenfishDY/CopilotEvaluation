/**https://leetcode.com/problems/wiggle-sort-ii/ */
//Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
//You may assume the input array always has a valid answer.
// 
//Example 1:
//Input: nums = [1,5,1,1,6,4]
//Output: [1,6,1,5,1,4]
//Explanation: [1,4,1,5,1,6] is also accepted.
//Example 2:
//Input: nums = [1,3,2,2,3,1]
//Output: [2,3,1,3,1,2]
// 
//Constraints:
//	1 <= nums.length <= 5 * 104
//	0 <= nums[i] <= 5000
//	It is guaranteed that there will be an answer for the given input nums.
// 
//Follow Up: Can you do it in O(n) time and/or in-place with O(1) extra space?
void wiggleSort(int* nums, int numsSize){
int *tmp = (int *)malloc(sizeof(int) * numsSize);
    memcpy(tmp, nums, sizeof(int) * numsSize);
    int mid = (numsSize + 1) >> 1;
    int left = mid - 1, right = numsSize - 1;
    for (int i = 0; i < numsSize; i++) {
        if ((i & 1) == 0) {
            nums[i] = tmp[left--];
        } else {
            nums[i] = tmp[right--];
        }
    }
}