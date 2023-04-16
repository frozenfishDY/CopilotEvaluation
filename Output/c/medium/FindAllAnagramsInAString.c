/**https://leetcode.com/problems/find-all-anagrams-in-a-string/ */
//Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
//An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findAnagrams(char * s, char * p, int* returnSize){
    int* result = (int*)malloc(sizeof(int) * 10000);
    *returnSize = 0;
    int* sCount = (int*)malloc(sizeof(int) * 26);
    int* pCount = (int*)malloc(sizeof(int) * 26);
    for(int i = 0; i < 26; i++){
        sCount[i] = 0;
        pCount[i] = 0;
    }
    int pLength = strlen(p);
    for(int i = 0; i < pLength; i++){
        pCount[p[i] - 'a']++;
    }
    int sLength = strlen(s);
    for(int i = 0; i < sLength; i++){
        sCount[s[i] - 'a']++;
        if(i >= pLength){
            sCount[s[i - pLength] - 'a']--;
        }
        int j = 0;
        for(j = 0; j < 26; j++){
            if(sCount[j] != pCount[j]){
                break;
            }
        }
        if(j == 26){
            result[*returnSize] = i - pLength + 1;
            (*returnSize)++;
        }
    }
    return result;

}

    