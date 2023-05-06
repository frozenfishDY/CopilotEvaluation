/**https://leetcode.com/problems/redundant-connection-ii/ */
//In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.
//The given input is a directed graph that started as a rooted tree with n nodes (with distinct values from 1 to n), with one additional directed edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed.
//The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [ui, vi] that represents a directed edge connecting nodes ui and vi, where ui is a parent of child vi.
//Return an edge that can be removed so that the resulting graph is a rooted tree of n nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findRedundantDirectedConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    int* result = (int*)malloc(sizeof(int) * 2);
    int* parent = (int*)malloc(sizeof(int) * (edgesSize + 1));
    int* rank = (int*)malloc(sizeof(int) * (edgesSize + 1));
    int* queue = (int*)malloc(sizeof(int) * edgesSize);
    int head = 0, tail = 0;
    for(int i = 0; i <= edgesSize; i++){
        parent[i] = i;
        rank[i] = 1;
    }
    for(int i = 0; i < edgesSize; i++){
        if(parent[edges[i][1]] != edges[i][1]){
            result[0] = parent[edges[i][1]];
            result[1] = edges[i][1];
            edges[i][1] = 0;
        }else{
            parent[edges[i][1]] = edges[i][0];
        }
    }
    for(int i = 0; i < edgesSize; i++){
        if(edges[i][1] == 0) continue;
        int x = edges[i][0], y = edges[i][1];
        while(x != parent[x]) x = parent[x];
        while(y != parent[y]) y = parent[y];
        if(x == y){
            if(result[0] == 0){
                result[0] = edges[i][0];
                result[1] = edges[i][1];
            }
        }else{
            if(rank[x] < rank[y]){
                parent[x] = y;
                rank[y] += rank[x];
            }else{
                parent[y] = x;
                rank[x] += rank[y];
            }
        }
    }
    *returnSize = 2;
    return result;

}

    