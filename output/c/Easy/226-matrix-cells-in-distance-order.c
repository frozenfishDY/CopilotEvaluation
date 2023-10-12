/**https://leetcode.com/problems/matrix-cells-in-distance-order/ */
//You are given four integers row, cols, rCenter, and cCenter. There is a rows x cols matrix and you are on the cell with the coordinates (rCenter, cCenter).
//Return the coordinates of all cells in the matrix, sorted by their distance from (rCenter, cCenter) from the smallest distance to the largest distance. You may return the answer in any order that satisfies this condition.
//The distance between two cells (r1, c1) and (r2, c2) is |r1 - r2| + |c1 - c2|.
// 
//Example 1:
//Input: rows = 1, cols = 2, rCenter = 0, cCenter = 0
//Output: [[0,0],[0,1]]
//Explanation: The distances from (0, 0) to other cells are: [0,1]
//Example 2:
//Input: rows = 2, cols = 2, rCenter = 0, cCenter = 1
//Output: [[0,1],[0,0],[1,1],[1,0]]
//Explanation: The distances from (0, 1) to other cells are: [0,1,1,2]
//The answer [[0,1],[1,1],[0,0],[1,0]] would also be accepted as correct.
//Example 3:
//Input: rows = 2, cols = 3, rCenter = 1, cCenter = 2
//Output: [[1,2],[0,2],[1,1],[0,1],[1,0],[0,0]]
//Explanation: The distances from (1, 2) to other cells are: [0,1,1,2,2,3]
//There are other answers that would also be accepted as correct, such as [[1,2],[1,1],[0,2],[1,0],[0,1],[0,0]].
// 
//Constraints:
//	1 <= rows, cols <= 100
//	0 <= rCenter < rows
//	0 <= cCenter < cols
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** allCellsDistOrder(int rows, int cols, int rCenter, int cCenter, int* returnSize, int** returnColumnSizes){
int i,j;
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            returnNums[i*cols+j]=(int *)malloc(sizeof(int)*2);
            returnNums[i*cols+j][0]=i;
            returnNums[i*cols+j][1]=j;
        }
    }
    int *distance=(int *)malloc(sizeof(int)*rows*cols);
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            distance[i*cols+j]=abs(i-rCenter)+abs(j-cCenter);
        }
    }
    for(i=0;i<rows*cols-1;i++){
        for(j=0;j<rows*cols-i-1;j++){
            if(distance[j]>distance[j+1]){
                int temp=distance[j];
                distance[j]=distance[j+1];
                distance[j+1]=temp;
                int *temp1=returnNums[j];
                returnNums[j]=returnNums[j+1];
                returnNums[j+1]=temp1;
            }
        }
    }
    *returnSize=rows*cols;
    *returnColumnSizes=(int *)malloc(sizeof(int)*rows*cols);
    for(i=0;i<rows*cols;i++){
        (*returnColumnSizes)[i]=2;
    }
    return returnNums;

}