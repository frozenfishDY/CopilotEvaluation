/**https://leetcode.com/problems/sorting-the-sentence/ */
//A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of lowercase and uppercase English letters._x000D_
//_x000D_
//A sentence can be shuffled by appending the 1-indexed word position to each word then rearranging the words in the sentence._x000D_
//_x000D_
//_x000D_
//	For example, the sentence "This is a sentence" can be shuffled as "sentence4 a3 is2 This1" or "is2 sentence4 This1 a3"._x000D_
//_x000D_
//_x000D_
//Given a shuffled sentence s containing no more than 9 words, reconstruct and return the original sentence._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//Input: s = "is2 sentence4 This1 a3"_x000D_
//Output: "This is a sentence"_x000D_
//Explanation: Sort the words in s to their original positions "This1 is2 a3 sentence4", then remove the numbers._x000D_
//_x000D_
//_x000D_
//Example 2:_x000D_
//_x000D_
//_x000D_
//Input: s = "Myself2 Me1 I4 and3"_x000D_
//Output: "Me Myself and I"_x000D_
//Explanation: Sort the words in s to their original positions "Me1 Myself2 and3 I4", then remove the numbers._x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	2 <= s.length <= 200_x000D_
//	s consists of lowercase and uppercase English letters, spaces, and digits from 1 to 9._x000D_
//	The number of words in s is between 1 and 9._x000D_
//	The words in s are separated by a single space._x000D_
//	s contains no leading or trailing spaces._x000D_
class Solution {
    public String sortSentence(String s) {
        String[] arr = s.split(" ");
        String[] res = new String[arr.length];
        for(int i = 0; i < arr.length; i++){
            int index = Integer.parseInt(arr[i].substring(arr[i].length() - 1));
            res[index - 1] = arr[i].substring(0, arr[i].length() - 1);
        }
        return String.join(" ", res);
    }
}