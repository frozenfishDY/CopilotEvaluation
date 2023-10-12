/**https://leetcode.com/problems/permutation-in-string/ */
//Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
//In other words, return true if one of s1's permutations is the substring of s2.
// 
//Example 1:
//Input: s1 = "ab", s2 = "eidbaooo"
//Output: true
//Explanation: s2 contains one permutation of s1 ("ba").
//Example 2:
//Input: s1 = "ab", s2 = "eidboaoo"
//Output: false
// 
//Constraints:
//	1 <= s1.length, s2.length <= 104
//	s1 and s2 consist of lowercase English letters.
bool checkInclusion(char * s1, char * s2){
int len1 = strlen(s1);
    int len2 = strlen(s2);
    int* count = (int*)malloc(sizeof(int) * 26);
    memset(count, 0, sizeof(int) * 26);
    for (int i = 0; i < len1; i++) {
        count[s1[i] - 'a']++;
    }
    int i = 0, j = 0, k = 0;
    while (j < len2) {
        count[s2[j] - 'a']--;
        if (count[s2[j] - 'a'] < 0) {
            while (s2[i] != s2[j]) {
                count[s2[i] - 'a']++;
                i++;
            }
            count[s2[i] - 'a']++;
            i++;
        }
        if (j - i + 1 == len1) {
            return true;
        }
        j++;
    }
    return false;
}