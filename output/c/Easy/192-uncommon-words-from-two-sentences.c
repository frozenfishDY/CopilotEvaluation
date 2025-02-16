/**https://leetcode.com/problems/uncommon-words-from-two-sentences/ */
//A sentence is a string of single-space separated words where each word consists only of lowercase letters.
//A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.
//Given two sentences s1 and s2, return a list of all the uncommon words. You may return the answer in any order.
// 
//Example 1:
//Input: s1 = "this apple is sweet", s2 = "this apple is sour"
//Output: ["sweet","sour"]
//Example 2:
//Input: s1 = "apple apple", s2 = "banana"
//Output: ["banana"]
// 
//Constraints:
//	1 <= s1.length, s2.length <= 200
//	s1 and s2 consist of lowercase English letters and spaces.
//	s1 and s2 do not have leading or trailing spaces.
//	All the words in s1 and s2 are separated by a single space.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** uncommonFromSentences(char * s1, char * s2, int* returnSize){
char *words[201];
  int wordsSize = 0;
  char *p = strtok(s1, " ");
  while(p) {
    words[wordsSize++] = p;
    p = strtok(NULL, " ");
  }
  p = strtok(s2, " ");
  while(p) {
    words[wordsSize++] = p;
    p = strtok(NULL, " ");
  }
  char **res = (char **)malloc(sizeof(char *) * 201);
  *returnSize = 0;
  for(int i = 0; i < wordsSize; i++) {
    int j = 0;
    for(; j < wordsSize; j++) {
      if(i == j) {
        continue;
      }
      if(strcmp(words[i], words[j]) == 0) {
        break;
      }
    }
    if(j == wordsSize) {
      res[(*returnSize)++] = words[i];
    }
  }
  return res;
}