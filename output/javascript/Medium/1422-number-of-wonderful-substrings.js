/**https://leetcode.com/problems/number-of-wonderful-substrings/ */
//A wonderful string is a string where at most one letter appears an odd number of times._x000D_
//_x000D_
//_x000D_
//	For example, "ccjjc" and "abab" are wonderful, but "ab" is not._x000D_
//_x000D_
//_x000D_
//Given a string word that consists of the first ten lowercase English letters ('a' through 'j'), return the number of wonderful non-empty substrings in word. If the same substring appears multiple times in word, then count each occurrence separately._x000D_
//_x000D_
//A substring is a contiguous sequence of characters in a string._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//Input: word = "aba"_x000D_
//Output: 4_x000D_
//Explanation: The four wonderful substrings are underlined below:_x000D_
//- "aba" -> "a"_x000D_
//- "aba" -> "b"_x000D_
//- "aba" -> "a"_x000D_
//- "aba" -> "aba"_x000D_
//_x000D_
//_x000D_
//Example 2:_x000D_
//_x000D_
//_x000D_
//Input: word = "aabb"_x000D_
//Output: 9_x000D_
//Explanation: The nine wonderful substrings are underlined below:_x000D_
//- "aabb" -> "a"_x000D_
//- "aabb" -> "aa"_x000D_
//- "aabb" -> "aab"_x000D_
//- "aabb" -> "aabb"_x000D_
//- "aabb" -> "a"_x000D_
//- "aabb" -> "abb"_x000D_
//- "aabb" -> "b"_x000D_
//- "aabb" -> "bb"_x000D_
//- "aabb" -> "b"_x000D_
//_x000D_
//_x000D_
//Example 3:_x000D_
//_x000D_
//_x000D_
//Input: word = "he"_x000D_
//Output: 2_x000D_
//Explanation: The two wonderful substrings are underlined below:_x000D_
//- "he" -> "h"_x000D_
//- "he" -> "e"_x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	1 <= word.length <= 105_x000D_
//	word consists of lowercase English letters from 'a' to 'j'._x000D_
/**_x000D_
 * @param {string} word_x000D_
 * @return {number}_x000D_
 */
var wonderfulSubstrings = function(word) {
    let map = new Map();
    map.set(0, 1);
    let result = 0, prefix = 0;
    for(let i = 0; i < word.length; i++){
        prefix ^= 1 << (word.charCodeAt(i) - 'a'.charCodeAt(0));
        result += map.get(prefix) || 0;
        for(let j = 0; j < 10; j++){
            let temp = prefix ^ (1 << j);
            result += map.get(temp) || 0;
        }
        map.set(prefix, (map.get(prefix) || 0) + 1);
    }
    return result;
};