/**https://leetcode.com/problems/optimal-partition-of-string/ */
//Given a string s, partition the string into one or more substrings such that the characters in each substring are unique. That is, no letter appears in a single substring more than once.
//Return the minimum number of substrings in such a partition.
//Note that each character should belong to exactly one substring in a partition.
// 
//Example 1:
//Input: s = "abacaba"
//Output: 4
//Explanation:
//Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
//It can be shown that 4 is the minimum number of substrings needed.
//Example 2:
//Input: s = "ssssss"
//Output: 6
//Explanation:
//The only valid partition is ("s","s","s","s","s","s").
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists of only English lowercase letters.
int partitionString(char * s){
int i, j;
	int *cnt = (int *)malloc(sizeof(int) * 26);
	memset(cnt, 0, sizeof(int) * 26);
	for (i = 0; i < strlen(s); ++i) {
		cnt[s[i] - 'a']++;
	}
	int max = 0;
	for (i = 0; i < 26; ++i) {
		if (cnt[i] > max) {
			max = cnt[i];
		}
	}
	if (strlen(s) - max * 2 == 0) {
		return strlen(s);
	}
	return strlen(s) - max * 2 + 1;
}