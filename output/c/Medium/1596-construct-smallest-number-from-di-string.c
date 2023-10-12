/**https://leetcode.com/problems/construct-smallest-number-from-di-string/ */
//You are given a 0-indexed string pattern of length n consisting of the characters 'I' meaning increasing and 'D' meaning decreasing.
//A 0-indexed string num of length n + 1 is created using the following conditions:
//	num consists of the digits '1' to '9', where each digit is used at most once.
//	If pattern[i] == 'I', then num[i] < num[i + 1].
//	If pattern[i] == 'D', then num[i] > num[i + 1].
//Return the lexicographically smallest possible string num that meets the conditions.
// 
//Example 1:
//Input: pattern = "IIIDIDDD"
//Output: "123549876"
//Explanation:
//At indices 0, 1, 2, and 4 we must have that num[i] < num[i+1].
//At indices 3, 5, 6, and 7 we must have that num[i] > num[i+1].
//Some possible values of num are "245639871", "135749862", and "123849765".
//It can be proven that "123549876" is the smallest possible num that meets the conditions.
//Note that "123414321" is not possible because the digit '1' is used more than once.
//Example 2:
//Input: pattern = "DDD"
//Output: "4321"
//Explanation:
//Some possible values of num are "9876", "7321", and "8742".
//It can be proven that "4321" is the smallest possible num that meets the conditions.
// 
//Constraints:
//	1 <= pattern.length <= 8
//	pattern consists of only the letters 'I' and 'D'.
char * smallestNumber(char * pattern){
int i, j;
	int *cnt = (int *)malloc(sizeof(int) * strlen(pattern));
	memset(cnt, 0, sizeof(int) * strlen(pattern));
	int *num = (int *)malloc(sizeof(int) * (strlen(pattern) + 1));
	memset(num, 0, sizeof(int) * (strlen(pattern) + 1));
	for (i = 0; i < strlen(pattern); ++i) {
		if (pattern[i] == 'I') {
			cnt[i] = 1;
		} else {
			cnt[i] = 0;
		}
	}
	for (i = 0; i < strlen(pattern); ++i) {
		if (cnt[i] == 1) {
			num[i] = i + 1;
		} else {
			for (j = 0; j < strlen(pattern); ++j) {
				if (num[j] == 0) {
					num[j] = i + 1;
					break;
				}
			}
		}
	}
	for (i = 0; i < strlen(pattern) + 1; ++i) {
		printf("%d", num[i]);
	}
	printf("\n");
	return "";
}