/**https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/ */
//You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.
//We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.
// 
//Example 1:
//Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
//Output: [20,24]
//Explanation: 
//List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
//List 2: [0, 9, 12, 20], 20 is in range [20,24].
//List 3: [5, 18, 22, 30], 22 is in range [20,24].
//Example 2:
//Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
//Output: [1,1]
// 
//Constraints:
//	nums.length == k
//	1 <= k <= 3500
//	1 <= nums[i].length <= 50
//	-105 <= nums[i][j] <= 105
//	nums[i] is sorted in non-decreasing order.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallestRange(int** nums, int numsSize, int* numsColSize, int* returnSize){
*returnSize = 2;
    int *res = (int *)malloc(sizeof(int) * 2);
    int k = 0;
    int **temp = (int **)malloc(sizeof(int *) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        temp[i] = (int *)malloc(sizeof(int) * 2);
    }
    int max = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        temp[i][0] = nums[i][0];
        temp[i][1] = 0;
        max = fmax(max, nums[i][0]);
    }
    int min = INT_MAX;
    while (1) {
        min = INT_MAX;
        int minIndex = 0;
        int max = INT_MIN;
        for (int i = 0; i < numsSize; i++) {
            if (temp[i][0] < min) {
                min = temp[i][0];
                minIndex = i;
            }
            max = fmax(max, temp[i][0]);
        }
        if (max - min < res[1] - res[0]) {
            res[0] = min;
            res[1] = max;
        }
        temp[minIndex][1]++;
        if (temp[minIndex][1] == numsColSize[minIndex]) {
            break;
        }
        temp[minIndex][0] = nums[minIndex][temp[minIndex][1]];
    }
    return res;
}