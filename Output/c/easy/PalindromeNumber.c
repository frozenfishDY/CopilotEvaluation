/**https://leetcode.com/problems/palindrome-number/ */
//Given an integer x, return true if x is a palindrome, and false otherwise.

bool isPalindrome(int x){
    if(x < 0){
        return false;
    }
    int temp = x;
    int reverse = 0;
    while(temp != 0){
        reverse = reverse * 10 + temp % 10;
        temp = temp / 10;
    }
    if(reverse == x){
        return true;
    }
    return false;
   

}
    