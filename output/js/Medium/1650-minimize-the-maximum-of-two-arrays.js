/**https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/ */
//We have two arrays arr1 and arr2 which are initially empty. You need to add positive integers to them such that they satisfy all the following conditions:
//arr1 contains uniqueCnt1 distinct positive integers, each of which is not divisible by divisor1.
//arr2 contains uniqueCnt2 distinct positive integers, each of which is not divisible by divisor2.
//No integer is present in both arr1 and arr2.
//Given divisor1, divisor2, uniqueCnt1, and uniqueCnt2, return the minimum possible maximum integer that can be present in either array.


/**
 * @param {number} divisor1
 * @param {number} divisor2
 * @param {number} uniqueCnt1
 * @param {number} uniqueCnt2
 * @return {number}
 */
var minimizeSet = function(divisor1, divisor2, uniqueCnt1, uniqueCnt2) {
    let gcd = getGCD(divisor1, divisor2);
    let lcm = divisor1 * divisor2 / gcd;
    let max1 = divisor1 * uniqueCnt1;
    let max2 = divisor2 * uniqueCnt2;
    let max3 = lcm * Math.min(uniqueCnt1, uniqueCnt2);
    let result = Math.max(max1, max2, max3);
    return result;
    
    
};

    