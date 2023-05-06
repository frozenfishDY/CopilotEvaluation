/**https://leetcode.com/problems/graph-connectivity-with-threshold/ */
//We have n cities labeled from 1 to n. Two different cities with labels x and y are directly connected by a bidirectional road if and only if x and y share a common divisor strictly greater than some threshold. More formally, cities with labels x and y have a road between them if there exists an integer z such that all of the following are true:
//x % z == 0,
//y % z == 0, and
//z > threshold.
//Given the two integers, n and threshold, and an array of queries, you must determine for each queries[i] = [ai, bi] if cities ai and bi are connected directly or indirectly. (i.e. there is some path between them).
//Return an array answer, where answer.length == queries.length and answer[i] is true if for the ith query, there is a path between ai and bi, or answer[i] is false if there is no path.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* areConnected(int n, int threshold, int** queries, int queriesSize, int* queriesColSize, int* returnSize){
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

    