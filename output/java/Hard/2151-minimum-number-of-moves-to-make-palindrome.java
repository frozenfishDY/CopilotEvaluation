/**https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome/ */
//You are given a string s consisting only of lowercase English letters.
//In one move, you can select any two adjacent characters of s and swap them.
//Return the minimum number of moves needed to make s a palindrome.
//Note that the input will be generated such that s can always be converted to a palindrome.


class MinimumNumberOfMovesToMakePalindrome {
    public int minMovesToMakePalindrome(String s) {
        int n = s.length();
        int left = 0;
        int right = n - 1;
        int res = 0;
        while (left < right) {
            if (s.charAt(left) != s.charAt(right)) {
                res += Math.min(s.charAt(left), s.charAt(right)) - 'a';
            }
            left++;
            right--;
        }
        return res;
        
    }
}
     
    