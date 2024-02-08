/**https://leetcode.com/problems/minimum-height-trees/ */
//A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.
//Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).
//Return a list of all MHTs' root labels. You can return the answer in any order.
//The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findMinHeightTrees(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    int* result = (int*)malloc(sizeof(int) * n);
    int resultSize = 0;
    if(n == 1){
        result[resultSize++] = 0;
    }
    else{
        int* degree = (int*)malloc(sizeof(int) * n);
        memset(degree, 0, sizeof(int) * n);
        int** graph = (int**)malloc(sizeof(int*) * n);
        for(int i = 0; i < n; i++){
            graph[i] = (int*)malloc(sizeof(int) * n);
            memset(graph[i], 0, sizeof(int) * n);
        }
        for(int i = 0; i < edgesSize; i++){
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
            graph[edges[i][0]][edges[i][1]] = 1;
            graph[edges[i][1]][edges[i][0]] = 1;
        }
        int* queue = (int*)malloc(sizeof(int) * n);
        int queueSize = 0;
        for(int i = 0; i < n; i++){
            if(degree[i] == 1){
                queue[queueSize++] = i;
            }
        }
        while(queueSize > 0){
            int* newQueue = (int*)malloc(sizeof(int) * n);
            int newQueueSize = 0;
            for(int i = 0; i < queueSize; i++){
                int node = queue[i];
                result[resultSize++] = node;
                for(int j = 0; j < n; j++){
                    if(graph[node][j] == 1){
                        degree[j]--;
                        if(degree[j] == 1){
                            newQueue[newQueueSize++] = j;
                        }
                    }
                }
            }
            queue = newQueue;
            queueSize = newQueueSize;
        }
    }
    *returnSize = resultSize;
    return result;

}

    