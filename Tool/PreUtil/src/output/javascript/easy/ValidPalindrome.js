/**https://leetcode.com/problems/valid-palindrome/ */
//A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
//Given a string s, return true if it is a palindrome, or false otherwise.


/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    let left = 0;
    let right = s.length - 1;
    while(left < right){
        while(!isAlphaNumeric(s[left]) && left < right){
            left++;
        }
        while(!isAlphaNumeric(s[right]) && left < right){
            right--;
        }
        if(s[left].toLowerCase() !== s[right].toLowerCase()){
            return false;
        }
        left++;
        right--;
    }
    return true;
    
    
};

    