/**https://leetcode.com/problems/numbers-with-repeated-digits/ */
//Given an integer n, return the number of positive integers in the range [1, n] that have at least one repeated digit.


/**
 * @param {number} n
 * @return {number}
 */
var numDupDigitsAtMostN = function(n) {
    let ans = 0;
    let digits = [];
    let num = n;
    while(num > 0){
        digits.push(num % 10);
        num = Math.floor(num / 10);
    }
    digits = digits.reverse();
    let len = digits.length;
    for(let i = 1; i < len; i++){
        ans += 9 * A(9, i - 1);
    }
    let seen = new Set();
    for(let i = 0; i < len; i++){
        for(let j = (i == 0 ? 1 : 0); j < digits[i]; j++){
            if(!seen.has(j)){
                ans += A(9 - i, len - i - 1);
            }
        }
        if(seen.has(digits[i])){
            break;
        }
        seen.add(digits[i]);
        if(i == len - 1){
            ans++;
        }
    }
    return n - ans;
    
};

    