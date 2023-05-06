/**https://leetcode.com/problems/minimum-interval-to-include-each-query/ */
//You are given a 2D integer array intervals, where intervals[i] = [lefti, righti] describes the ith interval starting at lefti and ending at righti (inclusive). The size of an interval is defined as the number of integers it contains, or more formally righti - lefti + 1.
//You are also given an integer array queries. The answer to the jth query is the size of the smallest interval i such that lefti <= queries[j] <= righti. If no such interval exists, the answer is -1.
//Return an array containing the answers to the queries.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minInterval(int** intervals, int intervalsSize, int* intervalsColSize, int* queries, int queriesSize, int* returnSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*intervalsSize);
    for(i=0;i<intervalsSize;i++){
        arr[i] = 0;
    }
    int* arr2 = (int*)malloc(sizeof(int)*intervalsSize);
    for(i=0;i<intervalsSize;i++){
        arr2[i] = 0;
    }
    int* arr3 = (int*)malloc(sizeof(int)*intervalsSize);
    for(i=0;i<intervalsSize;i++){
        arr3[i] = 0;
    }
    int* arr4 = (int*)malloc(sizeof(int)*intervalsSize);
    for(i=0;i<intervalsSize;i++){
        arr4[i] = 0;
    }
    int* arr5 = (int*)malloc(sizeof(int)*intervalsSize);
    for(i=0;i<intervalsSize;i++){
        arr5[i] = 0;
    }
    int* arr6 = (int*)malloc(sizeof(int)*intervalsSize);
    for(i=0;i<intervalsSize;i++){
        arr6[i] = 0;
    }
    int* arr7 = (int*)malloc(sizeof(int)*intervalsSize);
    for(i=0;i<intervalsSize;i++){
        arr7[i] = 0;
    }
    int* arr8 = (int*)malloc(sizeof(int)*intervalsSize);
    for(i=0;i<intervalsSize;i++){
        arr8[i] = 0;
    }
    int* arr9 = (int*)malloc(sizeof(int)*intervalsSize);
    for(i=0;i<intervalsSize;i++){
        arr9[i] = 0;
    }
    int* arr10 = (int*)malloc(sizeof(int)*intervalsSize);
    for(i=0;i<intervalsSize;i++){
        arr10[i] = 0;
    }
    int* arr11 = (int*)malloc(sizeof(int)*intervalsSize);
    for(i=0;i<intervalsSize;i++){
        arr11[i] = 0;
    }
    int* arr12 = (int*)malloc(sizeof(int)*intervalsSize);
    for(i=0;i<intervalsSize;i++){
        arr12[i] = 0;
    }
    int* arr13 = (int*)malloc(sizeof(int)*intervalsSize);
    for(i=0;i<intervalsSize;i

}

    