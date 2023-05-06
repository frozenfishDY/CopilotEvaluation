/**https://leetcode.com/problems/smallest-value-of-the-rearranged-number/ */
//You are given an integer num. Rearrange the digits of num such that its value is minimized and it does not contain any leading zeros.
//Return the rearranged number with minimal value.
//Note that the sign of the number does not change after rearranging the digits.


/**
 * @param {number} num
 * @return {number}
 */
var smallestNumber = function(num) {
    let arr = [];
    while (num > 0) {
        let digit = num % 10;
        arr.push(digit);
        num = Math.floor(num / 10);
    }
    arr.sort((a, b) => a - b);
    let res = 0;
    for (let i = 0; i < arr.length; i++) {
        res = res * 10 + arr[i];
    }
    return res;
    
};

    