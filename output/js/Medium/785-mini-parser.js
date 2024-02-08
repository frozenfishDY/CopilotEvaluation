/**https://leetcode.com/problems/mini-parser/ */
//Given a string s represents the serialization of a nested list, implement a parser to deserialize it and return the deserialized NestedInteger.
//Each element is either an integer or a list whose elements may also be integers or other lists.
// 
//Example 1:
//Input: s = "324"
//Output: 324
//Explanation: You should return a NestedInteger object which contains a single integer 324.
//Example 2:
//Input: s = "[123,[456,[789]]]"
//Output: [123,[456,[789]]]
//Explanation: Return a NestedInteger object containing a nested list with 2 elements:
//1. An integer containing value 123.
//2. A nested list containing two elements:
//    i.  An integer containing value 456.
//    ii. A nested list with one element:
//         a. An integer containing value 789
// 
//Constraints:
//	1 <= s.length <= 5 * 104
//	s consists of digits, square brackets "[]", negative sign '-', and commas ','.
//	s is the serialization of valid NestedInteger.
//	All the values in the input are in the range [-106, 106].
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * function NestedInteger() {
 *
 *     Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     @return {boolean}
 *     this.isInteger = function() {
 *         ...
 *     };
 *
 *     Return the single integer that this NestedInteger holds, if it holds a single integer
 *     Return null if this NestedInteger holds a nested list
 *     @return {integer}
 *     this.getInteger = function() {
 *         ...
 *     };
 *
 *     Set this NestedInteger to hold a single integer equal to value.
 *     @return {void}
 *     this.setInteger = function(value) {
 *         ...
 *     };
 *
 *     Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
 *     @return {void}
 *     this.add = function(elem) {
 *         ...
 *     };
 *
 *     Return the nested list that this NestedInteger holds, if it holds a nested list
 *     Return null if this NestedInteger holds a single integer
 *     @return {NestedInteger[]}
 *     this.getList = function() {
 *         ...
 *     };
 * };
 */
/**
 * @param {string} s
 * @return {NestedInteger}
 */
var deserialize = function(s) { 
    if (s[0] !== '[') {
        return new NestedInteger(Number(s));
    }
    let stack = [];
    let current = null;
    let start = 0;
    for (let i = 0; i < s.length; i++) {
        let char = s[i];
        if (char === '[') {
            let nestedInteger = new NestedInteger();
            if (current !== null) {
                current.add(nestedInteger);
            }
            stack.push(current);
            current = nestedInteger;
            start = i + 1;
        } else if (char === ',' || char === ']') {
            if (i > start) {
                let value = Number(s.substring(start, i));
                let nestedInteger = new NestedInteger(value);
                current.add(nestedInteger);
            }
            start = i + 1;
            if (char === ']') {
                current = stack.pop();
            }
        }
    }
    return current;
};