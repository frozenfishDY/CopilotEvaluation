/**https://leetcode.com/problems/minimize-xor/ */
//Given two positive integers num1 and num2, find the positive integer x such that:
//	x has the same number of set bits as num2, and
//	The value x XOR num1 is minimal.
//Note that XOR is the bitwise XOR operation.
//Return the integer x. The test cases are generated such that x is uniquely determined.
//The number of set bits of an integer is the number of 1's in its binary representation.
// 
//Example 1:
//Input: num1 = 3, num2 = 5
//Output: 3
//Explanation:
//The binary representations of num1 and num2 are 0011 and 0101, respectively.
//The integer 3 has the same number of set bits as num2, and the value 3 XOR 3 = 0 is minimal.
//Example 2:
//Input: num1 = 1, num2 = 12
//Output: 3
//Explanation:
//The binary representations of num1 and num2 are 0001 and 1100, respectively.
//The integer 3 has the same number of set bits as num2, and the value 3 XOR 1 = 2 is minimal.
// 
//Constraints:
//	1 <= num1, num2 <= 109
/**
 * @param {number} num1
 * @param {number} num2
 * @return {number}
 */
var minimizeXor = function(num1, num2) {
    let res = 0;
    for (let i = 31; i >= 0; i--) {
        let mask = 1 << i;
        let bit1 = num1 & mask;
        let bit2 = num2 & mask;
        if (bit1 && !bit2) {
            res |= mask;
        } else if (!bit1 && bit2) {
            res |= mask;
        }
    }
    return res;
};