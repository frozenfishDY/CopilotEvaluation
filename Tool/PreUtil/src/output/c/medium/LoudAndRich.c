/**https://leetcode.com/problems/loud-and-rich/ */
//There is a group of n people labeled from 0 to n - 1 where each person has a different amount of money and a different level of quietness.
//You are given an array richer where richer[i] = [ai, bi] indicates that ai has more money than bi and an integer array quiet where quiet[i] is the quietness of the ith person. All the given data in richer are logically correct (i.e., the data will not lead you to a situation where x is richer than y and y is richer than x at the same time).
//Return an integer array answer where answer[x] = y if y is the least quiet person (that is, the person y with the smallest value of quiet[y]) among all people who definitely have equal to or more money than the person x.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* loudAndRich(int** richer, int richerSize, int* richerColSize, int* quiet, int quietSize, int* returnSize){
    int* result = (int*)malloc(sizeof(int) * quietSize);
    *returnSize = quietSize;
    int* hash = (int*)malloc(sizeof(int) * quietSize);
    for(int i = 0; i < quietSize; i++){
        hash[i] = -1;
    }
    for(int i = 0; i < quietSize; i++){
        result[i] = i;
    }
    for(int i = 0; i < richerSize; i++){
        int x = richer[i][0];
        int y = richer[i][1];
        if(quiet[x] < quiet[result[y]]){
            result[y] = x;
        }
        hash[y] = x;
    }
    for(int i = 0; i < quietSize; i++){
        if(hash[i] == -1){
            continue;
        }
        int x = i;
        while(hash[x] != -1){
            if(quiet[result[x]] < quiet[result[hash[x]]]){
                result[hash[x]] = result[x];
            }
            x = hash[x];
        }
    }
    return result;

}

    