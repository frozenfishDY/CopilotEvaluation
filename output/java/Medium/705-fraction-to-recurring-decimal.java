/**https://leetcode.com/problems/fraction-to-recurring-decimal/ */
//Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
//If the fractional part is repeating, enclose the repeating part in parentheses.
//If multiple answers are possible, return any of them.
//It is guaranteed that the length of the answer string is less than 104 for all the given inputs.
// 
//Example 1:
//Input: numerator = 1, denominator = 2
//Output: "0.5"
//Example 2:
//Input: numerator = 2, denominator = 1
//Output: "2"
//Example 3:
//Input: numerator = 4, denominator = 333
//Output: "0.(012)"
// 
//Constraints:
//	-231 <= numerator, denominator <= 231 - 1
//	denominator != 0
class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        long n = numerator, d = denominator;
        if (n % d == 0)
            return String.valueOf(n / d);
        StringBuilder sb = new StringBuilder();
        if (n < 0 ^ d < 0)
            sb.append('-');
        n = Math.abs(n);
        d = Math.abs(d);
        sb.append(n / d).append('.');
        n %= d;
        Map<Long, Integer> map = new HashMap<>();
        while (n > 0) {
            map.put(n, sb.length());
            n *= 10;
            sb.append(n / d);
            n %= d;
            if (map.containsKey(n)) {
                int index = map.get(n);
                sb.insert(index, '(');
                sb.append(')');
                break;
            }
        }
        return sb.toString();
    }
}