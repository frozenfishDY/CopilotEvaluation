/**https://leetcode.com/problems/occurrences-after-bigram/ */
//Given two strings first and second, consider occurrences in some text of the form "first second third", where second comes immediately after first, and third comes immediately after second.
//Return an array of all the words third for each occurrence of "first second third".
// 
//Example 1:
//Input: text = "alice is a good girl she is a good student", first = "a", second = "good"
//Output: ["girl","student"]
//Example 2:
//Input: text = "we will we will rock you", first = "we", second = "will"
//Output: ["we","rock"]
// 
//Constraints:
//	1 <= text.length <= 1000
//	text consists of lowercase English letters and spaces.
//	All the words in text a separated by a single space.
//	1 <= first.length, second.length <= 10
//	first and second consist of lowercase English letters.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findOcurrences(char * text, char * first, char * second, int* returnSize){
char **res = (char **)malloc(sizeof(char *) * 1000);
  *returnSize = 0;
  char *p = strtok(text, " ");
  char *last = NULL;
  char *lastlast = NULL;
  while(p) {
    if(lastlast != NULL && last != NULL && strcmp(lastlast, first) == 0 && strcmp(last, second) == 0) {
      res[(*returnSize)++] = p;
    }
    lastlast = last;
    last = p;
    p = strtok(NULL, " ");
  }
  return res;
}