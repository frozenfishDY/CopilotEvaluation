/**https://leetcode.com/problems/reverse-vowels-of-a-string/ */
//Given a string s, reverse only all the vowels in the string and return it.
//The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.
// 
//Example 1:
//Input: s = "hello"
//Output: "holle"
//Example 2:
//Input: s = "leetcode"
//Output: "leotcede"
// 
//Constraints:
//	1 <= s.length <= 3 * 105
//	s consist of printable ASCII characters.
char * reverseVowels(char * s){
    int i = 0, j = strlen(s) - 1;
  char temp;
  while(i < j) {
    while(i < j && !strchr("aeiouAEIOU", s[i])) {
      i++;
    }
    while(i < j && !strchr("aeiouAEIOU", s[j])) {
      j--;
    }
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    i++;
    j--;
  }
  return s;

}