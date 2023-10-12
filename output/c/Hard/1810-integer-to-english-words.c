/**https://leetcode.com/problems/integer-to-english-words/ */
//Convert a non-negative integer num to its English words representation.
// 
//Example 1:
//Input: num = 123
//Output: "One Hundred Twenty Three"
//Example 2:
//Input: num = 12345
//Output: "Twelve Thousand Three Hundred Forty Five"
//Example 3:
//Input: num = 1234567
//Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
// 
//Constraints:
//	0 <= num <= 231 - 1
char * numberToWords(int num){
if (num == 0) return "Zero";
    char *res = (char *)malloc(sizeof(char) * 1000);
    char *p = res;
    char *units[10] = {"", " Thousand", " Million", " Billion"};
    char *ones[20] = {"", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine", " Ten",
                     " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen"};
    char *tens[10] = {"", " Ten", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"};
    int unit = 0;
    while (num > 0) {
        int n = num % 1000;
        if (n > 0) {
            if (unit > 0) {
                p += sprintf(p, "%s", units[unit]);
            }
            if (n >= 100) {
                p += sprintf(p, "%s Hundred", ones[n / 100]);
            }
            if (n % 100 >= 20) {
                p += sprintf(p, "%s%s", tens[(n % 100) / 10], ones[n % 10]);
            } else {
                p += sprintf(p, "%s", ones[n % 100]);
            }
        }
        num /= 1000;
        unit++;
    }
    return res;

}