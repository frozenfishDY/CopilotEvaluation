/**https://leetcode.com/problems/sequential-digits/ */
//An integer has sequential digits if and only if each digit in the number is one more than the previous digit.
//Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.


/**
 * @param {number} low
 * @param {number} high
 * @return {number[]}
 */
var sequentialDigits = function(low, high) {
    let result = [];
    let queue = [];
    for(let i = 1; i <= 9; i++){
        queue.push(i);
    }
    while(queue.length > 0){
        let num = queue.shift();
        if(num >= low && num <= high){
            result.push(num);
        }
        if(num > high){
            break;
        }
        let lastDigit = num % 10;
        if(lastDigit < 9){
            let nextNum = num * 10 + lastDigit + 1;
            queue.push(nextNum);
        }
    }
    return result;
    
};

    