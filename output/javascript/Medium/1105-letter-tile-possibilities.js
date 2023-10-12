/**https://leetcode.com/problems/letter-tile-possibilities/ */
//You have n  tiles, where each tile has one letter tiles[i] printed on it.
//Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.
// 
//Example 1:
//Input: tiles = "AAB"
//Output: 8
//Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
//Example 2:
//Input: tiles = "AAABBC"
//Output: 188
//Example 3:
//Input: tiles = "V"
//Output: 1
// 
//Constraints:
//	1 <= tiles.length <= 7
//	tiles consists of uppercase English letters.
/**
 * @param {string} tiles
 * @return {number}
 */
var numTilePossibilities = function(tiles) {
    const visited = new Array(tiles.length).fill(false);
    const set = new Set();
    const dfs = (str) => {
        if (str.length > 0) {
            set.add(str);
        }
        for (let i = 0; i < tiles.length; i++) {
            if (!visited[i]) {
                visited[i] = true;
                dfs(str + tiles[i]);
                visited[i] = false;
            }
        }
    }
    dfs('');
    return set.size;
};