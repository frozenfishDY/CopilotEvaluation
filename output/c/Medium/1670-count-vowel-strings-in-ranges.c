/**https://leetcode.com/problems/count-vowel-strings-in-ranges/ */
//You are given a 0-indexed array of strings words and a 2D array of integers queries.
//Each query queries[i] = [li, ri] asks us to find the number of strings present in the range li to ri (both inclusive) of words that start and end with a vowel.
//Return an array ans of size queries.length, where ans[i] is the answer to the ith query.
//Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* vowelStrings(char ** words, int wordsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize){
    int* ans = (int*)calloc(queriesSize, sizeof(int));
    int* hash = (int*)calloc(wordsSize, sizeof(int));
    for(int i = 0; i < queriesSize; i++){
        int count = 0;
        for(int j = queries[i][0]; j <= queries[i][1]; j++){
            if(hash[j] == 0){
                if(words[j][0] == 'a' || words[j][0] == 'e' || words[j][0] == 'i' || words[j][0] == 'o' || words[j][0] == 'u'){
                    if(words[j][strlen(words[j]) - 1] == 'a' || words[j][strlen(words[j]) - 1] == 'e' || words[j][strlen(words[j]) - 1] == 'i' || words[j][strlen(words[j]) - 1] == 'o' || words[j][strlen(words[j]) - 1] == 'u'){
                        count++;
                        hash[j] = 1;
                    }
                }
            }
        }
        ans[i] = count;
    }
    *returnSize = queriesSize;
    return ans;

}

    