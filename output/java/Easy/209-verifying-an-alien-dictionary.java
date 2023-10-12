/**https://leetcode.com/problems/verifying-an-alien-dictionary/ */
//In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.
//Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographically in this alien language.
// 
//Example 1:
//Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
//Output: true
//Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
//Example 2:
//Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
//Output: false
//Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
//Example 3:
//Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
//Output: false
//Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).
// 
//Constraints:
//	1 <= words.length <= 100
//	1 <= words[i].length <= 20
//	order.length == 26
//	All characters in words[i] and order are English lowercase letters.
class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        int[] index = new int[26];
        int len = words.length;
        for(int i = 0; i < order.length(); i++){
            index[order.charAt(i) - 'a'] = i;
        }
        for(int i = 0; i < len - 1; i++){
            if(!compare(words[i], words[i + 1], index)){
                return false;
            }
        }
        return true;
    }
    private boolean compare(String s1, String s2, int[] index){
        int len1 = s1.length();
        int len2 = s2.length();
        int min = Math.min(len1, len2);
        for(int i = 0; i < min; i++){
            char c1 = s1.charAt(i);
            char c2 = s2.charAt(i);
            if(c1 != c2){
                return index[c1 - 'a'] < index[c2 - 'a'];
            }
        }
        return len1 <= len2;
    }
}