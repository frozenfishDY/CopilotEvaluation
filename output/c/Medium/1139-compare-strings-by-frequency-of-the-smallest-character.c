/**https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/ */
//Let the function f(s) be the frequency of the lexicographically smallest character in a non-empty string s. For example, if s = "dcce" then f(s) = 2 because the lexicographically smallest character is 'c', which has a frequency of 2.
//You are given an array of strings words and another array of query strings queries. For each query queries[i], count the number of words in words such that f(queries[i]) < f(W) for each W in words.
//Return an integer array answer, where each answer[i] is the answer to the ith query.
// 
//Example 1:
//Input: queries = ["cbd"], words = ["zaaaz"]
//Output: [1]
//Explanation: On the first query we have f("cbd") = 1, f("zaaaz") = 3 so f("cbd") < f("zaaaz").
//Example 2:
//Input: queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
//Output: [1,2]
//Explanation: On the first query only f("bbb") < f("aaaa"). On the second query both f("aaa") and f("aaaa") are both > f("cc").
// 
//Constraints:
//	1 <= queries.length <= 2000
//	1 <= words.length <= 2000
//	1 <= queries[i].length, words[i].length <= 10
//	queries[i][j], words[i][j] consist of lowercase English letters.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numSmallerByFrequency(char ** queries, int queriesSize, char ** words, int wordsSize, int* returnSize){
  int *res = (int *)malloc(sizeof(int) * queriesSize);
    int *count = (int *)malloc(sizeof(int) * wordsSize);
    for (int i = 0; i < wordsSize; ++i) {
        count[i] = 0;
        char min = 'z';
        for (int j = 0; j < strlen(words[i]); ++j) {
            if (words[i][j] < min) {
                min = words[i][j];
                count[i] = 1;
            } else if (words[i][j] == min) {
                ++count[i];
            }
        }
    }
    for (int i = 0; i < queriesSize; ++i) {
        res[i] = 0;
        char min = 'z';
        int cnt = 0;
        for (int j = 0; j < strlen(queries[i]); ++j) {
            if (queries[i][j] < min) {
                min = queries[i][j];
                cnt = 1;
            } else if (queries[i][j] == min) {
                ++cnt;
            }
        }
        for (int j = 0; j < wordsSize; ++j) {
            if (cnt < count[j]) {
                ++res[i];
            }
        }
    }
    *returnSize = queriesSize;
    return res;
}