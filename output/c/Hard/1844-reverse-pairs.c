/**https://leetcode.com/problems/reverse-pairs/ */
//Given an integer array nums, return the number of reverse pairs in the array.
//A reverse pair is a pair (i, j) where:
//	0 <= i < j < nums.length and
//	nums[i] > 2 * nums[j].
// 
//Example 1:
//Input: nums = [1,3,2,3,1]
//Output: 2
//Explanation: The reverse pairs are:
//(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
//(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
//Example 2:
//Input: nums = [2,4,3,5,1]
//Output: 3
//Explanation: The reverse pairs are:
//(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
//(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
//(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
// 
//Constraints:
//	1 <= nums.length <= 5 * 104
//	-231 <= nums[i] <= 231 - 1
int reversePairs(int* nums, int numsSize){
int res = 0;
    int *temp = (int *)malloc(sizeof(int) * numsSize);
    res = mergeSort(nums, 0, numsSize - 1, temp);
    return res;
}
int mergeSort(int *nums, int left, int right, int *temp) {
    if (left >= right) return 0;
    int mid = left + (right - left) / 2;
    int res = mergeSort(nums, left, mid, temp) + mergeSort(nums, mid + 1, right, temp);
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if ((long long)nums[i] > 2 * (long long)nums[j]) {
            res += mid - i + 1;
            j++;
        } else {
            i++;
        }
    }
    i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) temp[k++] = nums[i++];
        else temp[k++] = nums[j++];
    }
    while (i <= mid) temp[k++] = nums[i++];
    while (j <= right) temp[k++] = nums[j++];
    for (int i = 0; i < k; i++) {
        nums[left + i] = temp[i];
    }
    return res;
}