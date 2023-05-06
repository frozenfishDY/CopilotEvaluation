/**https://leetcode.com/problems/print-words-vertically/ */
//Given a string s. Return all the words vertically in the same order in which they appear in s.
//Words are returned as a list of strings, complete with spaces when is necessary. (Trailing spaces are not allowed).
//Each word would be put on only one column and that in one column there will be only one word.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** printVertically(char * s, int* returnSize){
    int size = strlen(s);
    int wordCount = 0;
    int wordSize = 0;
    int maxWordSize = 0;
    for(int i = 0; i < size; i++){
        if(s[i] == ' '){
            wordCount++;
            if(wordSize > maxWordSize){
                maxWordSize = wordSize;
            }
            wordSize = 0;
        }
        else{
            wordSize++;
        }
    }
    wordCount++;
    if(wordSize > maxWordSize){
        maxWordSize = wordSize;
    }
    char** result = malloc(sizeof(char*) * maxWordSize);
    for(int i = 0; i < maxWordSize; i++){
        result[i] = malloc(sizeof(char) * (wordCount + 1));
        memset(result[i], ' ', wordCount);
        result[i][wordCount] = '\0';
    }
    int wordIndex = 0;
    int charIndex = 0;
    for(int i = 0; i < size; i++){
        if(s[i] == ' '){
            wordIndex++;
            charIndex = 0;
        }
        else{
            result[charIndex++][wordIndex] = s[i];
        }
    }
    for(int i = 0; i < maxWordSize; i++){
        int j = wordCount - 1;
        while(result[i][j] == ' '){
            j--;
        }
        result[i][j + 1] = '\0';
    }
    *returnSize = maxWordSize;
    return result;

}

    