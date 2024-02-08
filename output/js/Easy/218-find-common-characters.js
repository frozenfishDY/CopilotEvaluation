/**https://leetcode.com/problems/find-common-characters/ */
//Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.
// 
//Example 1:
//Input: words = ["bella","label","roller"]
//Output: ["e","l","l"]
//Example 2:
//Input: words = ["cool","lock","cook"]
//Output: ["c","o"]
// 
//Constraints:
//	1 <= words.length <= 100
//	1 <= words[i].length <= 100
//	words[i] consists of lowercase English letters.
/**
 * @param {string[]} words
 * @return {string[]}
 */
var commonChars = function(words) {
    let res = [];
    for (let c of words[0]) {
        if (words.every(w => w.includes(c))) {
            words = words.map(w => w.replace(c, ''));
            res.push(c);
        }
    }
    return res;
};