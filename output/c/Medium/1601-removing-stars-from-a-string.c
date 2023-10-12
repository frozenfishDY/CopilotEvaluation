/**https://leetcode.com/problems/removing-stars-from-a-string/ */
//You are given a string s, which contains stars *.
//In one operation, you can:
//	Choose a star in s.
//	Remove the closest non-star character to its left, as well as remove the star itself.
//Return the string after all stars have been removed.
//Note:
//	The input will be generated such that the operation is always possible.
//	It can be shown that the resulting string will always be unique.
// 
//Example 1:
//Input: s = "leet**cod*e"
//Output: "lecoe"
//Explanation: Performing the removals from left to right:
//- The closest character to the 1st star is 't' in "leet**cod*e". s becomes "lee*cod*e".
//- The closest character to the 2nd star is 'e' in "lee*cod*e". s becomes "lecod*e".
//- The closest character to the 3rd star is 'd' in "lecod*e". s becomes "lecoe".
//There are no more stars, so we return "lecoe".
//Example 2:
//Input: s = "erase*****"
//Output: ""
//Explanation: The entire string is removed, so we return an empty string.
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists of lowercase English letters and stars *.
//	The operation above can be performed on s.
char * removeStars(char * s){
int i, j;
	int *cnt = (int *)malloc(sizeof(int) * strlen(s));
	memset(cnt, 0, sizeof(int) * strlen(s));
	int *num = (int *)malloc(sizeof(int) * (strlen(s) + 1));
	memset(num, 0, sizeof(int) * (strlen(s) + 1));
	for (i = 0; i < strlen(s); ++i) {
		if (s[i] == '*') {
			cnt[i] = 1;
		} else {
			cnt[i] = 0;
		}
	}
	for (i = 0; i < strlen(s); ++i) {
		if (cnt[i] == 1) {
			num[i] = i + 1;
		} else {
			for (j = 0; j < strlen(s); ++j) {
				if (num[j] == 0) {
					num[j] = i + 1;
					break;
				}
			}
		}
	}
	for (i = 0; i < strlen(s) + 1; ++i) {
		printf("%d", num[i]);
	}
	printf("\n");
	return "";
}