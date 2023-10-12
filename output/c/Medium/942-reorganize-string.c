/**https://leetcode.com/problems/reorganize-string/ */
//Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
//Return any possible rearrangement of s or return "" if not possible.
// 
//Example 1:
//Input: s = "aab"
//Output: "aba"
//Example 2:
//Input: s = "aaab"
//Output: ""
// 
//Constraints:
//	1 <= s.length <= 500
//	s consists of lowercase English letters.
char * reorganizeString(char * s){
int length = strlen(s);
    int count[26] = {0};
    int max = 0;
    for (int i = 0; i < length; i++) {
        count[s[i] - 'a']++;
        if (count[s[i] - 'a'] > max) {
            max = count[s[i] - 'a'];
        }
    }
    if (max > (length + 1) / 2) {
        return "";
    }
    char* result = (char*)malloc(sizeof(char) * (length + 1));
    result[length] = '\0';
    int evenIndex = 0, oddIndex = 1;
    for (int i = 0; i < 26; i++) {
        while (count[i] > 0 && count[i] < (length + 1) / 2 && oddIndex < length) {
            result[oddIndex] = 'a' + i;
            count[i]--;
            oddIndex += 2;
        }
        while (count[i] > 0) {
            result[evenIndex] = 'a' + i;
            count[i]--;
            evenIndex += 2;
        }
    }
    return result;
}