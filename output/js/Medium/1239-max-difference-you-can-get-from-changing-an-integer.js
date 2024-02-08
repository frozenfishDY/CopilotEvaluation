/**https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/ */
//You are given an integer num. You will apply the following steps exactly two times:
//	Pick a digit x (0 <= x <= 9).
//	Pick another digit y (0 <= y <= 9). The digit y can be equal to x.
//	Replace all the occurrences of x in the decimal representation of num by y.
//	The new integer cannot have any leading zeros, also the new integer cannot be 0.
//Let a and b be the results of applying the operations to num the first and second times, respectively.
//Return the max difference between a and b.
// 
//Example 1:
//Input: num = 555
//Output: 888
//Explanation: The first time pick x = 5 and y = 9 and store the new integer in a.
//The second time pick x = 5 and y = 1 and store the new integer in b.
//We have now a = 999 and b = 111 and max difference = 888
//Example 2:
//Input: num = 9
//Output: 8
//Explanation: The first time pick x = 9 and y = 9 and store the new integer in a.
//The second time pick x = 9 and y = 1 and store the new integer in b.
//We have now a = 9 and b = 1 and max difference = 8
// 
//Constraints:
//	1 <= num <= 108
/**
 * @param {number} num
 * @return {number}
 */
var maxDiff = function(num) {
    let max = 0;
    let min = 0;
    let numArr = num.toString().split('');
    if (numArr[0] === '1') {
        let i = 1;
        while (numArr[i] === '1' || numArr[i] === '0') {
            i++;
        }
        max = parseInt(numArr.join('').replace(new RegExp(numArr[i], 'g'), '9'));
    } else {
        max = parseInt(numArr.join('').replace(new RegExp(numArr[0], 'g'), '9'));
    }
    if (numArr[0] === '9') {
        let i = 1;
        while (numArr[i] === '9') {
            i++;
        }
        min = parseInt(numArr.join('').replace(new RegExp(numArr[i], 'g'), '1'));
    } else {
        min = parseInt(numArr.join('').replace(new RegExp(numArr[0], 'g'), '1'));
    }
    return max - min;
};