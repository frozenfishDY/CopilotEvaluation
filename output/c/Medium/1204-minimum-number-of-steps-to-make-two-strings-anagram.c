/**https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/ */
//You are given two strings of the same length s and t. In one step you can choose any character of t and replace it with another character.
//Return the minimum number of steps to make t an anagram of s.
//An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.
// 
//Example 1:
//Input: s = "bab", t = "aba"
//Output: 1
//Explanation: Replace the first 'a' in t with b, t = "bba" which is anagram of s.
//Example 2:
//Input: s = "leetcode", t = "practice"
//Output: 5
//Explanation: Replace 'p', 'r', 'a', 'i' and 'c' from t with proper characters to make t anagram of s.
//Example 3:
//Input: s = "anagram", t = "mangaar"
//Output: 0
//Explanation: "anagram" and "mangaar" are anagrams. 
// 
//Constraints:
//	1 <= s.length <= 5 * 104
//	s.length == t.length
//	s and t consist of lowercase English letters only.
int minSteps(char * s, char * t){
int len = strlen(s);
    int *count = (int *)malloc(sizeof(int) * 26);
    memset(count, 0, sizeof(int) * 26);
    for (int i = 0; i < len; ++i) {
        ++count[s[i] - 'a'];
        --count[t[i] - 'a'];
    }
    int res = 0;
    for (int i = 0; i < 26; ++i) {
        if (count[i] > 0) {
            res += count[i];
        }
    }
    return res;
}