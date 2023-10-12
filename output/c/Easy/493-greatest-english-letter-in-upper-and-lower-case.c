/**https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case/ */
//Given a string of English letters s, return the greatest English letter which occurs as both a lowercase and uppercase letter in s. The returned letter should be in uppercase. If no such letter exists, return an empty string.
//An English letter b is greater than another letter a if b appears after a in the English alphabet.
// 
//Example 1:
//Input: s = "lEeTcOdE"
//Output: "E"
//Explanation:
//The letter 'E' is the only letter to appear in both lower and upper case.
//Example 2:
//Input: s = "arRAzFif"
//Output: "R"
//Explanation:
//The letter 'R' is the greatest letter to appear in both lower and upper case.
//Note that 'A' and 'F' also appear in both lower and upper case, but 'R' is greater than 'F' or 'A'.
//Example 3:
//Input: s = "AbCdEfGhIjK"
//Output: ""
//Explanation:
//There is no letter that appears in both lower and upper case.
// 
//Constraints:
//	1 <= s.length <= 1000
//	s consists of lowercase and uppercase English letters.
char * greatestLetter(char * s){
int i = 0;
    int *l = (int*)calloc(26, sizeof(int));
    int *u = (int*)calloc(26, sizeof(int));
    for (; i < strlen(s); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            l[s[i] - 'a']++;
        } else {
            u[s[i] - 'A']++;
        }
    }
    for (i = 25; i >= 0; i--) {
        if (l[i] > 0 && u[i] > 0) {
            char *res = (char*)calloc(2, sizeof(char));
            res[0] = i + 'A';
            return res;
        }
    }
    return "";
}