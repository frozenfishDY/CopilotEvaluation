/**https://leetcode.com/problems/swap-for-longest-repeated-character-substring/ */
//You are given a string text. You can swap two of the characters in the text.
//Return the length of the longest substring with repeated characters.
// 
//Example 1:
//Input: text = "ababa"
//Output: 3
//Explanation: We can swap the first 'b' with the last 'a', or the last 'b' with the first 'a'. Then, the longest repeated character substring is "aaa" with length 3.
//Example 2:
//Input: text = "aaabaaa"
//Output: 6
//Explanation: Swap 'b' with the last 'a' (or the first 'a'), and we get longest repeated character substring "aaaaaa" with length 6.
//Example 3:
//Input: text = "aaaaa"
//Output: 5
//Explanation: No need to swap, longest repeated character substring is "aaaaa" with length is 5.
// 
//Constraints:
//	1 <= text.length <= 2 * 104
//	text consist of lowercase English characters only.
class Solution {
    public int maxRepOpt1(String text) {
        int ans = 1;
        Map<Character, Integer> map = new HashMap<>();
        for(char c: text.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0)+1);
        }
        for(int i = 0; i < text.length(); i++) {
            char c = text.charAt(i);
            int count = 1;
            for(int j = i+1; j < text.length(); j++) {
                if(text.charAt(j) == c) {
                    count++;
                }
                else if(map.get(c) > count) {
                    count++;
                }
                else {
                    break;
                }
            }
            ans = Math.max(ans, count);
        }
        return ans;
    }
}