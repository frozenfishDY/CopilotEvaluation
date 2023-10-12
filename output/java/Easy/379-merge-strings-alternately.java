/**https://leetcode.com/problems/merge-strings-alternately/ */
//You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string._x000D_
//_x000D_
//Return the merged string._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//Input: word1 = "abc", word2 = "pqr"_x000D_
//Output: "apbqcr"_x000D_
//Explanation: The merged string will be merged as so:_x000D_
//word1:  a   b   c_x000D_
//word2:    p   q   r_x000D_
//merged: a p b q c r_x000D_
//_x000D_
//_x000D_
//Example 2:_x000D_
//_x000D_
//_x000D_
//Input: word1 = "ab", word2 = "pqrs"_x000D_
//Output: "apbqrs"_x000D_
//Explanation: Notice that as word2 is longer, "rs" is appended to the end._x000D_
//word1:  a   b _x000D_
//word2:    p   q   r   s_x000D_
//merged: a p b q   r   s_x000D_
//_x000D_
//_x000D_
//Example 3:_x000D_
//_x000D_
//_x000D_
//Input: word1 = "abcd", word2 = "pq"_x000D_
//Output: "apbqcd"_x000D_
//Explanation: Notice that as word1 is longer, "cd" is appended to the end._x000D_
//word1:  a   b   c   d_x000D_
//word2:    p   q _x000D_
//merged: a p b q c   d_x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	1 <= word1.length, word2.length <= 100_x000D_
//	word1 and word2 consist of lowercase English letters._x000D_
class Solution {
    public String mergeAlternately(String word1, String word2) {
        StringBuilder sb = new StringBuilder();
        int i = 0;
        int j = 0;
        while(i < word1.length() || j < word2.length()){
            if(i < word1.length()){
                sb.append(word1.charAt(i));
                i++;
            }
            if(j < word2.length()){
                sb.append(word2.charAt(j));
                j++;
            }
        }
        return sb.toString();
    }
}