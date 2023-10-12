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
char * fractionToDecimal(int numerator, int denominator){
if (numerator == 0) {
        return "0";
    }
    char *res = (char *)malloc(sizeof(char) * 10000);
    int index = 0;
    long long a = labs(numerator);
    long long b = labs(denominator);
    if ((numerator > 0) ^ (denominator > 0)) {
        res[index++] = '-';
    }
    res[index++] = a / b + '0';
    long long c = a % b;
    if (c == 0) {
        res[index] = '\0';
        return res;
    }
    res[index++] = '.';
    int *map = (int *)malloc(sizeof(int) * 10000);
    memset(map, 0, sizeof(int) * 10000);
    while (c != 0) {
        if (map[c] != 0) {
            res[map[c]] = '(';
            res[index++] = ')';
            res[index] = '\0';
            return res;
        }
        map[c] = index;
        c *= 10;
        res[index++] = c / b + '0';
        c %= b;
    }
    res[index] = '\0';
    return res;
}