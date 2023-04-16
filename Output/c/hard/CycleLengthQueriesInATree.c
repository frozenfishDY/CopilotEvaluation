/**https://leetcode.com/problems/cycle-length-queries-in-a-tree/ */
//You are given an integer n. There is a complete binary tree with 2^(n - 1) nodes. The root of that tree is the node with the value 1, and every node with a value val in the range [1, 2n - 1 - 1] has two children where:
//The left node has the value 2 * val, and
//The right node has the value 2 * val + 1.
//You are also given a 2D integer array queries of length m, where queries[i] = [ai, bi]. For each query, solve the following problem:
//Add an edge between the nodes with values ai and bi.
//Find the length of the cycle in the graph.
//Remove the added edge between nodes with values ai and bi.
//Note that:
//A cycle is a path that starts and ends at the same node, and each edge in the path is visited only once.
//The length of a cycle is the number of edges visited in the cycle.
//There could be multiple edges between two nodes in the tree after adding the edge of the query.
//Return an array answer of length m where answer[i] is the answer to the ith query.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* cycleLengthQueries(int n, int** queries, int queriesSize, int* queriesColSize, int* returnSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*queriesSize);
    for(i=0;i<queriesSize;i++){
        arr[i] = 0;
    }
    int* arr2 = (int*)malloc(sizeof(int)*queriesSize);
    for(i=0;i<queriesSize;i++){
        arr2[i] = 0;
    }
    int* arr3 = (int*)malloc(sizeof(int)*queriesSize);
    for(i=0;i<queriesSize;i++){
        arr3[i] = 0;
    }
    int* arr4 = (int*)malloc(sizeof(int)*queriesSize);
    for(i=0;i<queriesSize;i++){
        arr4[i] = 0;
    }
    int* arr5 = (int*)malloc(sizeof(int)*queriesSize);
    for(i=0;i<queriesSize;i++){
        arr5[i] = 0;
    }
    int* arr6 = (int*)malloc(sizeof(int)*queriesSize);
    for(i=0;i<queriesSize;i++){
        arr6[i] = 0;
    }
    int* arr7 = (int*)malloc(sizeof(int)*queriesSize);
    for(i=0;i<queriesSize;i++){
        arr7[i] = 0;
    }
    int* arr8 = (int*)malloc(sizeof(int)*queriesSize);
    for(i=0;i<queriesSize;i++){
        arr8[i] = 0;
    }
    int* arr9 = (int*)malloc(sizeof(int)*queriesSize);
    for(i=0;i<queriesSize;i++){
        arr9[i] = 0;
    }
    int* arr10 = (int*)malloc(sizeof(int)*queriesSize);
    for(i=0;i<queriesSize;i++){
        arr10[i] = 0;
    }
    int* arr11 = (int*)malloc(sizeof(int)*queriesSize);
    for(i=0;i<queriesSize;i++){
        arr11[i] = 0;
    }
    int* arr12 = (int*)malloc(sizeof(int)*queriesSize);
    for(i=0;i<queriesSize;i++){
        arr12[i] = 0;
    }
    int* arr13 = (int*)malloc(sizeof(int)*queriesSize);
    for(i=0;i<queriesSize;i++){
        arr13[i] = 0;
    }

}

    