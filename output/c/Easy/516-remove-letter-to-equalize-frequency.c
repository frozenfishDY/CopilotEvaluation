/**https://leetcode.com/problems/remove-letter-to-equalize-frequency/ */
//You are given a 0-indexed string word, consisting of lowercase English letters. You need to select one index and remove the letter at that index from word so that the frequency of every letter present in word is equal.
//Return true if it is possible to remove one letter so that the frequency of all letters in word are equal, and false otherwise.
//Note:
//	The frequency of a letter x is the number of times it occurs in the string.
//	You must remove exactly one letter and cannot chose to do nothing.
// 
//Example 1:
//Input: word = "abcc"
//Output: true
//Explanation: Select index 3 and delete it: word becomes "abc" and each character has a frequency of 1.
//Example 2:
//Input: word = "aazz"
//Output: false
//Explanation: We must delete a character, so either the frequency of "a" is 1 and the frequency of "z" is 2, or vice versa. It is impossible to make all present letters have equal frequency.
// 
//Constraints:
//	2 <= word.length <= 100
//	word consists of lowercase English letters only.
bool equalFrequency(char * word){
int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    int n = strlen(word);
    int *x = (int*)malloc(sizeof(int) * 26);
    memset(x, 0, sizeof(int) * 26);
    int *y = (int*)malloc(sizeof(int) * 26);
    memset(y, 0, sizeof(int) * 26);
    for (i = 0; i < n; i++) {
        x[word[i] - 'a']++;
    }
    for (i = 0; i < 26; i++) {
        if (x[i] == 0) {
            continue;
        }
        y[x[i] - 1]++;
    }
    for (i = 0; i < 26; i++) {
        if (y[i] == 0) {
            continue;
        }
        if (y[i] == 1) {
            a++;
        }
        if (y[i] == 2) {
            b++;
        }
        if (y[i] > 2) {
            c++;
        }
    }
    if (c > 0) {
        return false;
    }
    if (a == 0) {
        return true;
    }
    if (a > 1) {
        return false;
    }
    if (b == 0) {
        return true;
    }
    if (b > 1) {
        return false;
    }
    return true;
}