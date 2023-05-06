/**https://leetcode.com/problems/break-a-palindrome/ */
//Given a palindromic string of lowercase English letters palindrome, replace exactly one character with any lowercase English letter so that the resulting string is not a palindrome and that it is the lexicographically smallest one possible.
//Return the resulting string. If there is no way to replace a character to make it not a palindrome, return an empty string.
//A string a is lexicographically smaller than a string b (of the same length) if in the first position where a and b differ, a has a character strictly smaller than the corresponding character in b. For example, "abcc" is lexicographically smaller than "abcd" because the first position they differ is at the fourth character, and 'c' is smaller than 'd'.


/**
 * @param {string} palindrome
 * @return {string}
 */
var breakPalindrome = function(palindrome) {
    let n = palindrome.length;
    if(n == 1){
        return "";
    }
    let result = palindrome.split("");
    for(let i = 0; i < n / 2; i++){
        if(palindrome[i] != 'a'){
            result[i] = 'a';
            return result.join("");
        }
    }
    result[n - 1] = 'b';
    return result.join("");
    
};

    