/**https://leetcode.com/problems/minimum-degree-of-a-connected-trio-in-a-graph/ */
//You are given an undirected graph. You are given an integer n which is the number of nodes in the graph and an array edges, where each edges[i] = [ui, vi] indicates that there is an undirected edge between ui and vi.
//A connected trio is a set of three nodes where there is an edge between every pair of them.
//The degree of a connected trio is the number of edges where one endpoint is in the trio, and the other is not.
//Return the minimum degree of a connected trio in the graph, or -1 if the graph has no connected trios.


int minTrioDegree(int n, int** edges, int edgesSize, int* edgesColSize){
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
    for(i=0;i<edgesSize;i++){
        arr[edges[i][0]-1]++;
        arr[edges[i][1]-1]++;
        arr2[edges[i][0]-1]++;
        arr3[edges[i][1]-1]++;
    }
    int min = 100000;
    for(i=0;i<edgesSize;i++){
        if(arr[edges[i][0]-1] >= 2 && arr[edges[i][1]-1] >= 2){
            if(arr2[edges[i][0]-1] + arr3[edges[i][1]-1] - 2 < min){
                min = arr2[edges[i][0]-1] + arr3[edges[i][1]-1] - 2;
            }
        }
    }
    if(min == 100000){
        return -1;
    }
    return min;

}

    