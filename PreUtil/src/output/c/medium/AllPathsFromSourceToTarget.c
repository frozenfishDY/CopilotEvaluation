/**https://leetcode.com/problems/all-paths-from-source-to-target/ */
//Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.
//The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** allPathsSourceTarget(int** graph, int graphSize, int* graphColSize, int* returnSize, int** returnColumnSizes){
    int** result = (int**)malloc(sizeof(int*) * 1001);
    for(int i = 0; i < 1001; i++){
        result[i] = (int*)malloc(sizeof(int) * 1001);
    }
    int resultSize = 0;
    int* path = (int*)malloc(sizeof(int) * 1001);
    int pathSize = 0;
    dfs(graph, graphSize, graphColSize, 0, path, pathSize, result, &resultSize);
    *returnSize = resultSize;
    *returnColumnSizes = (int*)malloc(sizeof(int) * resultSize);
    for(int i = 0; i < resultSize; i++){
        (*returnColumnSizes)[i] = graphColSize[i];
    }
    return result;

}

    