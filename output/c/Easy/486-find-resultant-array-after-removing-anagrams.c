/**https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/ */
//You are given a 0-indexed string array words, where words[i] consists of lowercase English letters.
//In one operation, select any index i such that 0 < i < words.length and words[i - 1] and words[i] are anagrams, and delete words[i] from words. Keep performing this operation as long as you can select an index that satisfies the conditions.
//Return words after performing all operations. It can be shown that selecting the indices for each operation in any arbitrary order will lead to the same result.
//An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase using all the original letters exactly once. For example, "dacb" is an anagram of "abdc".
// 
//Example 1:
//Input: words = ["abba","baba","bbaa","cd","cd"]
//Output: ["abba","cd"]
//Explanation:
//One of the ways we can obtain the resultant array is by using the following operations:
//- Since words[2] = "bbaa" and words[1] = "baba" are anagrams, we choose index 2 and delete words[2].
//  Now words = ["abba","baba","cd","cd"].
//- Since words[1] = "baba" and words[0] = "abba" are anagrams, we choose index 1 and delete words[1].
//  Now words = ["abba","cd","cd"].
//- Since words[2] = "cd" and words[1] = "cd" are anagrams, we choose index 2 and delete words[2].
//  Now words = ["abba","cd"].
//We can no longer perform any operations, so ["abba","cd"] is the final answer.
//Example 2:
//Input: words = ["a","b","c","d","e"]
//Output: ["a","b","c","d","e"]
//Explanation:
//No two adjacent strings in words are anagrams of each other, so no operations are performed.
// 
//Constraints:
//	1 <= words.length <= 100
//	1 <= words[i].length <= 10
//	words[i] consists of lowercase English letters.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** removeAnagrams(char ** words, int wordsSize, int* returnSize){
int *hash = (int*)calloc(26, sizeof(int));
    int i = 0, j = 0;
    for (; i < wordsSize; i++) {
        memset(hash, 0, 26 * sizeof(int));
        for (j = 0; j < strlen(words[i]); j++) {
            hash[words[i][j] - 'a']++;
        }
        for (j = i + 1; j < wordsSize; j++) {
            int k = 0;
            for (; k < strlen(words[j]); k++) {
                if (hash[words[j][k] - 'a'] > 0) {
                    hash[words[j][k] - 'a']--;
                } else {
                    break;
                }
            }
            if (k == strlen(words[j])) {
                words[j] = "";
            }
        }
    }
    int resSize = 0;
    char **res = (char**)calloc(wordsSize, sizeof(char*));
    for (i = 0; i < wordsSize; i++) {
        if (strlen(words[i]) > 0) {
            res[resSize++] = words[i];
        }
    }
    *returnSize = resSize;
    return res;
}