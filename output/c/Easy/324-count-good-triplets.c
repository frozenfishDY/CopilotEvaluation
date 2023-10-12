/**https://leetcode.com/problems/count-good-triplets/ */
//Given an array of integers arr, and three integers a, b and c. You need to find the number of good triplets._x000D_
//_x000D_
//A triplet (arr[i], arr[j], arr[k]) is good if the following conditions are true:_x000D_
//_x000D_
//_x000D_
//	0 <= i < j < k < arr.length_x000D_
//	|arr[i] - arr[j]| <= a_x000D_
//	|arr[j] - arr[k]| <= b_x000D_
//	|arr[i] - arr[k]| <= c_x000D_
//_x000D_
//_x000D_
//Where |x| denotes the absolute value of x._x000D_
//_x000D_
//Return the number of good triplets._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//Input: arr = [3,0,1,1,9,7], a = 7, b = 2, c = 3_x000D_
//Output: 4_x000D_
//Explanation: There are 4 good triplets: [(3,0,1), (3,0,1), (3,1,1), (0,1,1)]._x000D_
//_x000D_
//_x000D_
//Example 2:_x000D_
//_x000D_
//_x000D_
//Input: arr = [1,1,2,2,3], a = 0, b = 0, c = 1_x000D_
//Output: 0_x000D_
//Explanation: No triplet satisfies all conditions._x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	3 <= arr.length <= 100_x000D_
//	0 <= arr[i] <= 1000_x000D_
//	0 <= a, b, c <= 1000_x000D_


int countGoodTriplets(int* arr, int arrSize, int a, int b, int c){
int i, j, k, count = 0;
	for (i = 0; i < arrSize; ++i) {
		for (j = i + 1; j < arrSize; ++j) {
			if (abs(arr[i] - arr[j]) <= a) {
				for (k = j + 1; k < arrSize; ++k) {
					if (abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
						++count;
					}
				}
			}
		}
	}
	return count;
}