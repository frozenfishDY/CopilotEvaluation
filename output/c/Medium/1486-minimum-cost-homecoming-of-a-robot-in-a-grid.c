/**https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/ */
//There is an m x n grid, where (0, 0) is the top-left cell and (m - 1, n - 1) is the bottom-right cell. You are given an integer array startPos where startPos = [startrow, startcol] indicates that initially, a robot is at the cell (startrow, startcol). You are also given an integer array homePos where homePos = [homerow, homecol] indicates that its home is at the cell (homerow, homecol).
//The robot needs to go to its home. It can move one cell in four directions: left, right, up, or down, and it can not move outside the boundary. Every move incurs some cost. You are further given two 0-indexed integer arrays: rowCosts of length m and colCosts of length n.
//If the robot moves up or down into a cell whose row is r, then this move costs rowCosts[r].
//If the robot moves left or right into a cell whose column is c, then this move costs colCosts[c].
//Return the minimum total cost for this robot to return home.


int minCost(int* startPos, int startPosSize, int* homePos, int homePosSize, int* rowCosts, int rowCostsSize, int* colCosts, int colCostsSize){
    int i, j, k, l;
    int sum = 0;
    int x = startPos[0];
    int y = startPos[1];
    int x1 = homePos[0];
    int y1 = homePos[1];
    int max = 0;
    int index = 0;
    int* arr = malloc(rowCostsSize * sizeof(int));
    for(i = 0; i < rowCostsSize; i++){
        arr[i] = rowCosts[i];
    }
    for(i = 0; i < colCostsSize; i++){
        arr[i] = colCosts[i];
    }
    for(i = 0; i < rowCostsSize; i++){
        for(j = 0; j < colCostsSize; j++){
            if(arr[i] < arr[j]){
                if(arr[j] - arr[i] > max){
                    max = arr[j] - arr[i];
                    index = i;
                }
            }
        }
    }
    sum = sum - arr[index] + max;
    return sum;

}

    