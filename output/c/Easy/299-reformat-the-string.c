/**https://leetcode.com/problems/reformat-the-string/ */
//You are given an alphanumeric string s. (Alphanumeric string is a string consisting of lowercase English letters and digits).
//You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit. That is, no two adjacent characters have the same type.
//Return the reformatted string or return an empty string if it is impossible to reformat the string.
// 
//Example 1:
//Input: s = "a0b1c2"
//Output: "0a1b2c"
//Explanation: No two adjacent characters have the same type in "0a1b2c". "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.
//Example 2:
//Input: s = "leetcode"
//Output: ""
//Explanation: "leetcode" has only characters so we cannot separate them by digits.
//Example 3:
//Input: s = "1229857369"
//Output: ""
//Explanation: "1229857369" has only digits so we cannot separate them by characters.
// 
//Constraints:
//	1 <= s.length <= 500
//	s consists of only lowercase English letters and/or digits.
char * reformat(char * s){
int i, j, k, l, len = strlen(s);
    char *result = malloc(sizeof(char) * (len + 1));
    int *count = calloc(26, sizeof(int));
    for(i = 0; i < len; i++)
        count[s[i] - 'a']++;
    for(i = 0, j = 0, k = 25; i < len;){
        if(count[j] > 0){
            result[i++] = j + 'a';
            count[j]--;
        }
        if(count[k] > 0){
            result[i++] = k + 'a';
            count[k]--;
        }
        if(j == k)
            break;
        if(j < k)
            j++;
        else
            k--;
    }
    result[len] = '\0';
    return result;
}