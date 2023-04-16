/**https://leetcode.com/problems/count-the-digits-that-divide-a-number/ */
//Given an integer num, return the number of digits in num that divide num.
//An integer val divides nums if nums % val == 0.


/**
 * @param {number} num
 * @return {number}
 */
var countDigits = function(num) {
    let count = 0;
    let str = num.toString();
    for(let i = 0; i < str.length; i++){
        let digit = parseInt(str[i]);
        if(digit != 0 && num % digit == 0){
            count++;
        }
    }
    return count;
    
};

    