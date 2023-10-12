/**https://leetcode.com/problems/count-the-number-of-consistent-strings/ */
//You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.
//Return the number of consistent strings in the array words.
// 
//Example 1:
//Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
//Output: 2
//Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.
//Example 2:
//Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
//Output: 7
//Explanation: All strings are consistent.
//Example 3:
//Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
//Output: 4
//Explanation: Strings "cc", "acd", "ac", and "d" are consistent.
// 
//Constraints:
//	1 <= words.length <= 104
//	1 <= allowed.length <= 26
//	1 <= words[i].length <= 10
//	The characters in allowed are distinct.
//	words[i] and allowed contain only lowercase English letters.


int countConsistentStrings(char * allowed, char ** words, int wordsSize){
int i = 0, j = 0, k = 0, l = 0, cnt = 0, flag = 0;
    while(words[i] != NULL){
        while(words[i][j] != '\0'){
            while(allowed[k] != '\0'){
                if(words[i][j] == allowed[k]){
                    flag = 1;
                    break;
                }
                k++;
            }
            if(flag == 0){
                break;
            }
            flag = 0;
            k = 0;
            j++;
        }
        if(words[i][j] == '\0'){
            cnt++;
        }
        j = 0;
        i++;
    }
    return cnt;
}