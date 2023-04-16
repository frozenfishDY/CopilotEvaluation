/**https://leetcode.com/problems/maximal-rectangle/ */
//Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.


int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize){
    if(matrixSize == 0) return 0;
    int max = 0;
    int *height = (int*)malloc(sizeof(int) * (*matrixColSize));
    memset(height, 0, sizeof(int) * (*matrixColSize));
    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < *matrixColSize; j++){
            if(matrix[i][j] == '1'){
                height[j]++;
            }else{
                height[j] = 0;
            }
        }
        int curMax = largestRectangleArea(height, *matrixColSize);
        if(curMax > max) max = curMax;
    }
    return max;
   
}

    