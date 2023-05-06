/**https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/ */
//Given the binary representation of an integer as a string s, return the number of steps to reduce it to 1 under the following rules:
//If the current number is even, you have to divide it by 2.
//If the current number is odd, you have to add 1 to it.
//It is guaranteed that you can always reach one for all test cases.


/**
 * @param {string} s
 * @return {number}
 */
var numSteps = function(s) {
    let count = 0;
    let i = s.length - 1;
    while (i > 0) {
        if (s[i] === '0') {
            s = s.substring(0, i);
        } else {
            let j = i;
            while (j >= 0 && s[j] === '1') {
                s = s.substring(0, j) + '0' + s.substring(j + 1);
                j--;
            }
            if (j < 0) {
                s = '1' + s;
            } else {
                s = s.substring(0, j) + '1' + s.substring(j + 1);
            }
        }
        count++;
        i = s.length - 1;
    }
    return count;
    
};

    