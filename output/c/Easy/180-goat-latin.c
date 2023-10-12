/**https://leetcode.com/problems/goat-latin/ */
//You are given a string sentence that consist of words separated by spaces. Each word consists of lowercase and uppercase letters only.
//We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.) The rules of Goat Latin are as follows:
//	If a word begins with a vowel ('a', 'e', 'i', 'o', or 'u'), append "ma" to the end of the word.
//	
//		For example, the word "apple" becomes "applema".
//	
//	
//	If a word begins with a consonant (i.e., not a vowel), remove the first letter and append it to the end, then add "ma".
//	
//		For example, the word "goat" becomes "oatgma".
//	
//	
//	Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
//	
//		For example, the first word gets "a" added to the end, the second word gets "aa" added to the end, and so on.
//	
//	
//Return the final sentence representing the conversion from sentence to Goat Latin.
// 
//Example 1:
//Input: sentence = "I speak Goat Latin"
//Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
//Example 2:
//Input: sentence = "The quick brown fox jumped over the lazy dog"
//Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
// 
//Constraints:
//	1 <= sentence.length <= 150
//	sentence consists of English letters and spaces.
//	sentence has no leading or trailing spaces.
//	All the words in sentence are separated by a single space.
char * toGoatLatin(char * sentence){
 char *words[101];
  int wordsSize = 0;
  char *p = strtok(sentence, " ");
  while(p) {
    words[wordsSize++] = p;
    p = strtok(NULL, " ");
  }
  char *res = (char *)malloc(sizeof(char) * 10001);
  res[0] = '\0';
  for(int i = 0; i < wordsSize; i++) {
    if(tolower(words[i][0]) == 'a' || tolower(words[i][0]) == 'e' || tolower(words[i][0]) == 'i' || tolower(words[i][0]) == 'o' || tolower(words[i][0]) == 'u') {
      strcat(res, words[i]);
    } else {
      strcat(res, words[i] + 1);
      strncat(res, words[i], 1);
    }
    strcat(res, "ma");
    for(int j = 0; j < i + 1; j++) {
      strcat(res, "a");
    }
    if(i != wordsSize - 1) {
      strcat(res, " ");
    }
  }
  return res;
}