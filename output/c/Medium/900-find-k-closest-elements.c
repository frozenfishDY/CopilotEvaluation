/**https://leetcode.com/problems/find-k-closest-elements/ */
//Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.
//An integer a is closer to x than an integer b if:
//	|a - x| < |b - x|, or
//	|a - x| == |b - x| and a < b
// 
//Example 1:
//Input: arr = [1,2,3,4,5], k = 4, x = 3
//Output: [1,2,3,4]
//Example 2:
//Input: arr = [1,2,3,4,5], k = 4, x = -1
//Output: [1,2,3,4]
// 
//Constraints:
//	1 <= k <= arr.length
//	1 <= arr.length <= 104
//	arr is sorted in ascending order.
//	-104 <= arr[i], x <= 104
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize){
int* res = (int*)malloc(sizeof(int) * k);
	*returnSize = 0;
	if (arrSize == 0) return res;
	int left = 0, right = arrSize - k;
	while (left < right) {
		int mid = (left + right) / 2;
		if (x - arr[mid] > arr[mid + k] - x) {
			left = mid + 1;
		} else {
			right = mid;
		}
	}
	for (int i = left; i < left + k; i++) {
		res[(*returnSize)++] = arr[i];
	}
	return res;
}