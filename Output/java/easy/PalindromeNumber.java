/**https://leetcode.com/problems/palindrome-number/ */
//Given an integer x, return true if x is a palindrome, and false otherwise.

    class PalindromeNumber {
    public boolean isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        int reverse = 0;
        int original = x;
        while(x != 0){
            reverse = reverse * 10 + x % 10;
            x = x / 10;
        }
        return reverse == original;
        
        
    }
}

    