/**https://leetcode.com/problems/concatenated-words/ */
//Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.
//A concatenated word is defined as a string that is comprised entirely of at least two shorter words (not necesssarily distinct) in the given array.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findAllConcatenatedWordsInADict(char ** words, int wordsSize, int* returnSize){
    char** result = (char**)malloc(sizeof(char*) * wordsSize);
    int* queue = (int*)malloc(sizeof(int) * wordsSize);
    int head = 0, tail = 0;
    for(int i = 0; i < wordsSize; i++){
        while(head < tail && words[queue[tail - 1]] < words[i]) tail--;
        queue[tail++] = i;
        if(i - queue[head] >= k) head++;
        if(i >= k - 1) result[i - k + 1] = words[queue[head]];
    }
    *returnSize = wordsSize - k + 1;
    return result;

}

    