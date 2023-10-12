/**https://leetcode.com/problems/solve-the-equation/ */
//Solve a given equation and return the value of 'x' in the form of a string "x=#value". The equation contains only '+', '-' operation, the variable 'x' and its coefficient. You should return "No solution" if there is no solution for the equation, or "Infinite solutions" if there are infinite solutions for the equation.
//If there is exactly one solution for the equation, we ensure that the value of 'x' is an integer.
// 
//Example 1:
//Input: equation = "x+5-3+x=6+x-2"
//Output: "x=2"
//Example 2:
//Input: equation = "x=x"
//Output: "Infinite solutions"
//Example 3:
//Input: equation = "2x=x"
//Output: "x=0"
// 
//Constraints:
//	3 <= equation.length <= 1000
//	equation has exactly one '='.
//	equation consists of integers with an absolute value in the range [0, 100] without any leading zeros, and the variable 'x'.
/**
 * @param {string} equation
 * @return {string}
 */
var solveEquation = function(equation) {
    let [left, right] = equation.split('=');
    let [leftX, leftNum] = parse(left);
    let [rightX, rightNum] = parse(right);
    let x = leftX - rightX;
    let num = rightNum - leftNum;
    if (x === 0 && num === 0) {
        return 'Infinite solutions';
    } else if (x === 0 && num !== 0) {
        return 'No solution';
    } else {
        return 'x=' + num / x;
    }
};
function parse(str) {
    let x = 0;
    let num = 0;
    let sign = 1;
    let numStart = false;
    for (let i = 0; i < str.length; i++) {
        let c = str.charAt(i);
        if (c === 'x') {
            if (!numStart) {
                x += sign;
            } else {
                x += sign * parseInt(str.substring(numStart, i));
            }
            numStart = false;
        } else if (c === '+') {
            if (numStart) {
                num += sign * parseInt(str.substring(numStart, i));
            }
            sign = 1;
            numStart = false;
        } else if (c === '-') {
            if (numStart) {
                num += sign * parseInt(str.substring(numStart, i));
            }
            sign = -1;
            numStart = false;
        } else {
            if (!numStart) {
                numStart = i;
            }
        }
    }
    if (numStart) {
        num += sign * parseInt(str.substring(numStart));
    }
    return [x, num];
}