/**https://leetcode.com/problems/find-and-replace-pattern/ */
//Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.
//A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.
//Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findAndReplacePattern(char ** words, int wordsSize, char * pattern, int* returnSize){
    int* patternHash = (int*)malloc(sizeof(int) * 26);
    for(int i = 0; i < 26; i++){
        patternHash[i] = -1;
    }
    for(int i = 0; i < strlen(pattern); i++){
        patternHash[pattern[i] - 'a'] = i;
    }
    char** result = (char**)malloc(sizeof(char*) * wordsSize);
    *returnSize = 0;
    for(int i = 0; i < wordsSize; i++){
        int* wordHash = (int*)malloc(sizeof(int) * 26);
        for(int i = 0; i < 26; i++){
            wordHash[i] = -1;
        }
        for(int j = 0; j < strlen(words[i]); j++){
            wordHash[words[i][j] - 'a'] = j;
        }
        int match = 1;
        for(int j = 0; j < 26; j++){
            if(patternHash[j] != -1 && wordHash[j] != -1 && patternHash[j] != wordHash[j]){
                match = 0;
                break;
            }
        }
        if(match == 1){
            result[*returnSize] = words[i];
            (*returnSize)++;
        }
    }
    return result;

}

    