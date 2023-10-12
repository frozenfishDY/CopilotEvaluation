/**https://leetcode.com/problems/next-greater-element-iii/ */
//Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.
//Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.
// 
//Example 1:
//Input: n = 12
//Output: 21
//Example 2:
//Input: n = 21
//Output: -1
// 
//Constraints:
//	1 <= n <= 231 - 1
int nextGreaterElement(int n){
int nums[10] = { 0 };
	int i = 0, j = 0, temp = n;
	while (temp) {
		nums[i++] = temp % 10;
		temp /= 10;
	}
	for (j = 1; j < i; j++) {
		if (nums[j - 1] > nums[j]) {
			break;
		}
	}
	if (j == i) {
		return -1;
	}
	int index = 0;
	for (index = 0; index < i; index++) {
		if (nums[index] > nums[j]) {
			break;
		}
	}
	int t = nums[j];
	nums[j] = nums[index];
	nums[index] = t;
	for (int k = 0; k < j; k++, j--) {
		t = nums[k];
		nums[k] = nums[j];
		nums[j] = t;
	}
	long long res = 0;
	for (int k = i - 1; k >= 0; k--) {
		res = res * 10 + nums[k];
	}
	return res > INT_MAX ? -1 : res;
}