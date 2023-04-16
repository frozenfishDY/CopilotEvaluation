/**https://leetcode.com/problems/prison-cells-after-n-days/ */
//There are 8 prison cells in a row and each cell is either occupied or vacant.
//Each day, whether the cell is occupied or vacant changes according to the following rules:
//If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
//Otherwise, it becomes vacant.
//Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.
//You are given an integer array cells where cells[i] == 1 if the ith cell is occupied and cells[i] == 0 if the ith cell is vacant, and you are given an integer n.
//Return the state of the prison after n days (i.e., n such changes described above).


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* prisonAfterNDays(int* cells, int cellsSize, int n, int* returnSize){
    int* result = (int*)malloc(sizeof(int) * cellsSize);
    *returnSize = cellsSize;
    int* temp = (int*)malloc(sizeof(int) * cellsSize);
    int* temp2 = (int*)malloc(sizeof(int) * cellsSize);
    int* temp3 = (int*)malloc(sizeof(int) * cellsSize);
    int* temp4 = (int*)malloc(sizeof(int) * cellsSize);
    int* temp5 = (int*)malloc(sizeof(int) * cellsSize);
    int* temp6 = (int*)malloc(sizeof(int) * cellsSize);
    int* temp7 = (int*)malloc(sizeof(int) * cellsSize);
    int* temp8 = (int*)malloc(sizeof(int) * cellsSize);
    int* temp9 = (int*)malloc(sizeof(int) * cellsSize);
    int* temp10 = (int*)malloc(sizeof(int) * cellsSize);
    int* temp11 = (int*)malloc(sizeof(int) * cellsSize);
    int* temp12 = (int*)malloc(sizeof(int) * cellsSize);
    int* temp13 = (int*)malloc(sizeof(int) * cellsSize);
    int* temp14 = (int*)malloc(sizeof(int) * cellsSize);
    int* temp15 = (int*)malloc(sizeof(int) * cellsSize);
    int* temp16 = (int*)malloc(sizeof(int) * cellsSize);
    int* temp17 = (int*)malloc(sizeof(int) * cellsSize);
    int* temp18 = (int*)malloc(sizeof(int) * cellsSize);
    int* temp19 = (int*)malloc(sizeof(int) * cellsSize);
    int* temp20 = (int*)malloc(sizeof(int) * cellsSize);
    int* temp21 = (int*)malloc(sizeof(int) * cellsSize);
    int* temp22 = (int*)malloc(sizeof(int) * cellsSize);
    int* temp23 = (int*)malloc(sizeof(int) * cellsSize);
    int* temp24 = (int*)malloc(sizeof(int) * cellsSize);
    int* temp25 = (int*)malloc(sizeof(int) * cellsSize);
    int* temp26 = (int*)malloc(sizeof(int) * cellsSize);
    int* temp27 = (int*)malloc(sizeof(int) * cellsSize);
    int* temp28 = (int*)malloc(sizeof(int) * cellsSize);

}

    