/**https://leetcode.com/problems/next-greater-element-iii/ */
//Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.
//Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.
// 
//Example 1:
//Input: n = 12
//Output: 21
//Example 2:
//Input: n = 21
//Output: -1
// 
//Constraints:
//	1 <= n <= 231 - 1
/**
 * @param {number} n
 * @return {number}
 */
var nextGreaterElement = function(n) {
    let numStr = n.toString().split('');
    let i = numStr.length - 1;
    while (i > 0 && numStr[i - 1] >= numStr[i]) {
        i--;
    }
    if (i === 0) return -1;
    let j = numStr.length - 1;
    while (j >= i && numStr[j] <= numStr[i - 1]) {
        j--;
    }
    swap(numStr, i - 1, j);
    reverse(numStr, i);
    let result = parseInt(numStr.join(''));
    return result > 2147483647 ? -1 : result;
};
function swap(arr, i, j) {
    [arr[i], arr[j]] = [arr[j], arr[i]];
}

function reverse(arr, start) {
    let i = start;
    let j = arr.length - 1;
    while (i < j) {
        swap(arr, i, j);
        i++;
        j--;
    }
}