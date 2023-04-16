/**https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups/ */
//You are given a positive integer n representing the number of nodes in an undirected graph. The nodes are labeled from 1 to n.
//You are also given a 2D integer array edges, where edges[i] = [ai, bi] indicates that there is a bidirectional edge between nodes ai and bi. Notice that the given graph may be disconnected.
//Divide the nodes of the graph into m groups (1-indexed) such that:
//Each node in the graph belongs to exactly one group.
//For every pair of nodes in the graph that are connected by an edge [ai, bi], if ai belongs to the group with index x, and bi belongs to the group with index y, then |y - x| = 1.
//Return the maximum number of groups (i.e., maximum m) into which you can divide the nodes. Return -1 if it is impossible to group the nodes with the given conditions.


int magnificentSets(int n, int** edges, int edgesSize, int* edgesColSize){
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

    