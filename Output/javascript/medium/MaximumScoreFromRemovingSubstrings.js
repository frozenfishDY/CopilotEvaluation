/**https://leetcode.com/problems/maximum-score-from-removing-substrings/ */
//You are given a string s and two integers x and y. You can perform two types of operations any number of times.
//Remove substring "ab" and gain x points.
//For example, when removing "ab" from "cabxbae" it becomes "cxbae".
//Remove substring "ba" and gain y points.
//For example, when removing "ba" from "cabxbae" it becomes "cabxe".
//Return the maximum points you can gain after applying the above operations on s.


/**
 * @param {string} s
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var maximumGain = function(s, x, y) {
    let n = s.length;
    let stack = [];
    let result = 0;
    let a = 'a'.charCodeAt(0);
    let b = 'b'.charCodeAt(0);
    let ab = 'ab'.charCodeAt(0);
    let ba = 'ba'.charCodeAt(0);
    for (let i = 0; i < n; i++) {
        let c = s.charCodeAt(i);
        if (c == a || c == b) {
            stack.push(c);
        } else {
            if (stack.length >= 2) {
                let last = stack[stack.length - 1];
                let secondLast = stack[stack.length - 2];
                if (last + secondLast == ab) {
                    result += x;
                    stack.pop();
                    stack.pop();
                } else if (last + secondLast == ba) {
                    result += y;
                    stack.pop();
                    stack.pop();
                }
            }
        }
    }
    return result;
    
};

    