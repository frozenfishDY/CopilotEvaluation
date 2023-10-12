/**https://leetcode.com/problems/abbreviating-the-product-of-a-range/ */
//You are given two positive integers left and right with left <= right. Calculate the product of all integers in the inclusive range [left, right].
//Since the product may be very large, you will abbreviate it following these steps:
//	Count all trailing zeros in the product and remove them. Let us denote this count as C.
//	
//		For example, there are 3 trailing zeros in 1000, and there are 0 trailing zeros in 546.
//	
//	
//	Denote the remaining number of digits in the product as d. If d > 10, then express the product as <pre>...<suf> where <pre> denotes the first 5 digits of the product, and <suf> denotes the last 5 digits of the product after removing all trailing zeros. If d <= 10, we keep it unchanged.
//	
//		For example, we express 1234567654321 as 12345...54321, but 1234567 is represented as 1234567.
//	
//	
//	Finally, represent the product as a string "<pre>...<suf>eC".
//	
//		For example, 12345678987600000 will be represented as "12345...89876e5".
//	
//	
//Return a string denoting the abbreviated product of all integers in the inclusive range [left, right].
// 
//Example 1:
//Input: left = 1, right = 4
//Output: "24e0"
//Explanation: The product is 1 × 2 × 3 × 4 = 24.
//There are no trailing zeros, so 24 remains the same. The abbreviation will end with "e0".
//Since the number of digits is 2, which is less than 10, we do not have to abbreviate it further.
//Thus, the final representation is "24e0".
//Example 2:
//Input: left = 2, right = 11
//Output: "399168e2"
//Explanation: The product is 39916800.
//There are 2 trailing zeros, which we remove to get 399168. The abbreviation will end with "e2".
//The number of digits after removing the trailing zeros is 6, so we do not abbreviate it further.
//Hence, the abbreviated product is "399168e2".
//Example 3:
//Input: left = 371, right = 375
//Output: "7219856259e3"
//Explanation: The product is 7219856259000.
// 
//Constraints:
//	1 <= left <= right <= 104
char * abbreviateProduct(int left, int right){
int i, j, k, count, digits, length, len, len1, len2;
    char *result;
    for (i = left, count = 0; i <= right; i++) {
        for (j = i; j % 5 == 0; j /= 5) count++;
        for (j = i; j % 2 == 0; j /= 2) count++;
    }
    for (i = left, digits = 0; i <= right; i++) {
        for (j = i; j > 0; j /= 10) digits++;
    }
    length = 5 + digits - count;
    result = (char *)malloc((length + 1) * sizeof(char));
    result[length] = '\0';
    for (i = left, len = 0; i <= right; i++) {
        for (j = i; j % 5 == 0; j /= 5) count++;
        for (j = i; j % 2 == 0; j /= 2) count++;
        for (j = i, len1 = 0; j > 0; j /= 10) len1++;
        for (j = i, len2 = 0; j > 0; j /= 10) len2++;
        for (j = i, k = len2 - 1; j > 0; j /= 10) result[len + k--] = j % 10 + '0';
        len += len1;
    }
    for (i = length - 1; i >= 0; i--) {
        if (result[i] != '0') break;
        result[i] = '\0';
    }
    if (i >= 0 && result[i] == '.') result[i] = '\0';
    len = strlen(result);
    if (len > 10) {
        result[5] = '.';
        result[6] = '.';
        result[7] = '.';
        result[8] = '.';
        result[9] = '.';
        len = 10;
    }
    for (i = len - 1; i >= 0; i--) {
        if (result[i] != '0') break;
        result[i] = '\0';
    }
    if (i >= 0 && result[i] == '.') result[i] = '\0';
    len = strlen(result);
    result[len++] = 'e';
    result[len++] = count / 10 + '0';
    result[len++] = count % 10 + '0';
    result[len] = '\0';
    return result;
}