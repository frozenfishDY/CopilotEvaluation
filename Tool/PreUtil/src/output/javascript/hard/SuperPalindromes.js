/**https://leetcode.com/problems/super-palindromes/ */
//Let's say a positive integer is a super-palindrome if it is a palindrome, and it is also the square of a palindrome.
//Given two positive integers left and right represented as strings, return the number of super-palindromes integers in the inclusive range [left, right].


/**
 * @param {string} left
 * @param {string} right
 * @return {number}
 */
var superpalindromesInRange = function(left, right) {
    let ans = 0;
    let l = Math.ceil(Math.sqrt(Number(left)));
    let r = Math.floor(Math.sqrt(Number(right)));
    for(let i = l; i <= r; i++){
        if(isPalindrome(i) && isPalindrome(i * i)){
            ans++;
        }
    }
    for(let i = 1; i <= 100000; i++){
        let s = i.toString();
        let t = s.split("").reverse().join("");
        let num = Number(s + t);
        if(num > r){
            break;
        }
        if(num >= l && isPalindrome(num * num)){
            ans++;
        }
    }
    return ans;
    
    
};

    