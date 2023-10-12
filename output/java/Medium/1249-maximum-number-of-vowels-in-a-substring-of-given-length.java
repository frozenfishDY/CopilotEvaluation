/**https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/ */
//Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.
//Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.
// 
//Example 1:
//Input: s = "abciiidef", k = 3
//Output: 3
//Explanation: The substring "iii" contains 3 vowel letters.
//Example 2:
//Input: s = "aeiou", k = 2
//Output: 2
//Explanation: Any substring of length 2 contains 2 vowels.
//Example 3:
//Input: s = "leetcode", k = 3
//Output: 2
//Explanation: "lee", "eet" and "ode" contain 2 vowels.
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists of lowercase English letters.
//	1 <= k <= s.length
class Solution {
    public int maxVowels(String s, int k) {
        int n = s.length();
        int[] arr = new int[n];
        int[] sum = new int[n];
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == 'a' || s.charAt(i) == 'e'
               || s.charAt(i) == 'i' || s.charAt(i) == 'o'
               || s.charAt(i) == 'u') {
                arr[i] = 1;
            }
        }
        sum[0] = arr[0];
        for (int i = 1; i < n; i++) {
            sum[i] = sum[i-1] + arr[i];
        }
        for (int i = k - 1; i < n; i++) {
            int cur = sum[i];
            if (i - k >= 0) {
                cur -= sum[i-k];
            }
            res = Math.max(res, cur);
        }
        return res;
    }
}