/**https://leetcode.com/problems/reverse-only-letters/ */
//Given a string s, reverse the string according to the following rules:
//	All the characters that are not English letters remain in the same position.
//	All the English letters (lowercase or uppercase) should be reversed.
//Return s after reversing it.
// 
//Example 1:
//Input: s = "ab-cd"
//Output: "dc-ba"
//Example 2:
//Input: s = "a-bC-dEf-ghIj"
//Output: "j-Ih-gfE-dCba"
//Example 3:
//Input: s = "Test1ng-Leet=code-Q!"
//Output: "Qedo1ct-eeLg=ntse-T!"
// 
//Constraints:
//	1 <= s.length <= 100
//	s consists of characters with ASCII values in the range [33, 122].
//	s does not contain '\"' or '\\'.
/**
 * @param {string} s
 * @return {string}
 */
var reverseOnlyLetters = function(s) {
    let arr = s.split('');
    let start = 0;
    let end = arr.length - 1;
    while (start < end) {
        if (!isLetter(arr[start])) {
            start++;
        } else if (!isLetter(arr[end])) {
            end--;
        } else {
            let temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
    return arr.join('');
};
function isLetter(c) {
    return c.toLowerCase() !== c.toUpperCase();
}