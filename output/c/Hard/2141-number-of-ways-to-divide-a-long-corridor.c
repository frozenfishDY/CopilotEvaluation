/**https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/ */
//Along a long library corridor, there is a line of seats and decorative plants. You are given a 0-indexed string corridor of length n consisting of letters 'S' and 'P' where each 'S' represents a seat and each 'P' represents a plant.
//One room divider has already been installed to the left of index 0, and another to the right of index n - 1. Additional room dividers can be installed. For each position between indices i - 1 and i (1 <= i <= n - 1), at most one divider can be installed.
//Divide the corridor into non-overlapping sections, where each section has exactly two seats with any number of plants. There may be multiple ways to perform the division. Two ways are different if there is a position with a room divider installed in the first way but not in the second way.
//Return the number of ways to divide the corridor. Since the answer may be very large, return it modulo 109 + 7. If there is no way, return 0.
// 
//Example 1:
//Input: corridor = "SSPPSPS"
//Output: 3
//Explanation: There are 3 different ways to divide the corridor.
//The black bars in the above image indicate the two room dividers already installed.
//Note that in each of the ways, each section has exactly two seats.
//Example 2:
//Input: corridor = "PPSPSP"
//Output: 1
//Explanation: There is only 1 way to divide the corridor, by not installing any additional dividers.
//Installing any would create some section that does not have exactly two seats.
//Example 3:
//Input: corridor = "S"
//Output: 0
//Explanation: There is no way to divide the corridor because there will always be a section that does not have exactly two seats.
// 
//Constraints:
//	n == corridor.length
//	1 <= n <= 105
//	corridor[i] is either 'S' or 'P'.
int numberOfWays(char * corridor){
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
        for (j = i, k = len2 - 1; j > 0; j /= 10) result[len + k--] = j % 10 + '0';
        for (j = i, k = len1 - 1; j > 0; j /= 10) result[len + k--] = j % 10 + '0';
        for (j = i, k = len1 - 1; j > 0; j /= 10) result[len + k--] = j % 10 + '0';
        len += len1;
        len += len2;
    }
    return result;
}