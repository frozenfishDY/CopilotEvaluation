/**https://leetcode.com/problems/alternating-digit-sum/ */
//You are given a positive integer n. Each digit of n has a sign according to the following rules:
//The most significant digit is assigned a positive sign.
//Each other digit has an opposite sign to its adjacent digits.
//Return the sum of all digits with their corresponding sign.


/**
 * @param {number} n
 * @return {number}
 */
var alternateDigitSum = function(n) {
    let sum = 0;
    let isPositive = true;
    while(n > 0){
        let digit = n % 10;
        if(isPositive){
            sum += digit;
        }else{
            sum -= digit;
        }
        isPositive = !isPositive;
        n = Math.floor(n / 10);
    }
    return sum;
    
};

    