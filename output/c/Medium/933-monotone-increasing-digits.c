/**https://leetcode.com/problems/monotone-increasing-digits/ */
//An integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.
//Given an integer n, return the largest number that is less than or equal to n with monotone increasing digits.
// 
//Example 1:
//Input: n = 10
//Output: 9
//Example 2:
//Input: n = 1234
//Output: 1234
//Example 3:
//Input: n = 332
//Output: 299
// 
//Constraints:
//	0 <= n <= 109
int monotoneIncreasingDigits(int n){
int digits[9] = {0};
    int digitsSize = 0;
    int temp = n;
    while (temp > 0) {
        digits[digitsSize] = temp % 10;
        digitsSize++;
        temp /= 10;
    }
    int result = 0;
    for (int i = digitsSize - 1; i >= 0; i--) {
        int temp = 0;
        for (int j = 0; j < i; j++) {
            temp = temp * 10 + digits[j];
        }
        int current = digits[i];
        for (int j = i + 1; j < digitsSize; j++) {
            current = current * 10 + 9;
        }
        for (int j = digitsSize - 1; j > i; j--) {
            current = current * 10 + digits[j];
        }
        if (current <= n) {
            result = temp * 10 + digits[i];
            break;
        }
    }
    return result;
}