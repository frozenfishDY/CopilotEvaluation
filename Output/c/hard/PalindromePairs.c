/**https://leetcode.com/problems/palindrome-pairs/ */
//You are given a 0-indexed array of unique strings words.
//A palindrome pair is a pair of integers (i, j) such that:
//0 <= i, j < words.length,
//i != j, and
//words[i] + words[j] (the concatenation of the two strings) is a palindrome.
//Return an array of all the palindrome pairs of words.


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** palindromePairs(char ** words, int wordsSize, int* returnSize, int** returnColumnSizes){
    int** result = (int**)malloc(sizeof(int*) * wordsSize * wordsSize);
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

    