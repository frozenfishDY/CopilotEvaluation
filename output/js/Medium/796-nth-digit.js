/**https://leetcode.com/problems/nth-digit/ */
//Given an integer n, return the nth digit of the infinite integer sequence [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...].


/**
 * @param {number} n
 * @return {number}
 */
var findNthDigit = function(n) {
    let count = 9;
    let digits = 1;
    let start = 1;
    while(n > count){
        n -= count;
        digits++;
        start *= 10;
        count = 9 * start * digits;
    }
    let num = start + Math.floor((n - 1) / digits);
    let index = (n - 1) % digits;
    return parseInt(num.toString().charAt(index));    
};

    