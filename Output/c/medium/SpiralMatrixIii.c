/**https://leetcode.com/problems/spiral-matrix-iii/ */
//You start at the cell (rStart, cStart) of an rows x cols grid facing east. The northwest corner is at the first row and column in the grid, and the southeast corner is at the last row and column.
//You will walk in a clockwise spiral shape to visit every position in this grid. Whenever you move outside the grid's boundary, we continue our walk outside the grid (but may return to the grid boundary later.). Eventually, we reach all rows * cols spaces of the grid.
//Return an array of coordinates representing the positions of the grid in the order you visited them.


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** spiralMatrixIII(int rows, int cols, 
int rStart, int cStart, int* returnSize, 
int** returnColumnSizes){
    int** result = (int**)malloc(sizeof(int*) * rows * cols);
    *returnSize = rows * cols;
    *returnColumnSizes = (int*)malloc(sizeof(int) * rows * cols);
    for(int i = 0; i < rows * cols; i++){
        (*returnColumnSizes)[i] = 2;
    }
    int* x = (int*)malloc(sizeof(int) * rows * cols);
    int* y = (int*)malloc(sizeof(int) * rows * cols);
    int index = 0;
    int direction = 0;
    int length = 1;
    int count = 0;
    while(index < rows * cols){
        if(direction == 0){
            for(int i = 0; i < length; i++){
                if(rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols){
                    x[index] = rStart;
                    y[index] = cStart;
                    index++;
                }
                cStart++;
            }
            direction = 1;
            count++;
            if(count == 2){
                length++;
                count = 0;
            }
        }
        else if(direction == 1){
            for(int i = 0; i < length; i++){
                if(rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols){
                    x[index] = rStart;
                    y[index] = cStart;
                    index++;
                }
                rStart++;
            }
            direction = 2;
            count++;
            if(count == 2){
                length++;
                count = 0;
            }
        }
        else if(direction == 2){
            for(int i = 0; i < length; i++){
                if(rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols){
                    x[index] = rStart;
                    y[index] = cStart;
                    index++;
                }
                cStart--;
            }
            direction = 3;
            count++;
            if(count == 2){
                length++;
                count = 0;
            }
        }
        else if(direction == 3){
            for(int i = 0; i < length; i++){
                if(rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols){
                    x[index] = rStart;
                    y[index] = cStart;
                    index++;
                    

}

    