/**https://leetcode.com/problems/last-day-where-you-can-still-cross/ */
//There is a 1-based binary matrix where 0 represents land and 1 represents water. You are given integers row and col representing the number of rows and columns in the matrix, respectively.
//Initially on day 0, the entire matrix is land. However, each day a new cell becomes flooded with water. You are given a 1-based 2D array cells, where cells[i] = [ri, ci] represents that on the ith day, the cell on the rith row and cith column (1-based coordinates) will be covered with water (i.e., changed to 1).
//You want to find the last day that it is possible to walk from the top to the bottom by only walking on land cells. You can start from any cell in the top row and end at any cell in the bottom row. You can only travel in the four cardinal directions (left, right, up, and down).
//Return the last day where it is possible to walk from the top to the bottom by only walking on land cells.


int latestDayToCross(int row, int col, int** cells, int cellsSize, int* cellsColSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*col);
    for(i=0;i<col;i++){
        arr[i] = 0;
    }
    arr[0] = 1;
    for(i=1;i<row;i++){
        for(j=0;j<col;j++){
            arr[j] = 0;
            if(j>0){
                arr[j] = (arr[j] + arr[j-1])%1000000007;
            }
            if(j<col-1){
                arr[j] = (arr[j] + arr[j+1])%1000000007;
            }
        }
    }
    return arr[col-1];

}

    