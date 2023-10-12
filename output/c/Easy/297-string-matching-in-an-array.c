/**https://leetcode.com/problems/string-matching-in-an-array/ */
//Given an array of string words, return all strings in words that is a substring of another word. You can return the answer in any order.
//A substring is a contiguous sequence of characters within a string
// 
//Example 1:
//Input: words = ["mass","as","hero","superhero"]
//Output: ["as","hero"]
//Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
//["hero","as"] is also a valid answer.
//Example 2:
//Input: words = ["leetcode","et","code"]
//Output: ["et","code"]
//Explanation: "et", "code" are substring of "leetcode".
//Example 3:
//Input: words = ["blue","green","bu"]
//Output: []
//Explanation: No string of words is substring of another string.
// 
//Constraints:
//	1 <= words.length <= 100
//	1 <= words[i].length <= 30
//	words[i] contains only lowercase English letters.
//	All the strings of words are unique.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** stringMatching(char ** words, int wordsSize, int* returnSize){
int i,j;
    *returnSize=0;
    char **returnWords=(char **)malloc(sizeof(char *)*wordsSize);
    for(i=0;i<wordsSize;i++){
        for(j=0;j<wordsSize;j++){
            if(i!=j){
                char *p=strstr(words[j],words[i]);
                if(p!=NULL){
                    returnWords[*returnSize]=words[i];
                    (*returnSize)++;
                    break;
                }
            }
        }
    }
    return returnWords;

}