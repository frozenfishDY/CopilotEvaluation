/**https://leetcode.com/problems/valid-triangle-number/ */
//Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
// 
//Example 1:
//Input: nums = [2,2,3,4]
//Output: 3
//Explanation: Valid combinations are: 
//2,3,4 (using the first 2)
//2,3,4 (using the second 2)
//2,2,3
//Example 2:
//Input: nums = [4,2,3,4]
//Output: 4
// 
//Constraints:
//	1 <= nums.length <= 1000
//	0 <= nums[i] <= 1000
int triangleNumber(int* nums, int numsSize){
int res = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = numsSize - 1; i >= 2; i--) {
        int left = 0, right = i - 1;
        while (left < right) {
            if (nums[left] + nums[right] > nums[i]) {
                res += right - left;
                right--;
            } else {
                left++;
            }
        }
    }
    return res;
}