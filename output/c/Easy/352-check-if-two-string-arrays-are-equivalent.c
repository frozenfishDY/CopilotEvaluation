/**https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/ */
//Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.
//A string is represented by an array if the array elements concatenated in order forms the string.
// 
//Example 1:
//Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
//Output: true
//Explanation:
//word1 represents string "ab" + "c" -> "abc"
//word2 represents string "a" + "bc" -> "abc"
//The strings are the same, so return true.
//Example 2:
//Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
//Output: false
//Example 3:
//Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
//Output: true
// 
//Constraints:
//	1 <= word1.length, word2.length <= 103
//	1 <= word1[i].length, word2[i].length <= 103
//	1 <= sum(word1[i].length), sum(word2[i].length) <= 103
//	word1[i] and word2[i] consist of lowercase letters.
bool arrayStringsAreEqual(char ** word1, int word1Size, char ** word2, int word2Size){
int i = 0, j = 0, k = 0, l = 0;
    while(i < word1Size && j < word2Size){
        while(word1[i][k] != '\0' && word2[j][l] != '\0'){
            if(word1[i][k] != word2[j][l]){
                return false;
            }
            k++;
            l++;
        }
        if(word1[i][k] == '\0'){
            k = 0;
            i++;
        }
        if(word2[j][l] == '\0'){
            l = 0;
            j++;
        }
    }
    if(i < word1Size || j < word2Size){
        return false;
    }
    return true;
}