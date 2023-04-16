/**https://leetcode.com/problems/minimum-number-of-operations-to-make-string-sorted/ */
//You are given a string s (0-indexed) you are asked to perform the following operation on s until you get a sorted string:
//Find the largest index i such that 1 <= i < s.length and s[i] < s[i - 1].
//Find the largest index j such that i <= j < s.length and s[k] < s[i - 1] for all the possible values of k in the range [i, j] inclusive.
//Swap the two characters at indices i - 1 and j.
//Reverse the suffix starting at index i.
//Return the number of operations needed to make the string sorted. Since the answer can be too large, return it modulo 10^9 + 7.


/**
 * @param {string} s
 * @return {number}
 */
var makeStringSorted = function(s) {
    let result = 0;
    let map = new Map();
    for (let i = 0; i < s.length; i++) {
        let key = s[i];
        if (!map.has(key)) {
            map.set(key, 1);
        } else {
            map.set(key, map.get(key) + 1);
        }
    }
    let factorial = new Array(s.length + 1);
    factorial[0] = 1;
    factorial[1] = 1;
    for (let i = 2; i <= s.length; i++) {
        factorial[i] = factorial[i - 1] * i;
    }
    let mod = 1000000007;
    for (let i = 0; i < s.length; i++) {
        let count = 0;
        for (let [key, value] of map) {
            if (key < s[i]) {
                count += value;
            }
        }
        let current = factorial[s.length - i - 1];
        for (let [key, value] of map) {
            current = current / factorial[value];
        }
        result += count * current;
        result = result % mod;
        map.set(s[i], map.get(s[i]) - 1);
    }
    return result;
    
};

    