/**https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/ */
//On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.
//A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.
//Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.


int removeStones(int** stones, int stonesSize, int* stonesColSize){
    int* visited = (int*)malloc(sizeof(int) * stonesSize);
    for(int i = 0; i < stonesSize; i++){
        visited[i] = 0;
    }
    int count = 0;
    for(int i = 0; i < stonesSize; i++){
        if(visited[i] == 0){
            count++;
            dfs(stones, stonesSize, stonesColSize, visited, i);
        }
    }
    return stonesSize - count;

}

    