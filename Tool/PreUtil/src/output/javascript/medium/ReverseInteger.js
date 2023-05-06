/**https://leetcode.com/problems/reverse-integer/ */
//Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
//Assume the environment does not allow you to store 64-bit integers (signed or unsigned).


/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    let reversed = 0;
    while(x != 0){
        let digit = x % 10;
        x = Math.floor(x / 10);
        reversed = reversed * 10 + digit;
    }
    if(reversed > Math.pow(2, 31) - 1 || reversed < Math.pow(-2, 31)){
        return 0;
    }
    return reversed;
};

    