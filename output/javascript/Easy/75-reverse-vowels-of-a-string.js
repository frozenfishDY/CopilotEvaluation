/**https://leetcode.com/problems/reverse-vowels-of-a-string/ */
//Given a string s, reverse only all the vowels in the string and return it.
//The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.
// 
//Example 1:
//Input: s = "hello"
//Output: "holle"
//Example 2:
//Input: s = "leetcode"
//Output: "leotcede"
// 
//Constraints:
//	1 <= s.length <= 3 * 105
//	s consist of printable ASCII characters.
/**
 * @param {string} s
 * @return {string}
 */
var reverseVowels = function(s) {
    const length = s.length;
    const vowels = ['a', 'e', 'i', 'o', 'u'];
    let left = 0;
    let right = length - 1;
    const chars = s.split('');
    while (left < right) {
        if (vowels.includes(chars[left].toLowerCase()) && vowels.includes(chars[right].toLowerCase())) {
            const tmp = chars[left];
            chars[left] = chars[right];
            chars[right] = tmp;
            left++;
            right--;
        } else if (!vowels.includes(chars[left].toLowerCase())) {
            left++;
        } else if (!vowels.includes(chars[right].toLowerCase())) {
            right--;
        }
    }
    return chars.join('');
};