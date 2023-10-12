/**https://leetcode.com/problems/reconstruct-original-digits-from-english/ */
//Given a string s containing an out-of-order English representation of digits 0-9, return the digits in ascending order.
// 
//Example 1:
//Input: s = "owoztneoer"
//Output: "012"
//Example 2:
//Input: s = "fviefuro"
//Output: "45"
// 
//Constraints:
//	1 <= s.length <= 105
//	s[i] is one of the characters ["e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"].
//	s is guaranteed to be valid.
/**
 * @param {string} s
 * @return {string}
 */
var originalDigits = function(s) {
    let map = new Map();
    for (let i = 0; i < s.length; i++) {
        let char = s[i];
        if (map.has(char)) {
            map.set(char, map.get(char) + 1);
        } else {
            map.set(char, 1);
        }
    }
    let result = [];
    let digits = [
        ['z', 'zero', 0],
        ['w', 'two', 2],
        ['u', 'four', 4],
        ['x', 'six', 6],
        ['g', 'eight', 8],
        ['o', 'one', 1],
        ['t', 'three', 3],
        ['f', 'five', 5],
        ['s', 'seven', 7],
        ['i', 'nine', 9]
    ];
    for (let i = 0; i < digits.length; i++) {
        let digit = digits[i];
        let char = digit[0];
        let word = digit[1];
        let num = digit[2];
        let count = map.get(char);
        if (count) {
            for (let j = 0; j < word.length; j++) {
                let char = word[j];
                map.set(char, map.get(char) - count);
            }
            for (let j = 0; j < count; j++) {
                result.push(num);
            }
        }
    }
    return result.sort((a, b) => a - b).join('');
};