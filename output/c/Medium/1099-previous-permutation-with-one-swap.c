/**https://leetcode.com/problems/previous-permutation-with-one-swap/ */
//Given an array of positive integers arr (not necessarily distinct), return the lexicographically largest permutation that is smaller than arr, that can be made with exactly one swap. If it cannot be done, then return the same array.
//Note that a swap exchanges the positions of two numbers arr[i] and arr[j]
// 
//Example 1:
//Input: arr = [3,2,1]
//Output: [3,1,2]
//Explanation: Swapping 2 and 1.
//Example 2:
//Input: arr = [1,1,5]
//Output: [1,1,5]
//Explanation: This is already the smallest permutation.
//Example 3:
//Input: arr = [1,9,4,6,7]
//Output: [1,7,4,6,9]
//Explanation: Swapping 9 and 7.
// 
//Constraints:
//	1 <= arr.length <= 104
//	1 <= arr[i] <= 104
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* prevPermOpt1(int* arr, int arrSize, int* returnSize){
int* res = (int*)malloc(sizeof(int) * arrSize);
    *returnSize = arrSize;
    for (int i = arrSize - 1; i >= 0; i--) {
        if (i == arrSize - 1) {
            res[i] = arr[i];
        } else {
            if (arr[i] > arr[i + 1]) {
                int max = -1, index = -1;
                for (int j = i + 1; j < arrSize; j++) {
                    if (arr[j] < arr[i] && arr[j] > max) {
                        max = arr[j];
                        index = j;
                    }
                }
                if (index != -1) {
                    res[i] = arr[index];
                    arr[index] = arr[i];
                } else {
                    res[i] = arr[i];
                }
            } else {
                res[i] = arr[i];
            }
        }
    }
    return res;
}