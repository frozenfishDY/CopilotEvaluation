/**https://leetcode.com/problems/check-if-the-sentence-is-pangram/ */
//A pangram is a sentence where every letter of the English alphabet appears at least once.
//Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.
// 
//Example 1:
//Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
//Output: true
//Explanation: sentence contains at least one of every letter of the English alphabet.
//Example 2:
//Input: sentence = "leetcode"
//Output: false
// 
//Constraints:
//	1 <= sentence.length <= 1000
//	sentence consists of lowercase English letters.
bool checkIfPangram(char * sentence){
int i = 0, j = 0, k = 0, l = 0, max = 0, cnt = 0, len = strlen(sentence);
    int *p = (int *)calloc(26, sizeof(int));
    for(i = 0; i < len; i++){
        p[sentence[i] - 'a']++;
    }
    for(i = 0; i < 26; i++){
        if(p[i] == 0){
            return false;
        }
    }
    return true;
}