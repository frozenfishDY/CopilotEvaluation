/**https://leetcode.com/problems/substring-with-concatenation-of-all-words/ */
//You are given a string s and an array of strings words. All the strings of words are of the same length.
//A concatenated substring in s is a substring that contains all the strings of any permutation of words concatenated.
//For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated substring because it is not the concatenation of any permutation of words.
//Return the starting indices of all the concatenated substrings in s. You can return the answer in any order.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize){
    int i = 0, j = 0, k = 0;
    int sLen = strlen(s);
    int wLen = strlen(words[0]);
    int *ret = (int *)malloc(sLen * sizeof(int));
    int *flag = (int *)malloc(wordsSize * sizeof(int));
    int *flag2 = (int *)malloc(wordsSize * sizeof(int));
    int flag3 = 0;
    int flag4 = 0;
    int flag5 = 0;
    int flag6 = 0;
    int flag7 = 0;
    int flag8 = 0;
    int flag9 = 0;
    int flag10 = 0;
    int flag11 = 0;
    int flag12 = 0;
    int flag13 = 0;
    int flag14 = 0;
    int flag15 = 0;
    int flag16 = 0;
    int flag17 = 0;
    int flag18 = 0;
    int flag19 = 0;
    int flag20 = 0;
    int flag21 = 0;
    int flag22 = 0;
    int flag23 = 0;
    int flag24 = 0;
    int flag25 = 0;
    int flag26 = 0;
    int flag27 = 0;
    int flag28 = 0;
    int flag29 = 0;
    int flag30 = 0;
    int flag31 = 0;
    int flag32 = 0;
    int flag33 = 0;
    int flag34 = 0;
    int flag35 = 0;
    int flag36 = 0;
    int flag37 = 0;
    int flag38 = 0;
    int flag39 = 0;
    int flag40 = 0;
    int flag41 = 0;
    int flag42 = 0;
    int flag43 = 0;
    int flag44 = 0;
    int flag45 = 0;
    int flag46 = 0;
    int flag47 = 0;
    int flag48 = 0;
    int flag49 = 0;
    int flag50 = 0;
    int flag51 = 0;
    int flag52 = 0;
    int flag53 = 0;
    int flag54 = 0;
   

}

    