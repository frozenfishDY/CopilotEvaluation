/**https://leetcode.com/problems/closest-divisors/ */
//Given an integer num, find the closest two integers in absolute difference whose product equals num + 1 or num + 2.
//Return the two integers in any order.


/**
 * @param {number} num
 * @return {number[]}
 */
var closestDivisors = function(num) {
    let result1 = findDivisors(num + 1);
    let result2 = findDivisors(num + 2);
    if(Math.abs(result1[0] - result1[1]) < Math.abs(result2[0] - result2[1])){
        return result1;
    }else{
        return result2;
    }
    
    
};

    