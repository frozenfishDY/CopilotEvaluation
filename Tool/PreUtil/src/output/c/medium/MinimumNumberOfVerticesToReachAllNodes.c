/**https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/ */
//Given a directed acyclic graph, with n vertices numbered from 0 to n-1, and an array edges where edges[i] = [fromi, toi] represents a directed edge from node fromi to node toi.
//Find the smallest set of vertices from which all nodes in the graph are reachable. It's guaranteed that a unique solution exists.
//Notice that you can return the vertices in any order.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findSmallestSetOfVertices(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    int* arr = malloc(n * sizeof(int));
    int* visited = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        visited[i] = 0;
    }
    for(int i = 0; i < edgesSize; i++){
        visited[edges[i][1]] = 1;
    }
    int count = 0;
    for(int i = 0; i < n; i++){
        if(visited[i] == 0){
            arr[count++] = i;
        }
    }
    *returnSize = count;
    return arr;

}

    