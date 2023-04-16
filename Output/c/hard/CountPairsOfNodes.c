/**https://leetcode.com/problems/count-pairs-of-nodes/ */
//You are given an undirected graph defined by an integer n, the number of nodes, and a 2D integer array edges, the edges in the graph, where edges[i] = [ui, vi] indicates that there is an undirected edge between ui and vi. You are also given an integer array queries.
//Let incident(a, b) be defined as the number of edges that are connected to either node a or b.
//The answer to the jth query is the number of pairs of nodes (a, b) that satisfy both of the following conditions:
//a < b
//incident(a, b) > queries[j]
//Return an array answers such that answers.length == queries.length and answers[j] is the answer of the jth query.
//Note that there can be multiple edges between the same two nodes.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countPairs(int n, int** edges, int edgesSize, int* edgesColSize, int* queries, int queriesSize, int* returnSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr[i] = 0;
    }
    int* arr2 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr2[i] = 0;
    }
    int* arr3 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr3[i] = 0;
    }
    int* arr4 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr4[i] = 0;
    }
    int* arr5 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr5[i] = 0;
    }
    int* arr6 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr6[i] = 0;
    }
    int* arr7 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr7[i] = 0;
    }
    int* arr8 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr8[i] = 0;
    }
    int* arr9 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr9[i] = 0;
    }
    int* arr10 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr10[i] = 0;
    }
    int* arr11 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr11[i] = 0;
    }
    int* arr12 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr12[i] = 0;
    }
    int* arr13 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr13[i] = 0;
    }
    int* arr14 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr14[i] = 0;
    }
    int* arr15

}

    