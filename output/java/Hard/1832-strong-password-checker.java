/**https://leetcode.com/problems/strong-password-checker/ */
//A password is considered strong if the below conditions are all met:
//	It has at least 6 characters and at most 20 characters.
//	It contains at least one lowercase letter, at least one uppercase letter, and at least one digit.
//	It does not contain three repeating characters in a row (i.e., "Baaabb0" is weak, but "Baaba0" is strong).
//Given a string password, return the minimum number of steps required to make password strong. if password is already strong, return 0.
//In one step, you can:
//	Insert one character to password,
//	Delete one character from password, or
//	Replace one character of password with another character.
// 
//Example 1:
//Input: password = "a"
//Output: 5
//Example 2:
//Input: password = "aA1"
//Output: 3
//Example 3:
//Input: password = "1337C0d3"
//Output: 0
// 
//Constraints:
//	1 <= password.length <= 50
//	password consists of letters, digits, dot '.' or exclamation mark '!'.
class Solution {
    public int strongPasswordChecker(String password) {
        int res = 0, a = 1, A = 1, d = 1;
        char[] p = password.toCharArray();
        int[] arr = new int[p.length];
        for (int i = 0; i < arr.length;) {
            if (Character.isLowerCase(p[i])) {
                a = 0;
            }
            if (Character.isUpperCase(p[i])) {
                A = 0;
            }
            if (Character.isDigit(p[i])) {
                d = 0;
            }
            int j = i;
            while (i < p.length && p[i] == p[j]) {
                i++;
            }
            arr[j] = i - j;
        }
        int total_missing = (a + A + d);
        if (arr.length < 6) {
            res += total_missing + Math.max(0, 6 - (arr.length + total_missing));
        } else {
            int over_len = Math.max(arr.length - 20, 0), left_over = 0;
            res += over_len;
            for (int k = 1; k < 3; k++) {
                for (int i = 0; i < arr.length && over_len > 0; i++) {
                    if (arr[i] < 3 || arr[i] % 3 != (k - 1)) {
                        continue;
                    }
                    arr[i] -= Math.min(over_len, k);
                    over_len -= k;
                }
            }
            for (int i = 0; i < arr.length; i++) {
                if (arr[i] >= 3 && over_len > 0) {
                    int need = arr[i] - 2;
                    arr[i] -= over_len;
                    over_len -= need;
                }
                if (arr[i] >= 3) {
                    left_over += arr[i] / 3;
                }
            }
            res += Math.max(total_missing, left_over);
        }
        return res;
    }
}