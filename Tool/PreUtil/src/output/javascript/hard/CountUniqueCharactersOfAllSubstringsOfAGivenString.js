/**https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/ */
//Let's define a function countUniqueChars(s) that returns the number of unique characters on s.
//For example, calling countUniqueChars(s) if s = "LEETCODE" then "L", "T", "C", "O", "D" are the unique characters since they appear only once in s, therefore countUniqueChars(s) = 5.
//Given a string s, return the sum of countUniqueChars(t) where t is a substring of s. The test cases are generated such that the answer fits in a 32-bit integer.
//Notice that some substrings can be repeated so in this case you have to count the repeated ones too.


/**
 * @param {string} s
 * @return {number}
 */
var uniqueLetterString = function(s) {
    const n = s.length;
    const pos = new Array(26).fill(0).map(() => new Array());
    const mod = 10 ** 9 + 7;
    let ans = 0;
    
    for (let i = 0; i < n; i++) {
        pos[s[i].charCodeAt() - 'A'.charCodeAt()].push(i);
    }
    
    for (let i = 0; i < 26; i++) {
        const m = pos[i].length;
        for (let j = 0; j < m; j++) {
            const left = j > 0 ? pos[i][j - 1] : -1;
            const right = j < m - 1 ? pos[i][j + 1] : n;
            ans = (ans + (pos[i][j] - left) * (right - pos[i][j])) % mod;
        }
    }
    
    return ans;
    
};

    