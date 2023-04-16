/**https://leetcode.com/problems/maximum-white-tiles-covered-by-a-carpet/ */
//You are given a 2D integer array tiles where tiles[i] = [li, ri] represents that every tile j in the range li <= j <= ri is colored white.
//You are also given an integer carpetLen, the length of a single carpet that can be placed anywhere.
//Return the maximum number of white tiles that can be covered by the carpet.


/**
 * @param {number[][]} tiles
 * @param {number} carpetLen
 * @return {number}
 */
var maximumWhiteTiles = function(tiles, carpetLen) {
    let n = tiles.length;
    let start = new Array(n);
    let end = new Array(n);
    for (let i = 0; i < n; i++) {
        start[i] = tiles[i][0];
        end[i] = tiles[i][1];
    }
    start.sort((a, b) => a - b);
    end.sort((a, b) => a - b);
    let count = 0;
    let max = 0;
    let i = 0;
    let j = 0;
    while (i < n && j < n) {
        if (start[i] <= end[j]) {
            count++;
            max = Math.max(max, count);
            i++;
        } else {
            count--;
            j++;
        }
    }
    return max + carpetLen - 1;
    
};

    