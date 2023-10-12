/**https://leetcode.com/problems/longest-repeating-character-replacement/ */
//You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
//Return the length of the longest substring containing the same letter you can get after performing the above operations.
// 
//Example 1:
//Input: s = "ABAB", k = 2
//Output: 4
//Explanation: Replace the two 'A's with two 'B's or vice versa.
//Example 2:
//Input: s = "AABABBA", k = 1
//Output: 4
//Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
//The substring "BBBB" has the longest repeating letters, which is 4.
//There may exists other ways to achive this answer too.
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists of only uppercase English letters.
//	0 <= k <= s.length
int characterReplacement(char * s, int k){
int i = 0, j = 0, k = 0, l = 0, m = 0, n = 0;
    int len = strlen(s);
    int max = 0;
    int* count = (int*)malloc(sizeof(int) * 26);
    memset(count, 0, sizeof(int) * 26);
    while (j < len) {
        count[s[j] - 'A']++;
        max = max > count[s[j] - 'A'] ? max : count[s[j] - 'A'];
        if (j - i + 1 - max > k) {
            count[s[i] - 'A']--;
            i++;
        }
        j++;
    }
    return j - i;
}