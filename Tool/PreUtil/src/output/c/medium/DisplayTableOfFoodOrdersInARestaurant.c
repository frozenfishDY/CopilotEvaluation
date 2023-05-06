/**https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/ */
//Given the array orders, which represents the orders that customers have done in a restaurant. More specifically orders[i]=[customerNamei,tableNumberi,foodItemi] where customerNamei is the name of the customer, tableNumberi is the table customer sit at, and foodItemi is the item customer orders.
//Return the restaurant's ��display table��. The ��display table�� is a table whose row entries denote how many of each food item each table ordered. The first column is the table number and the remaining columns correspond to each food item in alphabetical order. The first row should be a header whose first column is ��Table��, followed by the names of the food items. Note that the customer names are not part of the table. Additionally, the rows should be sorted in numerically increasing order.


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char *** displayTable(char *** orders, int ordersSize, int* ordersColSize, int* returnSize, int** returnColumnSizes){
    int i, j, k, l, m, n, count = 0, **result;
    int *row, *col;
    row = (int*)malloc(gridSize * sizeof(int));
    col = (int*)malloc(gridColSize[0] * sizeof(int));
    for(i = 0; i < gridSize; i++){
        row[i] = 0;
        for(j = 0; j < gridColSize[0]; j++){
            if(grid[i][j] == 1){
                row[i]++;
            }
        }
    }
    for(i = 0; i < gridColSize[0]; i++){
        col[i] = 0;
        for(j = 0; j < gridSize; j++){
            if(grid[j][i] == 1){
                col[i]++;
            }
        }
    }
    result = (int**)malloc(gridSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(gridSize * sizeof(int));
    for(i = 0; i < gridSize; i++){
        result[i] = (int*)malloc(gridColSize[0] * sizeof(int));
        (*returnColumnSizes)[i] = gridColSize[0];
        for(j = 0; j < gridColSize[0]; j++){
            result[i][j] = row[i] + col[j];
            if(grid[i][j] == 1){
                result[i][j] -= 2;
            }
        }
    }
    *returnSize = gridSize;
    return result;

}

    