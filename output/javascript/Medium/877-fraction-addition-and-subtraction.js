/**https://leetcode.com/problems/fraction-addition-and-subtraction/ */
//Given a string expression representing an expression of fraction addition and subtraction, return the calculation result in string format.
//The final result should be an irreducible fraction. If your final result is an integer, change it to the format of a fraction that has a denominator 1. So in this case, 2 should be converted to 2/1.
// 
//Example 1:
//Input: expression = "-1/2+1/2"
//Output: "0/1"
//Example 2:
//Input: expression = "-1/2+1/2+1/3"
//Output: "1/3"
//Example 3:
//Input: expression = "1/3-1/2"
//Output: "-1/6"
// 
//Constraints:
//	The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
//	Each fraction (input and output) has the format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
//	The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1, 10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
//	The number of given fractions will be in the range [1, 10].
//	The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.
/**
 * @param {string} expression
 * @return {string}
 */
var fractionAddition = function(expression) {
    let result = 0;
    let numerator = 0;
    let denominator = 1;
    let sign = 1;
    let i = 0;
    while (i < expression.length) {
        if (expression[i] === '-') {
            sign = -1;
            i++;
        } else if (expression[i] === '+') {
            sign = 1;
            i++;
        } else {
            let start = i;
            while (i < expression.length && expression[i] !== '+' && expression[i] !== '-') {
                i++;
            }
            let fraction = expression.substring(start, i);
            let [num, denom] = fraction.split('/');
            num = Number(num);
            denom = Number(denom);
            numerator = numerator * denom + sign * num * denominator;
            denominator *= denom;
        }
    }
    if (numerator === 0) {
        return '0/1';
    }
    let gcd = GCD(Math.abs(numerator), denominator);
    return `${numerator / gcd}/${denominator / gcd}`;
};
function GCD(a, b) {
    if (a === 0) {
        return b;
    }
    return GCD(b % a, a);
}