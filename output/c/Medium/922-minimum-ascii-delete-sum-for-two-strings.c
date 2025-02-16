/**https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/ */
//Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.
// 
//Example 1:
//Input: s1 = "sea", s2 = "eat"
//Output: 231
//Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
//Deleting "t" from "eat" adds 116 to the sum.
//At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
//Example 2:
//Input: s1 = "delete", s2 = "leet"
//Output: 403
//Explanation: Deleting "dee" from "delete" to turn the string into "let",
//adds 100[d] + 101[e] + 101[e] to the sum.
//Deleting "e" from "leet" adds 101[e] to the sum.
//At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
//If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
// 
//Constraints:
//	1 <= s1.length, s2.length <= 1000
//	s1 and s2 consist of lowercase English letters.
int minimumDeleteSum(char * s1, char * s2){
int length1 = strlen(s1);
    int length2 = strlen(s2);
    int dp[length1 + 1][length2 + 1];
    dp[0][0] = 0;
    int sum = 0;
    for (int i = 1; i <= length1; i++) {
        sum += s1[i - 1];
        dp[i][0] = sum;
    }
    sum = 0;
    for (int i = 1; i <= length2; i++) {
        sum += s2[i - 1];
        dp[0][i] = sum;
    }
    for (int i = 1; i <= length1; i++) {
        for (int j = 1; j <= length2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                int temp1 = dp[i - 1][j] + s1[i - 1];
                int temp2 = dp[i][j - 1] + s2[j - 1];
                dp[i][j] = temp1 < temp2 ? temp1 : temp2;
            }
        }
    }
    return dp[length1][length2];
}