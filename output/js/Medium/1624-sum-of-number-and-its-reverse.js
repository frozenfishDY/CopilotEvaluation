/**https://leetcode.com/problems/sum-of-number-and-its-reverse/ */
//Given a non-negative integer num, return true if num can be expressed as the sum of any non-negative integer and its reverse, or false otherwise.


/**
 * @param {number} num
 * @return {boolean}
 */
var sumOfNumberAndReverse = function(num) {
    let reverse = 0;
    let temp = num;
    while (temp) {
        reverse = reverse * 10 + temp % 10;
        temp = Math.floor(temp / 10);
    }
    return num + reverse === num;
    
};

    