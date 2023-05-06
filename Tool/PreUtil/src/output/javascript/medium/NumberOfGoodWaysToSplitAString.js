/**https://leetcode.com/problems/number-of-good-ways-to-split-a-string/ */
//You are given a string s.
//A split is called good if you can split s into two non-empty strings sleft and sright where their concatenation is equal to s (i.e., sleft + sright = s) and the number of distinct letters in sleft and sright is the same.
//Return the number of good splits you can make in s.


/**
 * @param {string} s
 * @return {number}
 */
var numSplits = function(s) {
    let count = 0;
    let left = new Set();
    let right = new Set();
    let leftCount = 0;
    let rightCount = 0;
    for (let i = 0; i < s.length; i++) {
        if (!right.has(s[i])) {
            rightCount++;
            right.add(s[i]);
        }
    }
    for (let i = 0; i < s.length; i++) {
        if (!left.has(s[i])) {
            leftCount++;
            left.add(s[i]);
        }
        if (right.has(s[i])) {
            rightCount--;
            right.delete(s[i]);
        }
        if (leftCount === rightCount) {
            count++;
        }
    }
    return count;
    
};

    