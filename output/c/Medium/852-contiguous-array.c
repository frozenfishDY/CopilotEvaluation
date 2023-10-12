/**https://leetcode.com/problems/contiguous-array/ */
//Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
// 
//Example 1:
//Input: nums = [0,1]
//Output: 2
//Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
//Example 2:
//Input: nums = [0,1,0]
//Output: 2
//Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
// 
//Constraints:
//	1 <= nums.length <= 105
//	nums[i] is either 0 or 1.
int findMaxLength(int* nums, int numsSize){
int res = 0;
    int* map = (int*)malloc(sizeof(int) * (2 * numsSize + 1));
    memset(map, -1, sizeof(int) * (2 * numsSize + 1));
    int count = 0;
    map[numsSize] = 0;
    for (int i = 0; i < numsSize; i++) {
        count += nums[i] == 0 ? -1 : 1;
        if (map[count + numsSize] == -1) {
            map[count + numsSize] = i + 1;
        } else {
            if (res < i - map[count + numsSize] + 1) {
                res = i - map[count + numsSize] + 1;
            }
        }
    }
    free(map);
    return res;
}