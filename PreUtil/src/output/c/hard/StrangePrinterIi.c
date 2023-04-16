/**https://leetcode.com/problems/strange-printer-ii/ */
//There is a strange printer with the following two special requirements:
//On each turn, the printer will print a solid rectangular pattern of a single color on the grid. This will cover up the existing colors in the rectangle.
//Once the printer has used a color for the above operation, the same color cannot be used again.
//You are given a m x n matrix targetGrid, where targetGrid[row][col] is the color in the position (row, col) of the grid.
//Return true if it is possible to print the matrix targetGrid, otherwise, return false.


bool isPrintable(int** targetGrid, int targetGridSize, int* targetGridColSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*targetGridSize);
    for(i=0;i<targetGridSize;i++){
        arr[i] = 0;
    }
    int* arr2 = (int*)malloc(sizeof(int)*targetGridSize);
    for(i=0;i<targetGridSize;i++){
        arr2[i] = 0;
    }
    int* arr3 = (int*)malloc(sizeof(int)*targetGridSize);
    for(i=0;i<targetGridSize;i++){
        arr3[i] = 0;
    }
    int* arr4 = (int*)malloc(sizeof(int)*targetGridSize);
    for(i=0;i<targetGridSize;i++){
        arr4[i] = 0;
    }
    int* arr5 = (int*)malloc(sizeof(int)*targetGridSize);
    for(i=0;i<targetGridSize;i++){
        arr5[i] = 0;
    }
    int* arr6 = (int*)malloc(sizeof(int)*targetGridSize);
    for(i=0;i<targetGridSize;i++){
        arr6[i] = 0;
    }
    int* arr7 = (int*)malloc(sizeof(int)*targetGridSize);
    for(i=0;i<targetGridSize;i++){
        arr7[i] = 0;
    }
    int* arr8 = (int*)malloc(sizeof(int)*targetGridSize);
    for(i=0;i<targetGridSize;i++){
        arr8[i] = 0;
    }
    int* arr9 = (int*)malloc(sizeof(int)*targetGridSize);
    for(i=0;i<targetGridSize;i++){
        arr9[i] = 0;
    }
    int* arr10 = (int*)malloc(sizeof(int)*targetGridSize);
    for(i=0;i<targetGridSize;i++){
        arr10[i] = 0;
    }
    int* arr11 = (int*)malloc(sizeof(int)*targetGridSize);
    for(i=0;i<targetGridSize;i++){
        arr11[i] = 0;
    }
    int* arr12 = (int*)malloc(sizeof(int)*targetGridSize);
    for(i=0;i<targetGridSize;i++){
        arr12[i] = 0;
    }
    int* arr13 = (int*)malloc(sizeof(int)*targetGrid

}

    