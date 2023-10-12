/**https://leetcode.com/problems/word-pattern/ */
//Given a pattern and a string s, find if s follows the same pattern.
//Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.
// 
//Example 1:
//Input: pattern = "abba", s = "dog cat cat dog"
//Output: true
//Example 2:
//Input: pattern = "abba", s = "dog cat cat fish"
//Output: false
//Example 3:
//Input: pattern = "aaaa", s = "dog cat cat dog"
//Output: false
// 
//Constraints:
//	1 <= pattern.length <= 300
//	pattern contains only lower-case English letters.
//	1 <= s.length <= 3000
//	s contains only lowercase English letters and spaces ' '.
//	s does not contain any leading or trailing spaces.
//	All the words in s are separated by a single space.
bool wordPattern(char * pattern, char * s){
    char *map[26] = {NULL};
    char *token = strtok(s, " ");
    int i = 0;
    while (token) {
        if (i >= strlen(pattern)) return false;
        char *p = map[pattern[i] - 'a'];
        if (p == NULL) {
            for (int j = 0; j < 26; j++) {
                if (map[j] && strcmp(map[j], token) == 0) return false;
            }
            map[pattern[i] - 'a'] = token;
        } else if (strcmp(p, token) != 0) return false;
        token = strtok(NULL, " ");
        i++;
    }
    return i == strlen(pattern);

}