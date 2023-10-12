/**https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/ */
//You are given a string s formed by digits and '#'. We want to map s to English lowercase characters as follows:
//	Characters ('a' to 'i') are represented by ('1' to '9') respectively.
//	Characters ('j' to 'z') are represented by ('10#' to '26#') respectively.
//Return the string formed after mapping.
//The test cases are generated so that a unique mapping will always exist.
// 
//Example 1:
//Input: s = "10#11#12"
//Output: "jkab"
//Explanation: "j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".
//Example 2:
//Input: s = "1326#"
//Output: "acz"
// 
//Constraints:
//	1 <= s.length <= 1000
//	s consists of digits and the '#' letter.
//	s will be a valid string such that mapping is always possible.
char * freqAlphabets(char * s){
int i = len - 1;
    int j = len - 1;
    while(i >= 0){
        if(s[i] == '#'){
            s[j--] = (s[i - 2] - '0') * 10 + s[i - 1] - '0' - 1 + 'a';
            i -= 3;
        }else{
            s[j--] = s[i--] - '0' - 1 + 'a';
        }
    }
    return s + j + 1;
}