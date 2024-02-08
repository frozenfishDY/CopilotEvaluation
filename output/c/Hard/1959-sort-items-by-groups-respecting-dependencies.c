/**https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/ */
//There are n items each belonging to zero or one of m groups where group[i] is the group that the i-th item belongs to and it's equal to -1 if the i-th item belongs to no group. The items and the groups are zero indexed. A group can have no item belonging to it.
//Return a sorted list of the items such that:
//The items that belong to the same group are next to each other in the sorted list.
//There are some relations between these items where beforeItems[i] is a list containing all the items that should come before the i-th item in the sorted array (to the left of the i-th item).
//Return any solution if there is more than one solution and return an empty list if there is no solution.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortItems(int n, int m, int* group, int groupSize, int** beforeItems, int beforeItemsSize, int* beforeItemsColSize, int* returnSize){
    int* ans = (int*)malloc(sizeof(int)*n);
    *returnSize = n;
    int i,j;
    int** graph = (int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++){
        graph[i] = (int*)malloc(sizeof(int)*n);
        for(j=0;j<n;j++){
            graph[i][j] = 0;
        }
    }
    int** graph2 = (int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++){
        graph2[i] = (int*)malloc(sizeof(int)*n);
        for(j=0;j<n;j++){
            graph2[i][j] = 0;
        }
    }
    int* indegree = (int*)malloc(sizeof(int)*n);
    int* indegree2 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        indegree[i] = 0;
        indegree2[i] = 0;
    }
    for(i=0;i<n;i++){
        for(j=0;j<beforeItemsColSize[i];j++){
            graph[beforeItems[i][j]][i] = 1;
            indegree[i]++;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<beforeItemsColSize[i];j++){
            if(group[beforeItems[i][j]] == group[i]){
                graph2[beforeItems[i][j]][i] = 1;
                indegree2[i]++;
            }
        }
    }
    int* visited = (int*)malloc(sizeof(int)*n);
    int* visited2 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        visited[i] = 0;
        visited2[i] = 0;
    }
    int* stack = (int*)malloc(sizeof(int)*n);
    int* stack2 = (int*)malloc(sizeof(int)*n);
    int top = -1;
    int top2 = -1;
    for(i=0;i<n;i++){
        if(indegree[i] == 0){
            stack[++top] = i;
        }
    }
    for(i=0;i<n;i++){
        if(indegree2[i] == 0){
            stack2[++top2] = i;
        }
    }
    int* group2 = ( int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        group2[i] = group[i];
    }
    int* group3 = ( int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        group3[i] = group[i];
    }
    int* group4 = ( int*)malloc(sizeof(int)*n);

}

    