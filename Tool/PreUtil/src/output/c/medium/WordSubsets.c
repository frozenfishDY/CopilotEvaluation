/**https://leetcode.com/problems/word-subsets/ */
//You are given two string arrays words1 and words2.
//A string b is a subset of string a if every letter in b occurs in a including multiplicity.
//For example, "wrr" is a subset of "warrior" but is not a subset of "world".
//A string a from words1 is universal if for every string b in words2, b is a subset of a.
//Return an array of all the universal strings in words1. You may return the answer in any order.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** wordSubsets(char ** words1, int words1Size, char ** words2, int words2Size, int* returnSize){
    int* count = (int*)malloc(sizeof(int) * 26);
    for(int i = 0; i < 26; i++){
        count[i] = 0;
    }
    for(int i = 0; i < words2Size; i++){
        int* temp = (int*)malloc(sizeof(int) * 26);
        for(int j = 0; j < 26; j++){
            temp[j] = 0;
        }
        int length = strlen(words2[i]);
        for(int j = 0; j < length; j++){
            temp[words2[i][j] - 'a']++;
        }
        for(int j = 0; j < 26; j++){
            if(temp[j] > count[j]){
                count[j] = temp[j];
            }
        }
    }
    char** result = (char**)malloc(sizeof(char*) * 10001);
    for(int i = 0; i < 10001; i++){
        result[i] = (char*)malloc(sizeof(char) * 11);
    }
    *returnSize = 0;
    for(int i = 0; i < words1Size; i++){
        int* temp = (int*)malloc(sizeof(int) * 26);
        for(int j = 0; j < 26; j++){
            temp[j] = 0;
        }
        int length = strlen(words1[i]);
        for(int j = 0; j < length; j++){
            temp[words1[i][j] - 'a']++;
        }
        int j = 0;
        for(j = 0; j < 26; j++){
            if(temp[j] < count[j]){
                break;
            }
        }
        if(j == 26){
            strcpy(result[*returnSize], words1[i]);
            (*returnSize)++;
        }
    }
    return result;

}

    