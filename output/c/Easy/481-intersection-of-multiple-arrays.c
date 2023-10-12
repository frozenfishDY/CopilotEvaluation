/**https://leetcode.com/problems/intersection-of-multiple-arrays/ */
//Given a 2D integer array nums where nums[i] is a non-empty array of distinct positive integers, return the list of integers that are present in each array of nums sorted in ascending order.
// 
//Example 1:
//Input: nums = [[3,1,2,4,5],[1,2,3,4],[3,4,5,6]]
//Output: [3,4]
//Explanation: 
//The only integers present in each of nums[0] = [3,1,2,4,5], nums[1] = [1,2,3,4], and nums[2] = [3,4,5,6] are 3 and 4, so we return [3,4].
//Example 2:
//Input: nums = [[1,2,3],[4,5,6]]
//Output: []
//Explanation: 
//There does not exist any integer present both in nums[0] and nums[1], so we return an empty list [].
// 
//Constraints:
//	1 <= nums.length <= 1000
//	1 <= sum(nums[i].length) <= 1000
//	1 <= nums[i][j] <= 1000
//	All the values of nums[i] are unique.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int** nums, int numsSize, int* numsColSize, int* returnSize){
int *res = NULL;
    int resSize = 0;
    int *hash = (int*)calloc(1000, sizeof(int));
    int i = 0, j = 0, k = 0;
    for (; i < numsSize; i++) {
        memset(hash, 0, 1000 * sizeof(int));
        for (j = 0; j < numsColSize[i]; j++) {
            hash[nums[i][j] - 1]++;
            if (hash[nums[i][j] - 1] == numsSize) {
                int *tmp = (int*)realloc(res, sizeof(int) * (resSize + 1));
                if (NULL != tmp) {
                    res = tmp;
                    res[resSize++] = nums[i][j];
                }
            }
        }
    }
    *returnSize = resSize;
    return res;
}