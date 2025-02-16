/**https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/ */
//You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.
//Return the maximum possible length of s.
//A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
// 
//Example 1:
//Input: arr = ["un","iq","ue"]
//Output: 4
//Explanation: All the valid concatenations are:
//- ""
//- "un"
//- "iq"
//- "ue"
//- "uniq" ("un" + "iq")
//- "ique" ("iq" + "ue")
//Maximum length is 4.
//Example 2:
//Input: arr = ["cha","r","act","ers"]
//Output: 6
//Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").
//Example 3:
//Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
//Output: 26
//Explanation: The only string in arr has all 26 characters.
// 
//Constraints:
//	1 <= arr.length <= 16
//	1 <= arr[i].length <= 26
//	arr[i] contains only lowercase English letters.
int maxLength(char ** arr, int arrSize){
int res = 0;
    int *dp = (int *)malloc(sizeof(int) * (1 << arrSize));
    memset(dp, 0, sizeof(int) * (1 << arrSize));
    for (int i = 0; i < arrSize; ++i) {
        int mask = 0;
        int len = strlen(arr[i]);
        for (int j = 0; j < len; ++j) {
            mask |= (1 << (arr[i][j] - 'a'));
        }
        if (__builtin_popcount(mask) != len) {
            continue;
        }
        for (int j = (1 << arrSize) - 1; j >= 0; --j) {
            if ((mask & j) != 0) {
                continue;
            }
            dp[mask | j] = fmax(dp[mask | j], dp[j] + len);
        }
    }
    for (int i = 0; i < (1 << arrSize); ++i) {
        res = fmax(res, dp[i]);
    }
    return res;
}