/**https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/ */
//You are given an m x n binary grid grid where 1 represents land and 0 represents water. An island is a maximal 4-directionally (horizontal or vertical) connected group of 1's.
//The grid is said to be connected if we have exactly one island, otherwise is said disconnected.
//In one day, we are allowed to change any single land cell (1) into a water cell (0).
//Return the minimum number of days to disconnect the grid.


int minDays(int** grid, int gridSize, int* gridColSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*gridSize);
    for(i=0;i<gridSize;i++){
        arr[i] = 0;
    }
    int* arr2 = (int*)malloc(sizeof(int)*gridSize);
    for(i=0;i<gridSize;i++){
        arr2[i] = 0;
    }
    int* arr3 = (int*)malloc(sizeof(int)*gridSize);
    for(i=0;i<gridSize;i++){
        arr3[i] = 0;
    }
    int* arr4 = (int*)malloc(sizeof(int)*gridSize);
    for(i=0;i<gridSize;i++){
        arr4[i] = 0;
    }
    int* arr5 = (int*)malloc(sizeof(int)*gridSize);
    for(i=0;i<gridSize;i++){
        arr5[i] = 0;
    }
    int* arr6 = (int*)malloc(sizeof(int)*gridSize);
    for(i=0;i<gridSize;i++){
        arr6[i] = 0;
    }
    int* arr7 = (int*)malloc(sizeof(int)*gridSize);
    for(i=0;i<gridSize;i++){
        arr7[i] = 0;
    }
    int* arr8 = (int*)malloc(sizeof(int)*gridSize);
    for(i=0;i<gridSize;i++){
        arr8[i] = 0;
    }
    int* arr9 = (int*)malloc(sizeof(int)*gridSize);
    for(i=0;i<gridSize;i++){
        arr9[i] = 0;
    }
    int* arr10 = (int*)malloc(sizeof(int)*gridSize);
    for(i=0;i<gridSize;i++){
        arr10[i] = 0;
    }
    int* arr11 = (int*)malloc(sizeof(int)*gridSize);
    for(i=0;i<gridSize;i++){
        arr11[i] = 0;
    }
    int* arr12 = (int*)malloc(sizeof(int)*gridSize);
    for(i=0;i<gridSize;i++){
        arr12[i] = 0;
    }
    int* arr13 = (int*)malloc(sizeof(int)*gridSize);
    for(i=0;i<gridSize;i++){
        arr13[i] = 0;
    }

}

    