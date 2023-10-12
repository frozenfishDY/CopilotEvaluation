/**https://leetcode.com/problems/special-binary-string/ */
//Special binary strings are binary strings with the following two properties:
//	The number of 0's is equal to the number of 1's.
//	Every prefix of the binary string has at least as many 1's as 0's.
//You are given a special binary string s.
//A move consists of choosing two consecutive, non-empty, special substrings of s, and swapping them. Two strings are consecutive if the last character of the first string is exactly one index before the first character of the second string.
//Return the lexicographically largest resulting string possible after applying the mentioned operations on the string.
// 
//Example 1:
//Input: s = "11011000"
//Output: "11100100"
//Explanation: The strings "10" [occuring at s[1]] and "1100" [at s[3]] are swapped.
//This is the lexicographically largest string possible after some number of swaps.
//Example 2:
//Input: s = "10"
//Output: "10"
// 
//Constraints:
//	1 <= s.length <= 50
//	s[i] is either '0' or '1'.
//	s is a special binary string.
char * makeLargestSpecial(char * s){
int len = strlen(s);
    int cnt = 0, idx = 0;
    char **temp = (char **)malloc(sizeof(char *) * len);
    for (int i = 0; i < len; i++) {
        if (s[i] == '1') cnt++;
        else cnt--;
        if (cnt == 0) {
            temp[idx] = (char *)malloc(sizeof(char) * (i - idx + 2));
            temp[idx][0] = '1';
            int j = 1;
            for (int k = idx + 1; k < i; k++) temp[idx][j++] = s[k];
            temp[idx][j] = '0';
            temp[idx][j + 1] = '\0';
            idx++;
        }
    }
    for (int i = 0; i < idx; i++) {
        for (int j = i + 1; j < idx; j++) {
            if (strcmp(temp[i], temp[j]) < 0) {
                char *t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }
    char *res = (char *)malloc(sizeof(char) * (len + 1));
    int i = 0;
    for (int j = 0; j < idx; j++) {
        for (int k = 0; k < strlen(temp[j]); k++) {
            res[i++] = temp[j][k];
        }
    }
    res[i] = '\0';
    return res;
}