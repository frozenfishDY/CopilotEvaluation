/**https://leetcode.com/problems/find-the-divisibility-array-of-a-string/ */
//You are given a 0-indexed string word of length n consisting of digits, and a positive integer m.
//The divisibility array div of word is an integer array of length n such that:
//	div[i] = 1 if the numeric value of word[0,...,i] is divisible by m, or
//	div[i] = 0 otherwise.
//Return the divisibility array of word.
// 
//Example 1:
//Input: word = "998244353", m = 3
//Output: [1,1,0,0,0,1,1,0,0]
//Explanation: There are only 4 prefixes that are divisible by 3: "9", "99", "998244", and "9982443".
//Example 2:
//Input: word = "1010", m = 10
//Output: [0,1,0,1]
//Explanation: There are only 2 prefixes that are divisible by 10: "10", and "1010".
// 
//Constraints:
//	1 <= n <= 105
//	word.length == n
//	word consists of digits from 0 to 9
//	1 <= m <= 109
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* divisibilityArray(char * word, int m, int* returnSize){
int i, j;
	*returnSize = strlen(word);
	int* result = (int*)malloc(sizeof(int) * strlen(word));
	for (i = 0; i < strlen(word); i++) {
		result[i] = 0;
	}
	int* dp = (int*)malloc(sizeof(int) * (strlen(word) + 1));
	dp[0] = 0;
	for (i = 0; i < strlen(word); i++) {
		dp[i + 1] = (dp[i] * 10 + (word[i] - '0')) % m;
	}
	for (i = 0; i < strlen(word); i++) {
		if (dp[i + 1] == 0) {
			result[i] = 1;
		}
	}
	return result;
}