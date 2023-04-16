/**https://leetcode.com/problems/minimum-addition-to-make-integer-beautiful/ */
//You are given two positive integers n and target.
//An integer is considered beautiful if the sum of its digits is less than or equal to target.
//Return the minimum non-negative integer x such that n + x is beautiful. The input will be generated such that it is always possible to make n beautiful.


/**
 * @param {number} n
 * @param {number} target
 * @return {number}
 */
var makeIntegerBeautiful = function(n, target) {
    let sum = 0;
    let count = 0;
    let arr = [];
    while (n > 0) {
        let digit = n % 10;
        arr.push(digit);
        sum += digit;
        n = Math.floor(n / 10);
    }
    arr.reverse();
    let i = 0;
    while (sum > target) {
        let diff = sum - target;
        if (arr[i] > diff) {
            sum -= arr[i];
            arr[i] = diff;
            sum += arr[i];
            count += diff;
        }
        i++;
    }
    return count;
    
};

    