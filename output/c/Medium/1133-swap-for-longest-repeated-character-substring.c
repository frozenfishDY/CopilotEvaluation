/**https://leetcode.com/problems/swap-for-longest-repeated-character-substring/ */
//You are given a string text. You can swap two of the characters in the text.
//Return the length of the longest substring with repeated characters.
// 
//Example 1:
//Input: text = "ababa"
//Output: 3
//Explanation: We can swap the first 'b' with the last 'a', or the last 'b' with the first 'a'. Then, the longest repeated character substring is "aaa" with length 3.
//Example 2:
//Input: text = "aaabaaa"
//Output: 6
//Explanation: Swap 'b' with the last 'a' (or the first 'a'), and we get longest repeated character substring "aaaaaa" with length 6.
//Example 3:
//Input: text = "aaaaa"
//Output: 5
//Explanation: No need to swap, longest repeated character substring is "aaaaa" with length is 5.
// 
//Constraints:
//	1 <= text.length <= 2 * 104
//	text consist of lowercase English characters only.
int maxRepOpt1(char * text){
int *count = (int *)malloc(sizeof(int) * 26);
    memset(count, 0, sizeof(int) * 26);
    int **dp = (int **)malloc(sizeof(int *) * 26);
    for (int i = 0; i < 26; ++i) {
        dp[i] = (int *)malloc(sizeof(int) * 2);
        memset(dp[i], 0, sizeof(int) * 2);
    }
    int len = strlen(text);
    for (int i = 0; i < len; ++i) {
        ++count[text[i] - 'a'];
    }
    int res = 0;
    for (int i = 0; i < 26; ++i) {
        int cur = 0;
        dp[i][0] = dp[i][1] = 0;
        for (int j = 0; j < len; ++j) {
            if (text[j] == i + 'a') {
                ++cur;
            } else {
                dp[i][1] = dp[i][0];
                dp[i][0] = cur;
                cur = 0;
            }
            res = fmax(res, dp[i][0] + dp[i][1] + (count[i] > dp[i][0] + dp[i][1] ? 1 : 0));
        }
    }
    return res;
}