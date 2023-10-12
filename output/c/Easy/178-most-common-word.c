/**https://leetcode.com/problems/most-common-word/ */
//Given a string paragraph and a string array of the banned words banned, return the most frequent word that is not banned. It is guaranteed there is at least one word that is not banned, and that the answer is unique.
//The words in paragraph are case-insensitive and the answer should be returned in lowercase.
// 
//Example 1:
//Input: paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned = ["hit"]
//Output: "ball"
//Explanation: 
//"hit" occurs 3 times, but it is a banned word.
//"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
//Note that words in the paragraph are not case sensitive,
//that punctuation is ignored (even if adjacent to words, such as "ball,"), 
//and that "hit" isn't the answer even though it occurs more because it is banned.
//Example 2:
//Input: paragraph = "a.", banned = []
//Output: "a"
// 
//Constraints:
//	1 <= paragraph.length <= 1000
//	paragraph consists of English letters, space ' ', or one of the symbols: "!?',;.".
//	0 <= banned.length <= 100
//	1 <= banned[i].length <= 10
//	banned[i] consists of only lowercase English letters.
char * mostCommonWord(char * paragraph, char ** banned, int bannedSize){
char *res = NULL;
  int maxCount = 0;
  char *p = strtok(paragraph, "!?',;.");
  char *map[1000];
  int mapSize = 0;
  while(p != NULL) {
    map[mapSize++] = p;
    p = strtok(NULL, "!?',;.");
  }
  int count[mapSize];
  memset(count, 0, sizeof(count));
  for(int i = 0; i < mapSize; i++) {
    for(int j = 0; j < bannedSize; j++) {
      if(strcmp(map[i], banned[j]) == 0) {
        count[i] = -1;
        break;
      }
    }
    if(count[i] == -1) continue;
    count[i]++;
    if(count[i] > maxCount) {
      res = map[i];
      maxCount = count[i];
    }
  }
  return res;
}