/**https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/ */
//Given a string s, return true if s is a good string, or false otherwise.
//A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).
// 
//Example 1:
//Input: s = "abacbc"
//Output: true
//Explanation: The characters that appear in s are 'a', 'b', and 'c'. All characters occur 2 times in s.
//Example 2:
//Input: s = "aaabb"
//Output: false
//Explanation: The characters that appear in s are 'a' and 'b'.
//'a' occurs 3 times while 'b' occurs 2 times, which is not the same number of times.
// 
//Constraints:
//	1 <= s.length <= 1000
//	s consists of lowercase English letters.
bool areOccurrencesEqual(char * s){
int i = 0, j = 0, k = 0, l = 0, max = 0, cnt = 0, len = strlen(s);
    int *p = (int *)calloc(26, sizeof(int));
    for(i = 0; i < len; i++){
        p[s[i] - 'a']++;
    }
    for(i = 0; i < 26; i++){
        if(p[i] > 0){
            if(max == 0){
                max = p[i];
            }
            else if(max != p[i]){
                return false;
            }
        }
    }
    return true;
}