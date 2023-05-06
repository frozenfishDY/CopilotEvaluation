/**https://leetcode.com/problems/add-strings/ */
//Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.
//You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.


/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var addStrings = function(num1, num2) {
    let result = "";
    let carry = 0;
    let i = num1.length - 1;
    let j = num2.length - 1;
    while(i >= 0 || j >= 0){
        let sum = carry;
        if(i >= 0){
            sum += parseInt(num1[i]);
            i--;
        }
        if(j >= 0){
            sum += parseInt(num2[j]);
            j--;
        }
        result = (sum%10) + result;
        carry = Math.floor(sum/10);
    }
    if(carry != 0){
        result = carry + result;
    }
    return result;
    
};

    