/**https://leetcode.com/problems/queries-on-a-permutation-with-key/ */
//Given the array queries of positive integers between 1 and m, you have to process all queries[i] (from i=0 to i=queries.length-1) according to the following rules:
//In the beginning, you have the permutation P=[1,2,3,...,m].
//For the current i, find the position of queries[i] in the permutation P (indexing from 0) and then move this at the beginning of the permutation P. Notice that the position of queries[i] in P is the result for queries[i].
//Return an array containing the result for the given queries.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* processQueries(int* queries, int queriesSize, int m, int* returnSize){
    int i, j, k, l, m, n, count = 0, *result;
    int *P;
    P = (int*)malloc(m * sizeof(int));
    for(i = 0; i < m; i++){
        P[i] = i + 1;
    }
    result = (int*)malloc(queriesSize * sizeof(int));
    for(i = 0; i < queriesSize; i++){
        for(j = 0; j < m; j++){
            if(P[j] == queries[i]){
                result[i] = j;
                for(k = j; k > 0; k--){
                    P[k] = P[k - 1];
                }
                P[0] = queries[i];
                break;
            }
        }
    }
    *returnSize = queriesSize;
    return result;

}

    