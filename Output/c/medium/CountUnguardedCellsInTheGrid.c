/**https://leetcode.com/problems/count-unguarded-cells-in-the-grid/ */
//You are given two integers m and n representing a 0-indexed m x n grid. You are also given two 2D integer arrays guards and walls where guards[i] = [rowi, coli] and walls[j] = [rowj, colj] represent the positions of the ith guard and jth wall respectively.
//A guard can see every cell in the four cardinal directions (north, east, south, or west) starting from their position unless obstructed by a wall or another guard. A cell is guarded if there is at least one guard that can see it.
//Return the number of unoccupied cells that are not guarded.


int countUnguarded(int m, int n, int** guards, int guardsSize, int* guardsColSize, int** walls, int wallsSize, int* wallsColSize){
    int i, j, k, l, m, n, count = 0;
    int arr[100000] = {0};
    for(i = 0; i < guardsSize; i++){
        for(j = 0; j < 100000; j++){
            if(circles[i][0] + j * circles[i][2] < 100000){
                arr[circles[i][0] + j * circles[i][2]] = 1;
            }
        }
    }
    for(i = 0; i < 100000; i++){
        if(arr[i] == 1){
            count++;
        }
    }
    return count;

}

    