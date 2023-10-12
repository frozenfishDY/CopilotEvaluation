/**https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/ */
//Given a string s and a string array dictionary, return the longest string in the dictionary that can be formed by deleting some of the given string characters. If there is more than one possible result, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.
// 
//Example 1:
//Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
//Output: "apple"
//Example 2:
//Input: s = "abpcplea", dictionary = ["a","b","c"]
//Output: "a"
// 
//Constraints:
//	1 <= s.length <= 1000
//	1 <= dictionary.length <= 1000
//	1 <= dictionary[i].length <= 1000
//	s and dictionary[i] consist of lowercase English letters.
char * findLongestWord(char * s, char ** dictionary, int dictionarySize){
int i = 0, j = 0, k = 0, l = 0, m = 0, n = 0;
    int len = strlen(s);
    char* res = (char*)malloc(sizeof(char) * (len + 1));
    memset(res, 0, sizeof(char) * (len + 1));
    for (i = 0; i < dictionarySize; i++) {
        char* tmp = dictionary[i];
        int tmpLen = strlen(tmp);
        if (tmpLen < len || (tmpLen == len && strcmp(tmp, res) > 0)) {
            continue;
        }
        int i = 0, j = 0;
        while (i < len && j < tmpLen) {
            if (s[i] == tmp[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        if (j == tmpLen) {
            strcpy(res, tmp);
        }
    }
    return res;
}