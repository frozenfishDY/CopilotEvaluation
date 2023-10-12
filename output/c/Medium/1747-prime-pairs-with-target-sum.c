/**https://leetcode.com/problems/prime-pairs-with-target-sum/ */
//You are given an integer n. We say that two integers x and y form a prime number pair if:
//	1 <= x <= y <= n
//	x + y == n
//	x and y are prime numbers
//Return the 2D sorted list of prime number pairs [xi, yi]. The list should be sorted in increasing order of xi. If there are no prime number pairs at all, return an empty array.
//Note: A prime number is a natural number greater than 1 with only two factors, itself and 1.
// 
//Example 1:
//Input: n = 10
//Output: [[3,7],[5,5]]
//Explanation: In this example, there are two prime pairs that satisfy the criteria. 
//These pairs are [3,7] and [5,5], and we return them in the sorted order as described in the problem statement.
//Example 2:
//Input: n = 2
//Output: []
//Explanation: We can show that there is no prime number pair that gives a sum of 2, so we return an empty array. 
// 
//Constraints:
//	1 <= n <= 106
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findPrimePairs(int n, int* returnSize, int** returnColumnSizes){
int i, j;
	*returnSize = 0;
	int** result = (int**)malloc(sizeof(int*) * n);
	*returnColumnSizes = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		(*returnColumnSizes)[i] = 2;
		result[i] = (int*)malloc(sizeof(int) * 2);
	}
	int* primes = (int*)malloc(sizeof(int) * (n + 1));
	for (i = 0; i <= n; i++) {
		primes[i] = 0;
	}
	for (i = 2; i <= n; i++) {
		if (primes[i] == 0) {
			for (j = i * 2; j <= n; j += i) {
				primes[j] = 1;
			}
		}
	}
	for (i = 2; i <= n; i++) {
		if (primes[i] == 0 && primes[n - i] == 0) {
			result[*returnSize][0] = i;
			result[*returnSize][1] = n - i;
			(*returnSize)++;
		}
	}
	*returnSize = (*returnSize) / 2;
	return result;
}