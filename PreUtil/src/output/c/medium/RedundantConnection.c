/**https://leetcode.com/problems/redundant-connection/ */
//In this problem, a tree is an undirected graph that is connected and has no cycles.
//You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.
//Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    int* parent = (int*)malloc(sizeof(int) * edgesSize);
    for(int i = 0; i < edgesSize; i++){
        parent[i] = i;
    }
    for(int i = 0; i < edgesSize; i++){
        int x = edges[i][0];
        int y = edges[i][1];
        while(parent[x] != x){
            x = parent[x];
        }
        while(parent[y] != y){
            y = parent[y];
        }
        if(x == y){
            *returnSize = 2;
            return edges[i];
        }else{
            parent[x] = y;
        }
    }
    *returnSize = 0;
    return NULL;

}

    