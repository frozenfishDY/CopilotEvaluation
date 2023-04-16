/**https://leetcode.com/problems/minimum-number-of-frogs-croaking/ */
//You are given the string croakOfFrogs, which represents a combination of the string "croak" from different frogs, that is, multiple frogs can croak at the same time, so multiple "croak" are mixed.
//Return the minimum number of different frogs to finish all the croaks in the given string.
//A valid "croak" means a frog is printing five letters 'c', 'r', 'o', 'a', and 'k' sequentially. The frogs have to print all five letters to finish a croak. If the given string is not a combination of a valid "croak" return -1.


/**
 * @param {string} croakOfFrogs
 * @return {number}
 */
var minNumberOfFrogs = function(croakOfFrogs) {
    let count = 0;
    let c = 0;
    let r = 0;
    let o = 0;
    let a = 0;
    let k = 0;
    for (let i = 0; i < croakOfFrogs.length; i++) {
        if (croakOfFrogs[i] === 'c') {
            c++;
        } else if (croakOfFrogs[i] === 'r') {
            r++;
        } else if (croakOfFrogs[i] === 'o') {
            o++;
        } else if (croakOfFrogs[i] === 'a') {
            a++;
        } else if (croakOfFrogs[i] === 'k') {
            k++;
        }
        if (c < r || r < o || o < a || a < k) {
            return -1;
        }
        count = Math.max(count, c - k);
    }
    if (c !== k) {
        return -1;
    }
    return count;
    
};

    