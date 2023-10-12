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
int strongPasswordChecker(char * password){
int len = strlen(password);
    int lower = 1, upper = 1, digit = 1;
    int repeat = 0, one = 0, two = 0;
    int i = 0;
    while (i < len) {
        if (password[i] >= 'a' && password[i] <= 'z') lower = 0;
        if (password[i] >= 'A' && password[i] <= 'Z') upper = 0;
        if (password[i] >= '0' && password[i] <= '9') digit = 0;
        int j = i + 1;
        while (j < len && password[j] == password[i]) j++;
        repeat += (j - i) / 3;
        if ((j - i) % 3 == 1) one++;
        if ((j - i) % 3 == 2) two++;
        i = j;
    }
    int miss = lower + upper + digit;
    if (len < 6) return fmax(6 - len, miss);
    if (len <= 20) return fmax(repeat, miss);
    int del = len - 20;
    repeat -= fmin(del, one);
    repeat -= fmin(fmax(del - one, 0), two * 2) / 2;
    repeat -= fmax(del - one - 2 * two, 0) / 3;
    return del + fmax(repeat, miss);
}