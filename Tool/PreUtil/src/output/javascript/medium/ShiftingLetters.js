/**https://leetcode.com/problems/shifting-letters/ */
//You are given a string s of lowercase English letters and an integer array shifts of the same length.
//Call the shift() of a letter, the next letter in the alphabet, (wrapping around so that 'z' becomes 'a').
//For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.
//Now for each shifts[i] = x, we want to shift the first i + 1 letters of s, x times.
//Return the final string after all such shifts to s are applied.


/**
 * @param {string} s
 * @param {number[]} shifts
 * @return {string}
 */
var shiftingLetters = function(s, shifts) {
    let n = s.length;
    let result = new Array(n);
    let sum = 0;
    for(let i = n - 1; i >= 0; i--){
        sum = (sum + shifts[i]) % 26;
        result[i] = String.fromCharCode((s.charCodeAt(i) - 'a'.charCodeAt(0) + sum) % 26 + 'a'.charCodeAt(0));
    }
    return result.join('');
    
};

    