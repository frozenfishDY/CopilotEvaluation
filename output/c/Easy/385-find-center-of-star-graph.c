/**https://leetcode.com/problems/find-center-of-star-graph/ */
//There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly n - 1 edges that connect the center node with every other node.
//You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi. Return the center of the given star graph.


int findCenter(int** edges, int edgesSize, int* edgesColSize){
    int i = 0;
    int j = 0;
    int result = 0;
    int count = 0;
    for(i = 0; i < edgesSize; i++){
        for(j = 0; j < edgesColSize[i]; j++){
            if(edges[i][j] == edges[i][j + 1]){
                result = edges[i][j];
            }
        }
    }
    return result;

}

    