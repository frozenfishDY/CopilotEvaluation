/**https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/ */
//An undirected graph of n nodes is defined by edgeList, where edgeList[i] = [ui, vi, disi] denotes an edge between nodes ui and vi with distance disi. Note that there may be multiple edges between two nodes.
//Given an array queries, where queries[j] = [pj, qj, limitj], your task is to determine for each queries[j] whether there is a path between pj and qj such that each edge on the path has a distance strictly less than limitj .
//Return a boolean array answer, where answer.length == queries.length and the jth value of answer is true if there is a path for queries[j] is true, and false otherwise.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* distanceLimitedPathsExist(int n, int** edgeList, int edgeListSize, int* edgeListColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*queriesSize);
    for(i=0;i<queriesSize;i++){
        arr[i] = 0;
    }
    for(i=1;i<queriesSize;i++){
        for(j=0;j<i;j++){
            arr[i] = (arr[i] * (2*(i-j)+1)) % 1000000007;
        }
    }
    int sum = 0;
    for(i=0;i<queriesSize;i++){
        sum = (sum + arr[i]) % 1000000007;
    }
    return arr;

}

    