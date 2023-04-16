/**https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/ */
//Given a m x n binary matrix mat. In one step, you can choose one cell and flip it and all the four neighbors of it if they exist (Flip is changing 1 to 0 and 0 to 1). A pair of cells are called neighbors if they share one edge.
//Return the minimum number of steps required to convert mat to a zero matrix or -1 if you cannot.
//A binary matrix is a matrix with all cells equal to 0 or 1 only.
//A zero matrix is a matrix with all cells equal to 0.


int minFlips(int** mat, int matSize, int* matColSize){
    int i,j;
    int* arr = (int*)malloc(sizeof(int)*matSize);
    for(i=0;i<matSize;i++){
        arr[i] = 0;
    }
    int* arr2 = (int*)malloc(sizeof(int)*matSize);
    for(i=0;i<matSize;i++){
        arr2[i] = 0;
    }
    int* arr3 = (int*)malloc(sizeof(int)*matColSize[0]);
    for(i=0;i<matColSize[0];i++){
        arr3[i] = 0;
    }
    int* arr4 = (int*)malloc(sizeof(int)*matColSize[0]);
    for(i=0;i<matColSize[0];i++){
        arr4[i] = 0;
    }
    int ans = 0;
    int flag = 0;
    while(flag==0){
        flag = 1;
        for(i=0;i<matSize;i++){
            if(arr[i]<matColSize[0]){
                flag = 0;
                break;
            }
        }
        if(flag==1){
            break;
        }
        for(i=0;i<matSize;i++){
            if(arr[i]<matColSize[0]){
                arr[i]++;
                arr2[i]++;
                break;
            }
        }
        for(i=0;i<matColSize[0];i++){
            if(arr3[i]<matSize){
                arr3[i]++;
                arr4[i]++;
                break;
            }
        }
        ans++;
    }
    return ans;


}

    