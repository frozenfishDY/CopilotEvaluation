/**https://leetcode.com/problems/relative-ranks/ */
//You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.
//The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines their rank:
//The 1st place athlete's rank is "Gold Medal".
//The 2nd place athlete's rank is "Silver Medal".
//The 3rd place athlete's rank is "Bronze Medal".
//For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").
//Return an array answer of size n where answer[i] is the rank of the ith athlete.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findRelativeRanks(int* score, int scoreSize, int* returnSize){
    int* sorted = (int*)malloc(scoreSize * sizeof(int));
    for(int i = 0; i < scoreSize; i++){
        sorted[i] = score[i];
    }
    qsort(sorted, scoreSize, sizeof(int), cmpfunc);
    char** ans = (char**)malloc(scoreSize * sizeof(char*));
    *returnSize = scoreSize;
    for(int i = 0; i < scoreSize; i++){
        int j = 0;
        while(score[i] != sorted[j]){
            j++;
        }
        if(j == 0){
            ans[i] = (char*)malloc(10 * sizeof(char));
            strcpy(ans[i], "Gold Medal");
        }else if(j == 1){
            ans[i] = (char*)malloc(12 * sizeof(char));
            strcpy(ans[i], "Silver Medal");
        }else if(j == 2){
            ans[i] = (char*)malloc(12 * sizeof(char));
            strcpy(ans[i], "Bronze Medal");
        }else{
            ans[i] = (char*)malloc(10 * sizeof(char));
            sprintf(ans[i], "%d", j + 1);
        }
    }
    return ans;


}

    