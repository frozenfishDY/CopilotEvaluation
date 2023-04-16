/**https://leetcode.com/problems/frog-position-after-t-seconds/ */
//Given an undirected tree consisting of n vertices numbered from 1 to n. A frog starts jumping from vertex 1. In one second, the frog jumps from its current vertex to another unvisited vertex if they are directly connected. The frog can not jump back to a visited vertex. In case the frog can jump to several vertices, it jumps randomly to one of them with the same probability. Otherwise, when the frog can not jump to any unvisited vertex, it jumps forever on the same vertex.
//The edges of the undirected tree are given in the array edges, where edges[i] = [ai, bi] means that exists an edge connecting the vertices ai and bi.
//Return the probability that after t seconds the frog is on the vertex target. Answers within 10-5 of the actual answer will be accepted.


double frogPosition(int n, int** edges, int edgesSize, int* edgesColSize, int t, int target){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr[i] = 0;
    }
    for(i=0;i<edgesSize;i++){
        arr[edges[i][0]-1]++;
        arr[edges[i][1]-1]++;
    }
    int* arr2 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr2[i] = 0;
    }
    for(i=0;i<edgesSize;i++){
        if(edges[i][0]==1){
            arr2[edges[i][1]-1] = 1;
        }
        if(edges[i][1]==1){
            arr2[edges[i][0]-1] = 1;
        }
    }
    int* arr3 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr3[i] = 0;
    }
    for(i=0;i<edgesSize;i++){
        if(arr2[edges[i][0]-1]==1){
            arr3[edges[i][1]-1] = 1;
        }
        if(arr2[edges[i][1]-1]==1){
            arr3[edges[i][0]-1] = 1;
        }
    }
    int* arr4 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr4[i] = 0;
    }
    for(i=0;i<edgesSize;i++){
        if(arr3[edges[i][0]-1]==1){
            arr4[edges[i][1]-1] = 1;
        }
        if(arr3[edges[i][1]-1]==1){
            arr4[edges[i][0]-1] = 1;
        }
    }
    int* arr5 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr5[i] = 0;
    }
    for(i=0;i<edgesSize;i++){
        if(arr4[edges[i][0]-1]==1){
            arr5[edges[i][1]-1] = 1;
        }
        if(arr4[edges[i][1]-1]==1){
            arr5[edges[i][0]-1] = 1;

}

    