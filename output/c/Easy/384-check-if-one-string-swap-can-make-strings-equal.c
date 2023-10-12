/**https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/ */
//You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.
//Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.
// 
//Example 1:
//Input: s1 = "bank", s2 = "kanb"
//Output: true
//Explanation: For example, swap the first character with the last character of s2 to make "bank".
//Example 2:
//Input: s1 = "attack", s2 = "defend"
//Output: false
//Explanation: It is impossible to make them equal with one string swap.
//Example 3:
//Input: s1 = "kelb", s2 = "kelb"
//Output: true
//Explanation: The two strings are already equal, so no string swap operation is required.
// 
//Constraints:
//	1 <= s1.length, s2.length <= 100
//	s1.length == s2.length
//	s1 and s2 consist of only lowercase English letters.
bool areAlmostEqual(char * s1, char * s2){
int i = 0, j = 0, k = 0, l = 0, max = 0, cnt = 0, len = strlen(s1), pos1 = -1, pos2 = -1;
    if(strcmp(s1, s2) == 0){
        return true;
    }
    for(i = 0; i < len; i++){
        if(s1[i] != s2[i]){
            if(pos1 == -1){
                pos1 = i;
            }
            else if(pos2 == -1){
                pos2 = i;
            }
            else{
                return false;
            }
        }
    }
    if(pos2 == -1){
        return false;
    }
    if(s1[pos1] == s2[pos2] && s1[pos2] == s2[pos1]){
        return true;
    }
    return false;
}