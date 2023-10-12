/**https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/ */
//Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.
// 
//Example 1:
//Input: s = "bcabc"
//Output: "abc"
//Example 2:
//Input: s = "cbacdcbc"
//Output: "acdb"
// 
//Constraints:
//	1 <= s.length <= 1000
//	s consists of lowercase English letters.
// 
//Note: This question is the same as 316: https://leetcode.com/problems/remove-duplicate-letters/
char * smallestSubsequence(char * s){
int length = strlen(s);
    int count[26] = {0};
    int used[26] = {0};
    for (int i = 0; i < length; i++) {
        count[s[i] - 'a']++;
    }
    char* result = (char*)malloc(sizeof(char) * 27);
    result[26] = '\0';
    int index = 0;
    for (int i = 0; i < length; i++) {
        int ch = s[i] - 'a';
        count[ch]--;
        if (used[ch]) {
            continue;
        }
        while (index > 0 && result[index - 1] > s[i] && count[result[index - 1] - 'a'] > 0) {
            used[result[--index] - 'a'] = 0;
        }
        result[index++] = s[i];
        used[ch] = 1;
    }
    result[index] = '\0';
    return result;
}