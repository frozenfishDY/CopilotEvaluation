/**https://leetcode.com/problems/find-common-characters/ */
//Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.
// 
//Example 1:
//Input: words = ["bella","label","roller"]
//Output: ["e","l","l"]
//Example 2:
//Input: words = ["cool","lock","cook"]
//Output: ["c","o"]
// 
//Constraints:
//	1 <= words.length <= 100
//	1 <= words[i].length <= 100
//	words[i] consists of lowercase English letters.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** commonChars(char ** words, int wordsSize, int* returnSize){
int charCount[26];
    memset(charCount, 0x7f, sizeof(charCount));
    for(int i = 0; i < wordsSize; i++) {
        int tmp[26] = {0};
        for(int j = 0; words[i][j]; j++) {
            tmp[words[i][j] - 'a']++;
        }
        for(int j = 0; j < 26; j++) {
            charCount[j] = fmin(charCount[j], tmp[j]);
        }
    }
    char **res = (char **)malloc(sizeof(char *) * 101);
    *returnSize = 0;
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < charCount[i]; j++) {
            res[(*returnSize)] = (char *)malloc(2);
            res[(*returnSize)][0] = 'a' + i;
            res[(*returnSize)++][1] = '\0';
        }
    }
    return res;
}