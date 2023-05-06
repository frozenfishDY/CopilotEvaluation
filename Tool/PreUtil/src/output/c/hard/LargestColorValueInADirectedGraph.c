/**https://leetcode.com/problems/largest-color-value-in-a-directed-graph/ */
//There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.
//You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.
//A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.
//Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.


int largestPathValue(char * colors, int** edges, int edgesSize, int* edgesColSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*edgesSize);
    for(i=0;i<edgesSize;i++){
        arr[i] = 0;
    }
    int* arr2 = (int*)malloc(sizeof(int)*edgesSize);
    for(i=0;i<edgesSize;i++){
        arr2[i] = 0;
    }
    int* arr3 = (int*)malloc(sizeof(int)*edgesSize);
    for(i=0;i<edgesSize;i++){
        arr3[i] = 0;
    }
    int* arr4 = (int*)malloc(sizeof(int)*edgesSize);
    for(i=0;i<edgesSize;i++){
        arr4[i] = 0;
    }
    int* arr5 = (int*)malloc(sizeof(int)*edgesSize);
    for(i=0;i<edgesSize;i++){
        arr5[i] = 0;
    }
    int* arr6 = (int*)malloc(sizeof(int)*edgesSize);
    for(i=0;i<edgesSize;i++){
        arr6[i] = 0;
    }
    int* arr7 = (int*)malloc(sizeof(int)*edgesSize);
    for(i=0;i<edgesSize;i++){
        arr7[i] = 0;
    }
    int* arr8 = (int*)malloc(sizeof(int)*edgesSize);
    for(i=0;i<edgesSize;i++){
        arr8[i] = 0;
    }
    int* arr9 = (int*)malloc(sizeof(int)*edgesSize);
    for(i=0;i<edgesSize;i++){
        arr9[i] = 0;
    }
    int* arr10 = (int*)malloc(sizeof(int)*edgesSize);
    for(i=0;i<edgesSize;i++){
        arr10[i] = 0;
    }
    int* arr11 = (int*)malloc(sizeof(int)*edgesSize);
    for(i=0;i<edgesSize;i++){
        arr11[i] = 0;
    }
    int* arr12 = (int*)malloc(sizeof(int)*edgesSize);
    for(i=0;i<edgesSize;i++){
        arr12[i] = 0;
    }
    int* arr13 = (int*)malloc(sizeof(int)*edgesSize);
    for(i=0;i<edgesSize;i++){
        arr13[i] = 0;
    }

}

    