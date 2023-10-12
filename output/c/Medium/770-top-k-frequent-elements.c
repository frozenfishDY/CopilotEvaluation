/**https://leetcode.com/problems/top-k-frequent-elements/ */
//Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
// 
//Example 1:
//Input: nums = [1,1,1,2,2,3], k = 2
//Output: [1,2]
//Example 2:
//Input: nums = [1], k = 1
//Output: [1]
// 
//Constraints:
//	1 <= nums.length <= 105
//	-104 <= nums[i] <= 104
//	k is in the range [1, the number of unique elements in the array].
//	It is guaranteed that the answer is unique.
// 
//Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
*returnSize = 0;
    int *res = (int *)malloc(sizeof(int) * k);
    int *freq = (int *)malloc(sizeof(int) * (numsSize + 1));
    memset(freq, 0, sizeof(int) * (numsSize + 1));
    for (int i = 0; i < numsSize; i++) {
        freq[nums[i]]++;
    }
    int max = 0;
    for (int i = 0; i < numsSize + 1; i++) {
        if (freq[i] > max) {
            max = freq[i];
        }
    }
    int **buckets = (int **)malloc(sizeof(int *) * (max + 1));
    memset(buckets, 0, sizeof(int *) * (max + 1));
    for (int i = 0; i < numsSize + 1; i++) {
        if (freq[i] > 0) {
            if (buckets[freq[i]] == NULL) {
                buckets[freq[i]] = (int *)malloc(sizeof(int) * (numsSize + 1));
                memset(buckets[freq[i]], 0, sizeof(int) * (numsSize + 1));
            }
            buckets[freq[i]][0]++;
            buckets[freq[i]][buckets[freq[i]][0]] = i;
        }
    }
    int idx = 0;
    for (int i = max; i > 0 && idx < k; i--) {
        if (buckets[i] != NULL) {
            int len = buckets[i][0];
            for (int j = 1; j <= len && idx < k; j++) {
                res[idx++] = buckets[i][j];
            }
        }
    }
    return res;
}