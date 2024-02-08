/**https://leetcode.com/problems/super-palindromes/ */
//Let's say a positive integer is a super-palindrome if it is a palindrome, and it is also the square of a palindrome.
//Given two positive integers left and right represented as strings, return the number of super-palindromes integers in the inclusive range [left, right].


class SuperPalindromes {
    public int superpalindromesInRange(String left, String right) {
        long l = Long.parseLong(left);
        long r = Long.parseLong(right);
        int ans = 0;
        for (long i = 1; i <= 100000; i++) {
            String s = Long.toString(i);
            String t = new StringBuilder(s).reverse().toString();
            long v = Long.parseLong(s + t);
            v *= v;
            if (v > r) {
                break;
            }
            if (v >= l && isPalindrome(v)) {
                ans++;
            }
        }
        for (long i = 1; i <= 100000; i++) {
            String s = Long.toString(i);
            String t = new StringBuilder(s).deleteCharAt(s.length() - 1).reverse().toString();
            long v = Long.parseLong(s + t);
            v *= v;
            if (v > r) {
                break;
            }
            if (v >= l && isPalindrome(v)) {
                ans++;
            }
        }
        return ans;
        
        
    }
}
     
    