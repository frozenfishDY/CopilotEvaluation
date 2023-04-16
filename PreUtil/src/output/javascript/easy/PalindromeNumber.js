/**https://leetcode.com/problems/palindrome-number/ */
//Given an integer x, return true if x is a palindrome, and false otherwise.

   /**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    if(x < 0) return false;
    let rev = 0;
    let num = x;
    while(num > 0){
        rev = rev * 10 + num % 10;
        num = Math.floor(num / 10);
    }
    return rev === x;
    
    
};

    